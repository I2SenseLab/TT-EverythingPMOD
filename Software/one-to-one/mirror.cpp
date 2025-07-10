#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/watchdog.h"
#include "mirror_single.pio.h"
#include <array>
#include <cstdio>

static constexpr uint8_t male_pins[]   = {  2,  1, 32,  3, 30, 31, 28, 29 };
static constexpr uint8_t female_pins[] = { 17, 16, 19, 18, 25, 20, 27, 26 };
static constexpr size_t  PAIRS = std::size(male_pins);

static void print_snapshot()
{
    printf("Snapshot:");
    for (size_t i = 0; i < PAIRS; ++i)
        printf(" %u=%d", male_pins[i], gpio_get(male_pins[i]));
    puts("");
}

static void mirror_single_program_init(PIO pio, uint sm, uint offset,
                                       uint in_pin, uint out_pin)
{
    pio_sm_config c = mirror_single_program_get_default_config(offset);
    sm_config_set_in_pins (&c, in_pin);
    sm_config_set_out_pins(&c, out_pin, 1);
    sm_config_set_in_shift (&c, true,  false, 32);   // shift right
    sm_config_set_out_shift(&c, true,  false, 32);

    pio_sm_set_consecutive_pindirs(pio, sm, in_pin,  1, false);
    pio_sm_set_consecutive_pindirs(pio, sm, out_pin, 1, true);
    pio_sm_init(pio, sm, offset, &c);
    pio_sm_set_enabled(pio, sm, true);
}

int main()
{
    stdio_init_all();
    while (!stdio_usb_connected()) sleep_ms(10);
    printf("PIO single-bit mirror – %zu pairs\n", PAIRS);

    watchdog_enable(2'000'000, true);

    for (size_t i = 0; i < PAIRS; ++i) {
        PIO pio = (i < 4) ? pio0 : pio1;   // which block will drive this pair
        pio_gpio_init(pio, male_pins[i]);  // FUNCSEL = PIO0 *or* PIO1  ← ★
        pio_gpio_init(pio, female_pins[i]);
    }

    uint offset0 = pio_add_program(pio0, &mirror_single_program);
    uint offset1 = pio_add_program(pio1, &mirror_single_program);

    for (size_t i = 0; i < PAIRS; ++i) {
        PIO  pio = (i < 4) ? pio0 : pio1;
        uint sm  = i & 3;
        uint off = (i < 4) ? offset0 : offset1;
        mirror_single_program_init(pio, sm, off, male_pins[i], female_pins[i]);
    }

    uint64_t next_print = time_us_64() + 500'000;
    while (true) {
        if (time_us_64() >= next_print) {
            print_snapshot();
            next_print += 500'000;
        }
        watchdog_update();
    }
}
