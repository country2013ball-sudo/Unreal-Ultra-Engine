# ESP32 Wi-Fi repeater

Before compiling, replace `STA_SSID` and `STA_PASS` in `repeater.ino` with
your 2.4 GHz Wi-Fi credentials. Choose a unique `AP_PASS` of at least eight
characters. Do not commit real Wi-Fi credentials; this repository is public.

Install the ESP32 Arduino core and compile for a standard ESP32 board:

```sh
arduino-cli core update-index \
  --additional-urls https://espressif.github.io/arduino-esp32/package_esp32_index.json
arduino-cli core install esp32:esp32 \
  --additional-urls https://espressif.github.io/arduino-esp32/package_esp32_index.json
arduino-cli compile --fqbn esp32:esp32:esp32 repeater
```

The committed `repeater.ino.bin` is built with placeholder credentials and
must be recompiled after configuring your Wi-Fi details. It is the application
image; flashing it separately requires an ESP32 bootloader and partition table
already installed on the board.
