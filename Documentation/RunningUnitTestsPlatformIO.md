# Running Unit Tests with PlatformIO

To ensure your unit tests and source code run correctly, follow these steps:

### Configuration

**1. Add the Native Environment for Unit Testing:** In your `platformio.ini` file, include a `[env: native]` section for running Unity tests.:

```ini
[env:native]
platform = native
test_framework = unity
```

**2. Ensure Your Hardware Environment is Configured:** Include  the relevant hardware environment configuration, such as `uno-r4_wifi`, in your platformio.ini` file.

```ini
[env:uno_r4_wifi] 
platform = renesas-ra 
board = uno_r4_wifi 
framework = arduino 
lib_deps = 
    adafruit/Adafruit Motor Shield V2 Library@^1.1.3 
    SPI adafruit/DHT sensor library@^1.4.6 
    adafruit/Adafruit Unified Sensor@^1.1.14 
    bblanchon/ArduinoJson@^7.1.0 
    TFT_eSPI 
    openagriculturefoundation/rosserial_arduino@0.0.0-alpha+sha.1834b766b0 
    throwtheswitch/Unity@^2.6.0
```

### Running the Tests

**1. Run Unit Tests:** To run your unit tests with the native environment, use the following command:

```sh
pio test -e native
```

**2. Compile and Upload Source Code:** To compile and upload your source code for the specified hardware environment, use:

```sh
pio run -e uno_r4_wifi
```

Following these instructions will help ensure your unit tests and source code are handled in the correct environments.