# zephyr-esp32s3-hello-world
Zephyr RTOS Hello world application for ESP32-S3

This sample app demonstrates a Zephyr + ESP32-S3 "Hello world" example with basic Zephyr RTOS features like logging and shell.
Tested on the following boards:

- `esp32s3_devkitc/esp32s3/procpu` (default board)
- `esp32s3_zero/esp32s3/procpu`

## Getting Started

To try out this example app:

1. Set up the Zephyr prerequisites: https://docs.zephyrproject.org/latest/develop/getting_started/index.html
2. Create a zephyr workspace and set it up with this project:

    ```bash
    mkdir zephyr-workspace
    cd zephyr-workspace
    west init -m https://github.com/yk-ee/zephyr-esp32s3-hello-world
    west update
    ```

3. Build the example app:

    ```bash
    west build -b esp32s3_zero/esp32s3/procpu zephyr-esp32s3-hello-world
    ```

    or

    ```bash
    west build -p always -b esp32s3_devkitc/esp32s3/procpu zephyr-esp32s3-hello-world -- -DDTC_OVERLAY_FILE="esp32s3_zero.overlay" 
    ```

4. Flash the example app:

    ```bash
    west flash

    -- west flash: rebuilding
    ninja: no work to do.
    -- west flash: using runner esp32
    -- runners.esp32: reset after flashing requested
    -- runners.esp32: Flashing esp32 chip on None (921600bps)
    esptool v5.2.0
    Connected to ESP32-S3 on COM12:
    Chip type:          ESP32-S3 (QFN56) (revision v0.2)
    Features:           Wi-Fi, BT 5 (LE), Dual Core + LP Core, 240MHz, Embedded Flash 4MB (XMC), Embedded PSRAM 2MB (AP_3v3)
    Crystal frequency:  40MHz
    USB mode:           USB-Serial/JTAG
    MAC:                e0:72:a1:e7:d8:54

    Stub flasher running.
    Changing baud rate to 921600...
    Changed.

    Configuring flash size...
    Flash will be erased from 0x00000000 to 0x00023fff...
    Wrote 144884 bytes at 0x00000000 in 1.0 seconds (1123.5 kbit/s).
    Hash of data verified.

    Hard resetting via RTS pin...
    ```

5. Open a serial console and interact with the sample app shell.
    For example using `west espressif monitor`:

    ```bash
    # select the correct serial port based on your setup
    west espressif monitor -p COM12

    Build directory: D:\WORK\Ciklum\zephyrproject\build
    --- WARNING: GDB cannot open serial ports accessed as COMx
    --- Using \\.\COM12 instead...
    --- idf_monitor on \\.\COM12 115200 ---
    --- Quit: Ctrl+] | Menu: Ctrl+T | Help: Ctrl+T followed by Ctrl+H ---
    [0m<inf> hello_world: Hello WorlESP-ROM:esp32s3-20210327
    Build:Mar 27 2021
    rst:0x15 (USB_UART_CHIP_RESET),boot:0x9 (SPI_FAST_FLASH_BOOT)
    Saved PC:0x40379863
    SPIWP:0xee
    mode:DIO, clock div:1
    load:0x3fc8f170,len:0x26f4
    load:0x40374000,len:0xb154
    SHA-256 comparison failed:
    Calculated: 4733751ac5a0cff60ea26290b978562428b136b32c6846881f794307a79b3b5e
    Expected: 0000000070270000000000000000000000000000000000000000000000000000
    Attempting to boot anyway...
    entry 0x40379fe0
    I (59) soc_init: ESP Simple boot
    I (59) soc_init: compile time Mar 31 2026 19:54:20
    W (59) soc_init: Unicore bootloader
    I (59) soc_init: chip revision: v0.2
    I (61) flash_init: Boot SPI Speed : 80MHz
    I (65) flash_init: SPI Mode       : DIO
    I (69) flash_init: SPI Flash Size : 4MB
    I (72) boot: DRAM       : lma=00000020h vma=3fc8f170h size=026f4h (  9972)
    I (78) boot: IRAM       : lma=0000271ch vma=40374000h size=0b154h ( 45396)
    I (84) boot: IROM       : lma=00010000h vma=42000000h size=0b8a4h ( 47268)
    I (90) boot: DROM       : lma=00020000h vma=3c010000h size=035f4h ( 13812)
    I (97) boot: libc heap size 332 kB.
    I (100) spi_flash: detected chip: generic
    I (103) spi_flash: flash io: dio
    uart:~$ *** Booting Zephyr OS build v4.3.0-7513-gba5148006b29 ***
    uart:~$ [00:00:00.131,000] <inf> hello_world: Hello World! esp32s3_devkitc/esp32s3/procpu
    uart:~$ [00:00:00.131,000] <inf> hello_world: Found LED strip device ws2812@0
    uart:~$ uart:~$ [00:00:00.132,000] <inf> hello_world: Tick 0
    uart:~$ uart:~$ [00:00:01.133,000] <inf> hello_world: Tick 1
    uart:~$ uart:~$ [00:00:02.134,000] <inf> hello_world: Tick 2
    uart:~$ uart:~$ [00:00:03.135,000] <inf> hello_world: Tick 3
    uart:~$ uart:~$ [00:00:04.136,000] <inf> hello_world: Tick 4
    uart:~$ uart:~$ [00:00:05.137,000] <inf> hello_world: Tick 5
    uart:~$ uart:~$ [00:00:06.138,000] <inf> hello_world: Tick 6
    uart:~$ uart:~$

    ```

   Or using PySerial:

    ```bash
    # select the correct serial port based on your setup
    pyserial-miniterm --raw COM12 115200

    --- Miniterm on COM12  115200,8,N,1 ---
    --- Quit: Ctrl+] | Menu: Ctrl+T | Help: Ctrl+T followed by Ctrl+H ---
    /esp32s3/procpu
    [00:00:00.133,000] <inf> hello_world: Found LED strip device ws2812@0
    [00:00:00.134,000] <inf> hello_world: Tick 0
    [00:00:01.136,000] <inf> hello_world: Tick 1
    [00:00:02.137,000] <inf> hello_world: Tick 2
    [00:00:03.138,000] <inf> hello_world: Tick 3
    [00:00:04.139,000] <inf> hello_world: Tick 4
    [00:00:05.140,000] <inf> hello_world: Tick 5
    [00:00:06.141,000] <inf> hello_world: Tick 6
    [00:00:07.142,000] <inf> hello_world: Tick 7
    [00:00:08.143,000] <inf> hello_world: Tick 8
    uart:~$ 
    --- exit ---

    ```

