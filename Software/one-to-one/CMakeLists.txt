cmake_minimum_required(VERSION 3.13)

# Tell CMake that its first "try-compile" should build a static library,
# NOT a host executable (or it will fail on bare-metal cross builds).
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

# --------------------------------------------------------------------
# ► Board / platform
#   Either one of these is enough – pick the variant you prefer
# --------------------------------------------------------------------
set(PICO_BOARD pimoroni_pico_plus2_rp2350)   # ← board file ships with SDK
# set(PICO_PLATFORM rp2350)                  # …or force the platform by hand

# Import the SDK (it auto-detects RP2350 when the board sets it)
include(pico_sdk_import.cmake)
project(header_mirror C CXX ASM)
pico_sdk_init()

add_executable(header_mirror
    mirror.cpp          # ← the source below
)

set(PIO_FILES
    ${CMAKE_CURRENT_LIST_DIR}/mirror_single.pio
)

foreach(pio_file ${PIO_FILES})
    pico_generate_pio_header(header_mirror            # target that will use it
        ${pio_file}
        OUTPUT_DIR ${CMAKE_CURRENT_LIST_DIR})         # keep headers beside code
    target_sources(header_mirror PRIVATE ${pio_file}) # re-build on .pio change
endforeach()

# USB printf on /dev/ttyACM0, no UART
pico_enable_stdio_usb(header_mirror 1)
pico_enable_stdio_uart(header_mirror 0)

target_compile_features(header_mirror PUBLIC cxx_std_17)
target_link_libraries(header_mirror
    pico_stdlib
    hardware_pio
    hardware_dma
    hardware_watchdog)
pico_add_extra_outputs(header_mirror)
