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
    printf("RP2350 header-mirror DEBUG – %zu channels\n", PIN_CT);

    // --- watchdog: reboot if main loop stalls for >2 s ---------------------
    constexpr uint32_t WDT_PERIOD_US = 2 * 1'000'000;   // 2 s
    watchdog_enable(WDT_PERIOD_US, /*pause_on_debug=*/true);
    // ----------------------------------------------------------------------

    // Configure directions
    for (size_t i = 0; i < PIN_CT; ++i) {
        gpio_init(male_pins[i]);
        gpio_set_dir(male_pins[i], GPIO_IN);
        gpio_init(female_pins[i]);
        gpio_set_dir(female_pins[i], GPIO_OUT);
    }

    std::array<uint8_t, PIN_CT> prev{};                 // last seen states
    uint64_t next_snapshot = time_us_64() + 500'000;    // 500 ms

    while (true) {
        // mirror + per-pin change detection
        for (size_t i = 0; i < PIN_CT; ++i) {
            uint8_t val = gpio_get(male_pins[i]);
            gpio_put(female_pins[i], val);
            if (val != prev[i]) {
                printf("Change: GP%-2u -> GP%-2u = %d\n",
                       male_pins[i], female_pins[i], val);
                prev[i] = val;
            }
        }

        // periodic full dump
        if (time_us_64() >= next_snapshot) {
            print_snapshot();
            next_snapshot += 500'000;                  // schedule next dump
        }

        watchdog_update();                             // pet the watchdog
    }
}
