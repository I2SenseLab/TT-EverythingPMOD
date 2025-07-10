// mirror_debug.cpp – mirrors male-header signals to female headers
//                    and prints changes / snapshots (RP2350).
//                    Now includes a 2-second watchdog timer.

#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/watchdog.h"
#include "hardware/clocks.h"
#include "mirror_single.pio.h"
#include <array>
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

void mirror_single_program_init(PIO pio, uint sm, uint offset, uint input_pin, uint output_pin) {
    pio_sm_config c = mirror_single_program_get_default_config(offset);
    sm_config_set_in_pins(&c, input_pin);
    sm_config_set_out_pins(&c, output_pin, 1);
    sm_config_set_in_shift(&c, false, false, 32);  // no shifting
    sm_config_set_out_shift(&c, false, false, 32); // no shifting
    pio_sm_set_consecutive_pindirs(pio, sm, input_pin, 1, false);
    pio_sm_set_consecutive_pindirs(pio, sm, output_pin, 1, true);
    pio_sm_init(pio, sm, offset, &c);
    pio_sm_set_enabled(pio, sm, true);
}

int main()
{
    stdio_init_all();
    while (!stdio_usb_connected()) sleep_ms(10);
    printf("RP2350 PIO GPIO mirror – %zu channels\n", PIN_CT);

    constexpr uint32_t WDT_PERIOD_US = 2 * 1'000'000;
    watchdog_enable(WDT_PERIOD_US, true);

    // These are your OT0-7 and OOT0-7 pins
    uint8_t inputs[]  = {2, 1, 32, 3, 30, 31, 28, 29};
    uint8_t outputs[] = {17, 16, 19, 18, 25, 20, 27, 26};

    PIO pio = pio0;
    uint offset = pio_add_program(pio, &mirror_single_program);

    PIO pios[] = {pio0, pio0, pio0, pio0, pio1, pio1, pio1, pio1};
    uint offset0 = pio_add_program(pio0, &mirror_single_program);
    uint offset1 = pio_add_program(pio1, &mirror_single_program);

    for (int i = 0; i < 8; ++i) {
        PIO which = pios[i];
        uint sm = i % 4;
        uint offset = (which == pio0) ? offset0 : offset1;
        mirror_single_program_init(which, sm, offset, inputs[i], outputs[i]);
    }



    uint64_t next_snapshot = time_us_64() + 500'000;
    while (true) {
        if (time_us_64() >= next_snapshot) {
            print_snapshot();
            next_snapshot += 500'000;
        }
        watchdog_update();
    }
}
