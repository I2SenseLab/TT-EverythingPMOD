// mirror_debug.cpp – mirrors male-header signals to female headers
//                    and prints changes / snapshots (RP2350).
//                    Now includes a 2-second watchdog timer.

#include "pico/stdlib.h"
#include "hardware/timer.h"       // time_us_64()
#include "hardware/watchdog.h"    // watchdog_enable(), watchdog_update()
#include <array>
#include <cstdint>
#include <cstdio>

// ----- pin tables (male → female) -----
static constexpr uint8_t male_pins[] = {
     2,  1, 32,  3, 30, 31, 28, 29,   // OT0-7
    39, 40, 38, 37, 35, 36, 33, 34,   // IOT0-7
    47, 46, 45, 44, 43, 42, 41,  0    // IT0-7
};
static constexpr uint8_t female_pins[] = {
    17, 16, 19, 18, 25, 20, 27, 26,   // OOT0-7
     8,  9, 10, 11, 13, 12, 15, 14,   // OIOT0-7
    24, 23, 22, 21,  4,  5,  6,  7    // OIT0-7
};
static_assert(std::size(male_pins) == std::size(female_pins));
constexpr size_t PIN_CT = std::size(male_pins);

// ----- helpers --------------------------------------------------------------
static void print_snapshot()
{
    printf("Snapshot:");
    for (size_t i = 0; i < PIN_CT; ++i)
        printf(" %u=%d", male_pins[i], gpio_get(male_pins[i]));
    puts("");
}
// ---------------------------------------------------------------------------

int main()
{
    stdio_init_all();
    while (!stdio_usb_connected()) sleep_ms(10);
    printf("RP2350 PIO GPIO mirror – %zu channels\n", PIN_CT);

    constexpr uint32_t WDT_PERIOD_US = 2 * 1'000'000;
    watchdog_enable(WDT_PERIOD_US, true);

    PIO pio = pio0;
    uint sm_in = 0, sm_out = 1;

    // Set up input SM (male header)
    uint offset_in = pio_add_program(pio, &mirror_in_program);
    mirror_in_program_init(pio, sm_in, offset_in, male_pins[0]);

    // Set up output SM (female header)
    uint offset_out = pio_add_program(pio, &mirror_out_program);
    mirror_out_program_init(pio, sm_out, offset_out, female_pins[0]);

    // Start both state machines
    pio_sm_set_enabled(pio, sm_in, true);
    pio_sm_set_enabled(pio, sm_out, true);

    uint64_t next_snapshot = time_us_64() + 500'000;
    while (true) {
        if (time_us_64() >= next_snapshot) {
            print_snapshot();
            next_snapshot += 500'000;
        }
        watchdog_update();
    }
}
