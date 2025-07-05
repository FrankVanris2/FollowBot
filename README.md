# FollowBot

[Watch the FollowBot Prototype 1 in Action!](https://www.youtube.com/shorts/VBmE77GVLnA)

## Table of Contents
 - [Introduction](#introduction)
 - [About the Team](#about-the-team)
 - [Features](#features)
 - [Design Details](#design-details)
 - [Installation](#installation)
 - [Other Resources](#other-resources)
 - [Contributing](#contributing)
 - [License](#license)

## Introduction
Followbot is a companion robot that follows you around. The goal for this project is to build a low-cost robot that can carry you belongings for you. Currently, FollowBot is useful within school/city settings. Future endeavors include developing the capability for FollowBot to traverse uneven terrain such as dirt of gravel

## About the Team
We are a dedicated group of students committed to making robotics accessible and affordable for everyone. Our goal is to develop innovative robotic solutions that serve those in need while prioritizing safety and minimizing risks to humans. Through ethical engineering and thoughtful design, we strive to advance robotics in a way that benefits society and ensures responsible technological progress.
### Team at the Park
![TeamAtThePark_1](https://github.com/user-attachments/assets/76b7fb17-bf65-4df1-980f-1cf6344f8753)
### Close-up with the Robot
![TeamCloseToRobot](https://github.com/user-attachments/assets/842f2095-bb8a-443b-8343-8484e76f58ff)
### Buiding the Future
![image](https://github.com/user-attachments/assets/47134119-a80a-460e-81ce-f403b045a9ef)
### Probem-Solving in Action
![image](https://github.com/user-attachments/assets/a573d56d-7a8c-4139-aef1-bceac1660649)


## Features
- Carry up to 50 lbs
- Mapping capabilities to traverse from one point to another
- Following mechanics
- Companion app and website to monitor and control robot remotely

## Design Details
The construction of the FollowBot presents a significant challenge, given the intricate engineering required to create a device capable of carrying and autonomously following a user. The hardware components and their assembly will demand meticulous attention and precision.

On the hardware side we are utilizing the Arduino Uno Rev4 in order to send and do important tasks for the user. We will be developing a webpage and an app with valuable information for the user to use when needed. Mapping capabilities and path-finding algorithms will be applied to the FollowBot in order to avoid obstacles while following a designated path to a specific location. Computer vision techniques will be used to allow the FollowBot to follow the user if needed in order for it to carry their belongings. Sensors such as LiDAR, RGB etc. will come with software that will allow us to really improve the machine learning models that we will apply.

In terms of project success, our primary focus will be on systematic organization and incremental prototyping. We plan to develop a prototype during the first quarter and progressively refine it. Our goal is to deliver a practical and beneficial product for any consumer seeking a FollowBot to carry their belongings or allow the FollowBot to go to designated places.

### High Level Design Architecture
![image](/Images/High_Level_Design_Architecture1.png)

# Installation

## Installation Steps
Before you clone your repo you will need to first download vscode. The reason being is that when developing on the Robotics side There is a nice extension that is not found in any other IDE's. To make your life
easier and for you to not try and configure PlatformIO on another IDE with hassle. I would absolutely advise you to download VSCode.




* In VSCode click the extensions icon.

![image](/Images/readMe_images/Extensions.png)

* Look up **PlatformIO IDE**

![image](/Images/readMe_images/PlatformIO.png)

* Install it

![image](/Images/readMe_images/Install.png)

After VSCode with the PlatformIO extension has been installed we can now git clone the repo.

## Other Resources

## Website development
The website development has been migrated to it's very own repository, same will occur for the Native React side. If you want to learn more about the website development for this project, please check out the link 
below. Many changes within this repository will continue to occur throughout our production, along with our refactoring of our project:

[Website Development for Followbot](https://github.com/FrankVanris2/FollowBotWebsite)

## Robotic-end
The robotic side of this project will involve the integration and communication between an Arduino board and a Raspberry Pi running ROS2. The Arduino board will facilitate motor and sensory communication by allowing messages to be sent back and forth, enabling various applications supported by the Raspberry Pi with ROS2. Utilizing ROS2, we can develop learning models and employ computer vision technologies to enhance the accuracy of our mapping, following mechanics, voice recognition, path-finding, and user recognition. The required steps in order to begin development on the robotic side of this project is found in the link below. It will direct you to another Repository that will connect back as always to our master repository:

[ROS2 Development for FollowBot](https://github.com/FrankVanris2/ROS2_FollowBot)

**For Arduino Development**:
* If you have not already please download VSCode with the PlatformIO extension in order for you to develop on the Robotic side.
* Within the PlatformIO homepage there are 4 side buttons that you will be allowed to click on. Please click on the `Open Project` Button

![image](/Images/readMe_images/OpenProj.png)

* When you do so please go where you placed your repo, and you will need to open this folder: `FollowBot->FollowBot`

![image](/Images/readMe_images/DirProject.png)

* After you do so you will see all the files that we have made for the development of FollowBot.
* To run it you will need to press the blue checkmark icon at the bottom of the screen

![image](/Images/readMe_images/Compile.png)

* To push and build the code on the Arduino board or any Microcontroller that is applicable press the arrow icon at the bottom of the screen

![image](/Images/readMe_images/push_build.png)

* When you are programming on the device, sometimes you will want to print something to the Serial port. Click the plug icon to open the Serial Monitor.

![image](/Images/readMe_images/SerialMonitor.png)

* When you need to input PlatformIO specific commands, you will need to open the IO terminal. The icon is a small cmd screen.

![image](/Images/readMe_images/IOMonitor.png)

## Other Documentation:

Within the Repo there is a directory called `Documentation` Most of the documentation is around the requirements and the design of our Project. But there is specific docs that I recommend you guys reading up on. Please read the `RunningUnitTestsPlatformIO` documentation

- [Running Unit Test PlatformIO](https://github.com/FrankVanris2/FollowBot/blob/main/Documentation/RunningUnitTestsPlatformIO.md)
  
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
