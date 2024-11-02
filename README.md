# FollowBot


This robot will consist of different phases:

1. following mechanics, sensor intel. (Stage 1)
2. carrying mechanics, power efficiency. (Stage 2)
3. pathfinding mechanics, power efficiency. (Stage 3)
4. cost efficiency, balancing efficiency. (Stage 4)

## Table of Contents
 - [Introduction](#introduction)
 - [Features](#features)
 - [Design Details](#design-details)
 - [Installation](#installation)
 - [Configuration](#configuration)
 - [Usage](#usage)
 - [Contributing](#contributing)
 - [License](#license)

## Introduction
Followbot is a companion robot that follows you around. The goal for this project is to build a low cost robot that can carry you belongings for you. Currently Followbot is useful within school/city settings. Future endeavors include developing the capability for Followbot to traverse uneven terrain such as dirt of gravel

## Features
List the key features of your project. Use bullet points for clarity.
- Follow the user 
- Carry up to 50 lbs
- Companion app and website to monitor and control robot remotely

## Design Details
The construction of the Followbot presents a significant challenge, given the intricate engineering required to create a device capable of carrying and autonomously following a user. The hardware components and their assembly will demand meticulous attention and precision.

On the software side we are utilizing the Arduino Uno Rev4 in order to send and do important tasks for the user. We will be developing a webpage and a app with valuabe information for the user to use when needed. Mapping capabilities and path-finding algorithms will be applied to the Followbot in order to avoid obstacles while following a designated path to a specific location. Computer vision techniques will be used to allow the Followbot to follow the user if needed in order for it to carry their belongings. Sensors such as Lidar, RGB etc. will come with software that will allow us to really improve the machine learning models that we will apply.

In terms of project success, our primary focus will be on systematic organization and incremental prototyping. We plan to develop a prototype during the first quarter and progressively refine it. Our goal is to deliver a practical and beneficial product for any consumer seeking a Followbot to carry their belongings or allow the Followbot to go to designated places.

### Example Code:
`python code`
# Code snippet or example to showcase design principles

Installation
Provide instructions on how to install your project. Include any dependencies or
prerequisites.

# Installation steps
$ git clone https://github.com/FrankVanris2/FollowBot.git
$ cd your-repo
$ npm install # or any other relevant command

Configuration
Explain how users can configure your project. If applicable, include details about
configuration files.

Example Configuration:
# Configuration file example
key: value

Usage
Provide examples and instructions on how users can use your project. Include code
snippets or command-line examples.
Example Usage:
# Example command or usage

Contributing
We are a small team of college students, any help is appreciated! 

License
Copyright <2024> <Trong Duong Joeseph Hoang Igor Janotti Frank Vanris>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files ("Followbot") to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
