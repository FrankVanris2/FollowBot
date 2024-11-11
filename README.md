# FollowBot


This robot will consist of different phases:

1. Following mechanics, sensor intel. (Stage 1)
2. Carrying mechanics, power efficiency. (Stage 2)
3. Pathfinding mechanics, power efficiency. (Stage 3)
4. Cost efficiency, balancing efficiency. (Stage 4)

## Table of Contents
 - [Introduction](#introduction)
 - [Features](#features)
 - [Design Details](#design-details)
 - [Installation](#installation)
 - [Configuration](#configuration)
 - [Contributing](#contributing)
 - [License](#license)

## Introduction
Followbot is a companion robot that follows you around. The goal for this project is to build a low cost robot that can carry you belongings for you. Currently Followbot is useful within school/city settings. Future endeavors include developing the capability for Followbot to traverse uneven terrain such as dirt of gravel

## Features
- Carry up to 50 lbs
- Companion app and website to monitor and control robot remotely

## Design Details
The construction of the Followbot presents a significant challenge, given the intricate engineering required to create a device capable of carrying and autonomously following a user. The hardware components and their assembly will demand meticulous attention and precision.

On the software side we are utilizing the Arduino Uno Rev4 in order to send and do important tasks for the user. We will be developing a webpage and a app with valuabe information for the user to use when needed. Mapping capabilities and path-finding algorithms will be applied to the Followbot in order to avoid obstacles while following a designated path to a specific location. Computer vision techniques will be used to allow the Followbot to follow the user if needed in order for it to carry their belongings. Sensors such as LiDAR, RGB etc. will come with software that will allow us to really improve the machine learning models that we will apply.

In terms of project success, our primary focus will be on systematic organization and incremental prototyping. We plan to develop a prototype during the first quarter and progressively refine it. Our goal is to deliver a practical and beneficial product for any consumer seeking a Followbot to carry their belongings or allow the Followbot to go to designated places.



Installing npm
```sh
npm i -g npm
npm install @mui/icons-material


# Build
npm run build

# Run

npm run start

# In the browser use url: http://xx.xx.xx.xx:5000
# Where xx.xx.xx.xx is shown in the server command window
```
#### Develop

Two cmd windows:

- First window (for javascript browser development):

```sh 
npm run watch
```

- Second window (for python server development):

```sh
npm run startdebug
```

In the browser use url: http://localhost:3000/

When finished adding changes please run clean:
```sh
npm run clean
```

 
### Running Unit Tests with PlatformIO

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


## Contributing
We are a small team of college students, any help is appreciated! You can clone the repository on GitHub and submit a pull request.
```sh
git clone https://github.com/FrankVanris2/FollowBot.git
```

## License
MIT License 

Copyright (c) 2024 Trong Duong, Joeseph Hoang, Igor Janotti, Frank Vanris

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files ("Followbot") to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
