<h1>Software/Hardware Design Document <br>
for <br>
Follow Bot</h1>

<h2> Version 1.0 approved<br>
<br>
Prepared by Frank Vanris, Igor Janotti<br><br>
Bellevue College<br><br>
7/10/2024<br><br></h2>

<h2>
1. Introduction <br> <br>
</h2>

<h3> 1.1 Purpose<br> </h3>
This software/hardware design document describes the architecture and system design of the Follow Bot robot as well as it's software, and how reliable and usable it will be for the user.<br><br>

<h3> 1.2 Scope <br> </h3>
The Goal for this robot is for the user to be able to use it wherever they go while storing their belongings in a safe and reliable place.<br><br>

<h3> 1.3 Overview <br></h3>
The main gist of this document is to explain and express how the design for this software/hardware will be handled and to explain how the user will be able to use our software and hardware efficiently and reliably.<br><br>

<h3> 1.4 Reference Material <br> </h3>
Here are the given sources that were used to rely information for this document:<br>

* https://onlinelibrary.wiley.com/doi/10.1155/2022/8274455
* https://docs.ros.org/en/foxy/index.html
* https://docs.wpilib.org/en/stable/docs/hardware/hardware-basics/index.html
* https://docs.wpilib.org/en/stable/docs/software/hardware-apis/motors/index.html
* https://docs.arduino.cc/
* https://wiki.freecad.org/
* https://www.klipper3d.org/
* https://legacy.reactjs.org/docs/getting-started.html
* https://www.nature.com/articles/s41598-023-33837-1
* https://tinyurl.com/yc5y6r9x (AWS)
* https://scikit-learn.org/stable/ 

<h4> Books: </h4>

* Practical Robotics in C++ By *Lloyd Brombach*
* An Introduction to AI Robotics By *Robin Murphy*
* Introduction to Robotics: Mechanics and Control By *John J Craig*
* A Concise introduction to Robot Programming with ROS2 By *Francisco Rico Manrique*

<h3> 1.5 Definitions and Acronyms <br> </h3>

* ROS: Robotics Operating System

* DC: Direct Current

* AC: Alternating Current

* Nodes: A participant in the ROS2 Graph, which uses a client library to communicate with other nodes.

* Topics: one of the three main ways that nodes can communicate with one another is via topics.

* Foxy: A version of the ROS2, there are other versions such as Jammy, Jazzy, Humble, Iron, and others.

* Motor Drivers: control chips that are meant to run current through a number of motors.

* Motor Controller: Any Microcontroller that controls motors in general, such as Arduinos, ESP32's and AdaFruit controllers.

* AP: Access Points

* WiFi Triangulation: A way for wifi routers, to triangulate a position.

* Arduino: a microcontroller

* ESP32: a microcontroller
<br>

## 2. System Overview

### App

#### Goal
The goal of the app is to control and have the robot follow the user autonomously while avoiding obstacles. The mobile app should also send live data on battery life, location, weight, and temperature.

#### Requirements

- **Light and Dark Mode**  
  The app should support both light and dark themes for user interface customization.

- **Robot Follow Feature**  
  The app will allow the robot to follow the phone, potentially using GPS or similar technology.

- **Robot Status Updates**  
  The app will update the robot's status every 30 seconds. The update will include:
  - Power level
  - Temperature
  - Weight of the robot
  - Information on any movement issues related to the weight

- **Distance Notifications**  
  The app will send notifications if the robot gets too far away from the phone.

- **Controller Functionality**  
  The app will act as a controller for the robots, using the touchscreen. 
  - Optionally, a game controller can be used if the touchscreen is not functional.

### Website

#### Goal
The goal of the website is to inform the users about what the robot does and send queries back to the owners of the website.

#### Requirements

- **Technologies**  
  The website will be written in JavaScript, HTML, and CSS.

- **Light and Dark Mode**  
  The website will support both light and dark modes for user interface customization.

- **Pages**  
  The website will contain four main pages:
  
  1. **Robot**  
     - This page will include text and an embedded video from YouTube.
  
  2. **App**  
     - This page will include text, an embedded video from YouTube, and a link to download the app.
  
  3. **About Us**  
     - This page will include text and links to our work and social media profiles.
  
  4. **Feedback**  
     - This page will include a text area where users can provide feedback.
     - A private section for owners will be available to download and delete messages.
     - Consider using a database to store and manage feedback submissions.

### Robotic Overview

#### Goal
The goal of the robot is for it to carry up to 50 lbs of your belongings and follow you while maneuvering through different obstacles along the way.

We will be experimenting with different kinds of motors, sensors, and modules to determine the best way for the robot to follow the user while maneuvering through obstacles quickly. We also aim to create a device that keeps costs to a minimum.

#### Weight Carrying and Following
The user will be able to place various belongings within the device, such as food, electronics, books, sports items, clothing, and more. The robot will track the user based on the phone's position and its current position via the GPS module installed within the robot.

#### Sensors
The robot will use multiple sensors to avoid and move away from obstacles. Forms of avoidance will include lidar sensors, computer vision, and echo locative tracking. The choice of sensors will be decided as a team based on their accuracy in avoiding obstacles quickly.

#### Hardware
When designing the hardware, cost will be a key consideration. Initially, hardware will be created through 3D printing and simple woodworking. Designing the hardware will be done using various design applications such as FreeCAD, Fusion360, and Blender. For electronic hardware development and wiring, the final design will be created via a PCB manufacturer.

#### Real-Time Updates
Through the mobile app, the robot will provide real-time updates on battery life, distance between the user and the robot, the temperature within the robot's capsule, and the weight distribution on the robot. Notifications will be sent to the user if the battery life is low or if the robot needs help or repair.

#### Machine Learning Models
We aim to add machine learning to the robot. The capability for the robot to learn from its mistakes through reinforcement learning could be beneficial in improving performance while conserving battery life. Our goal is to maximize battery life so the robot can be used daily without frequent charging.

#### Authentication/Security
We plan to add an authentication process when initializing the robot on the user's account through the mobile app and the website. Each robot will have a unique secure number configuration that cannot be changed. This configuration will only need to be done once.

#### Cost
We aim to keep the price range for the robot under $500, ideally under $300. The device should be stable, useful, and beneficial to the consumer. The cost should attract consumers to buy our product. Our goal is to ensure the device is worth their money and to exceed their expectations.



<h2>3. Robotic Architecture</h2>

![alt text](RoboticArchitecture.png)
*Robot Architecture*

![alt text](realTime_historicalDataRetrieval.png)
*Data Retrieval for app and learning model*
 
 <h2>3. Systems Architecture:</h2>

![alt text](SystemsArchitecture.png)
*Interaction between website app and robot*

![alt text](<Authentication Process Design.png>)
*Authentication process for robot*

<h2>Architectural Design for both Robotic and System sides: </h2>

<h3> Robot Architectural Design </h3>

<h4> 3.1 Robot Architecture </h4>
1. Robot Server:

  * Robot server takes place within the ROS2 Raspberry Pi.
  * allows information back and forth between client nodes.

2. Universal Topic:
    
    * Universal topic allows for message transferring and message retrieving between client and server nodes.

3. Client Nodes:

    a. Motor Controller Node:

        * Control motor movement and allow for mathematical calculations between movements between a point to another point
    
    b. Sensors Node:
        
        * Object detection, and avoidance sensors such as Lidar, supersonic
        and others. Messaging server when close to object or far from object.
    
    c. Motor Driver Node:

        * Allows control for the motors and will allow speed control for the motor controller as well as battery life control.
    
    d. Distance Node:

        * This will allow for identifying the distance between a point to another point in space.

    e. Motor Node:

        * Motor control and power supply to the motors itself.

4. External Weight Node:
    * This node is seperate from the others because this will instantly connect to the mobile device in order to give live data of how much weight is being stored on the device itself.
<br><br>


<h4>Data Retrieval and Learning Model Architecture </h4>

1. Robot Server:

    * Robot server takes place within the ROS2 Raspberry Pi.
    * Allows information back and forth between client nodes.

2. Real Time Data Retrieval:
    * A method that will be used to obtain live data from the robot.
    * live data varies from battery life, to weight gain.

3. Data:
    
    **Battery Information**: Will give you how much battery is left in the system.

    **Weight Information**: Will give you the amount of weight that is being stored on the system.

    **Distance Information**: Will give the proximity and distance between you and the robot.

    **Temperature Information**: Will give you the interior temperature of where you are storing your items. Will be beneficial due to the fact that people are buying groceries and do not want their items to get spoiled.

4. Mobile App:
    * Will visually show the real time data to the user when they are using the app.
  
5. Learning Model:
    * Will be used to take in past data of the robot in order to find better ways to correct it's movement properly so it can easily, safely, and quickly follow you while trying to reduce battery consumption.
<br><br>

<h3> 3.1 Systems Architectural Design </h3>

<h4> Mobile and Web Application Interaction </h4>
1. Server Follow Bot:
    * We know that this will consist of all the connections to the client nodes, but it will also connect between the mobile app and the website itself.
  
2. ROS2 Raspberry Pi:
    * This device consists of all the fundamental backends in order to connect to the website and the mobile app.

3. Website interaction:
    * Backend to frontend interaction between the website and the Raspberry pi
    * With the website you will be able to also control the robot itself a bit if one is near by.

4. Website:
    * The website will consist of reliable information about the robot as well as have some minor interaction with the robot.

5. Mobile interaction:
    * Backend to frontend interaction between the mobile app and the Raspberry pi
    * The mobile app will have the main control over the robot itself, and will display reliable information about the robot

6. Mobile App:
    * You will be able to interact with the robot through a mobile interface. It will allow you to see certain specs such as battery, temperature, weight, and distance. You will also be able to control the robot if needed.

7. Mail Application interaction:
    * There will be an interaction from frontend to frontend for sending messages through email to a website owner who.

8. Mail Application:
    * The owner of the website will recieve emails from users that use the feedback page on the website. This will allow owners of the website to gain reliable information based on issues or future add-ons for the robot.
<br><br>

<h4> Authentication Process </h4>

1. Robot Server:

    * Robot server takes place within the ROS2 Raspberry Pi.
    * Allows information back and forth between client nodes.

2. Robot Authentication Key:
    * A 16 number/character key meant for every robot.
    * Every key will be different from the last. 

3. Mobile App/Website Authentication:
    a. You will input a username.
    b. You will input a password.

4. Authentication process:
    * the combination of the robots key as well as the users password and username will allow them to be authenticated for the use of the robot and for special offers as well as access towards the guides, feedback page, and support page.

5. Database:
  * The database will be used to store the robots keys, passwords, and usernames of users that are subscribed to the product. The database will be a way of making sure certain keys are not the same from one another as well as passwords and usernames.
<br><br>

### 3.2 Robot Decomposition Architectural Design

#### Robot Architecture

1. **Robot Server**
    - **Description**: The Robot Server operates within the ROS2 Raspberry Pi and facilitates communication between client nodes.
    - **Subsystem Model**:
      - **Class**: `RobotServer`
      - **Attributes**: `serverID`, `status`
      - **Methods**: `initialize()`, `sendMessage()`, `receiveMessage()`
    - **Interface Specifications**:
      - **Interfaces**: `ICommunication`
      - **Methods**: `sendMessage()`, `receiveMessage()`
<br><br>
2. **Universal Topic**
    - **Description**: The Universal Topic enables message transfer and retrieval between client and server nodes.
    - **Subsystem Model**:
      - **Class**: `UniversalTopic`
      - **Attributes**: `topicID`, `messageQueue`
      - **Methods**: `publishMessage()`, `subscribe()`
    - **Interface Specifications**:
      - **Interfaces**: `ITopic`
      - **Methods**: `publishMessage()`, `subscribe()`
<br><br>
3. **Client Nodes**

  a. **Motor Controller Node**

  - **Description**: Controls motor movement and performs mathematical calculations for movement between points.
      
  - **Subsystem Model**:
    - **Class**: `MotorControllerNode`
    - **Attributes**: `controllerID`, `currentPosition`, `targetPosition`
    - **Methods**: `calculatePath()`, `moveToTarget()`
  - **Interface Specifications**:
    - **Interfaces**: `IMotorControl`
    - **Methods**: `calculatePath()`, `moveToTarget()`

  b. **Sensors Node**
      
  - **Description**: Handles object detection and avoidance using sensors like Lidar and supersonic sensors.
  - **Subsystem Model**:
    - **Class**: `SensorsNode`
    - **Attributes**: `sensorID`, `objectDistance`
    - **Methods**: `detectObject()`, `sendAlert()`
  - **Interface Specifications**:
    - **Interfaces**: `ISensor`
    - **Methods**: `detectObject()`, `sendAlert()`

  c. **Motor Driver Node**

  - **Description**: Controls the motors, including speed and battery life management.

  - **Subsystem Model**:
    - **Class**: `MotorDriverNode`
    - **Attributes**: `driverID`, `motorSpeed`, `batteryLevel`
    - **Methods**: `controlSpeed()`, `monitorBattery()`
  - **Interface Specifications**:
      - **Interfaces**: `IMotorDriver`
      - **Methods**: `controlSpeed()`, `monitorBattery()`

  d. **Distance Node**

  - **Description**: Identifies the distance between points in space.

  - **Subsystem Model**:
    - **Class**: `DistanceNode`
    - **Attributes**: `distanceID`, `startPoint`, `endPoint`
    - **Methods**: `calculateDistance()`
  - **Interface Specifications**:
    - **Interfaces**: `IDistance`
    - **Methods**: `calculateDistance()`

  e. **Motor Node**

  - **Description**: Manages motor control and power supply.
      
  - **Subsystem Model**:
    - **Class**: `MotorNode`
    - **Attributes**: `motorID`, `powerSupply`
    - **Methods**: `controlMotor()`
  - **Interface Specifications**:
    - **Interfaces**: `IMotor`
    - **Methods**: `controlMotor()`
<br><br>
4. **External Weight Node**
    
    - **Description**: Connects to a mobile device to provide live data on the weight being stored on the device.
    - **Subsystem Model**:
      - **Class**: `ExternalWeightNode`
      - **Attributes**: `weightID`, `currentWeight`
      - **Methods**: `connectToDevice()`, `sendWeightData()`
    - **Interface Specifications**:
      - **Interfaces**: `IWeight`
      - **Methods**: `connectToDevice()`, `sendWeightData()`

#### Data Retrieval and Learning Model Architecture

1. **Robot Server**
    - **Description**: The Robot Server operates within the ROS2 Raspberry Pi and facilitates communication between client nodes.
    - **Subsystem Model**:
      - **Class**: `RobotServer`
      - **Attributes**: `serverID`, `status`
      - **Methods**: `initialize()`, `sendMessage()`, `receiveMessage()`
    - **Interface Specifications**:
      - **Interfaces**: `ICommunication`
      - **Methods**: `sendMessage()`, `receiveMessage()`

2. **Real Time Data Retrieval**
    - **Description**: A method used to obtain live data from the robot. The live data varies from battery life to weight gain.
    - **Subsystem Model**:
      - **Class**: `RealTimeDataRetrieval`
      - **Attributes**: `dataID`, `batteryLife`, `weightGain`, `timestamp`
      - **Methods**: `retrieveBatteryLife()`, `retrieveWeightGain()`, `updateTimestamp()`
    - **Interface Specifications**:
      - **Interfaces**: `IDataRetrieval`
      - **Methods**: `retrieveBatteryLife()`, `retrieveWeightGain()`, `updateTimestamp()`

3. **Data**
    - **Description**: Provides various types of information about the robot.
    - **Subsystem Model**:
      - **Class**: `Data`
      - **Attributes**: `batteryInfo`, `weightInfo`, `distanceInfo`, `temperatureInfo`
      - **Methods**: `getBatteryInfo()`, `getWeightInfo()`, `getDistanceInfo()`, `getTemperatureInfo()`
    - **Interface Specifications**:
      - **Interfaces**: `IData`
      - **Methods**: `getBatteryInfo()`, `getWeightInfo()`, `getDistanceInfo()`, `getTemperatureInfo()`

4. **Mobile App**
    - **Description**: Visually shows the real-time data to the user when they are using the app.
    - **Subsystem Model**:
      - **Class**: `MobileApp`
      - **Attributes**: `appID`, `realTimeData`
      - **Methods**: `displayRealTimeData()`
    - **Interface Specifications**:
      - **Interfaces**: `IMobileApp`
      - **Methods**: `displayRealTimeData()`

5. **Learning Model**
    - **Description**: Takes in past data of the robot to find better ways to correct its movement, ensuring it can follow you easily, safely, and quickly while reducing battery consumption.
    - **Subsystem Model**:
      - **Class**: `LearningModel`
      - **Attributes**: `modelID`, `pastData`
      - **Methods**: `analyzeData()`, `optimizeMovement()`
    - **Interface Specifications**:
      - **Interfaces**: `ILearningModel`
      - **Methods**: `analyzeData()`, `optimizeMovement()`

### 3.2 Systems Decomposition Architectural Design

#### Mobile and Web Application Interaction

1. **Server Follow Bot**
    - **Description**: Consists of all the connections to the client nodes and connects the mobile app and the website.
    - **Subsystem Model**:
      - **Class**: `ServerFollowBot`
      - **Attributes**: `botID`, `status`
      - **Methods**: `connectToClientNodes()`, `connectToMobileApp()`, `connectToWebsite()`
    - **Interface Specifications**:
      - **Interfaces**: `IConnection`
      - **Methods**: `connectToClientNodes()`, `connectToMobileApp()`, `connectToWebsite()`

2. **ROS2 Raspberry Pi**
    - **Description**: Contains all the fundamental backends to connect to the website and the mobile app.
    - **Subsystem Model**:
      - **Class**: `ROS2RaspberryPi`
      - **Attributes**: `deviceID`, `backendStatus`
      - **Methods**: `initializeBackend()`, `connectToWebsite()`, `connectToMobileApp()`
    - **Interface Specifications**:
      - **Interfaces**: `IBackend`
      - **Methods**: `initializeBackend()`, `connectToWebsite()`, `connectToMobileApp()`

3. **Website Interaction**
    - **Description**: Backend to frontend interaction between the website and the Raspberry Pi. Allows control of the robot if nearby.
    - **Subsystem Model**:
      - **Class**: `WebsiteInteraction`
      - **Attributes**: `interactionID`, `websiteStatus`
      - **Methods**: `backendToFrontend()`, `controlRobot()`
    - **Interface Specifications**:
      - **Interfaces**: `IWebsiteInteraction`
      - **Methods**: `backendToFrontend()`, `controlRobot()`

4. **Website**
    - **Description**: Provides reliable information about the robot and allows minor interaction with the robot.
    - **Subsystem Model**:
      - **Class**: `Website`
      - **Attributes**: `websiteID`, `content`
      - **Methods**: `displayInfo()`, `interactWithRobot()`
    - **Interface Specifications**:
      - **Interfaces**: `IWebsite`
      - **Methods**: `displayInfo()`, `interactWithRobot()`

5. **Mobile Interaction**
    - **Description**: Backend to frontend interaction between the mobile app and the Raspberry Pi. The mobile app has main control over the robot.
    - **Subsystem Model**:
      - **Class**: `MobileInteraction`
      - **Attributes**: `interactionID`, `mobileStatus`
      - **Methods**: `backendToFrontend()`, `controlRobot()`
    - **Interface Specifications**:
      - **Interfaces**: `IMobileInteraction`
      - **Methods**: `backendToFrontend()`, `controlRobot()`

6. **Mobile App**
    - **Description**: Allows interaction with the robot through a mobile interface. Displays specs like battery, temperature, weight, and distance. Allows control of the robot.
    - **Subsystem Model**:
      - **Class**: `MobileApp`
      - **Attributes**: `appID`, `specs`
      - **Methods**: `displaySpecs()`, `controlRobot()`
    - **Interface Specifications**:
      - **Interfaces**: `IMobileApp`
      - **Methods**: `displaySpecs()`, `controlRobot()`

7. **Mail Application Interaction**
    - **Description**: Frontend to frontend interaction for sending messages through email to the website owner.
    - **Subsystem Model**:
      - **Class**: `MailAppInteraction`
      - **Attributes**: `interactionID`, `emailStatus`
      - **Methods**: `sendEmail()`
    - **Interface Specifications**:
      - **Interfaces**: `IMailInteraction`
      - **Methods**: `sendMail()`

8. **Mail Application**
    - **Description**: The website owner receives emails from users using the feedback page. Provides reliable information based on issues or future add-ons for the robot.
    - **Subsystem Model**:
      - **Class**: `MailApplication`
      - **Attributes**: `mailID`, `feedback`
      - **Methods**: `receiveEmail()`, `processFeedback()`
    - **Interface Specifications**:
      - **Interfaces**: `IMailApplication`
      - **Methods**: `recieveEmail()`, `processFeedback()`

#### Authentication Process

1. **Robot Authentication Key**
    - **Description**: A 16 number/character key meant for every robot. Every key will be different from the last.
    - **Subsystem Model**:
      - **Class**: `RobotAuthKey`
      - **Attributes**: `keyID`, `keyValue`
      - **Methods**: `generateKey()`, `validateKey()`
    - **Interface Specifications**:
      - **Interfaces**: `IAuthKey`
      - **Methods**: `generateKey()`, `validateKey()`

2. **Mobile App/Website Authentication**
    - **Description**: Authentication process involving username and password input.
    - **Subsystem Model**:
      - **Class**: `AuthProcess`
      - **Attributes**: `username`, `password`
      - **Methods**: `inputUsername()`, `inputPassword()`
    - **Interface Specifications**:
      - **Interfaces**: `IAuthProcess`
      - **Methods**: `inputUsername()`, `inputPassword()`

3. **Authentication Process**
    - **Description**: Combines the robot’s key with the user’s password and username for authentication.
    - **Subsystem Model**:
      - **Class**: `Authentication`
      - **Attributes**: `authID`, `robotKey`, `userCredentials()`
      - **Methods**: `authenticateUser()`, `grantAccess()`
    - **Interface Specifications**:
      - **Interfaces**: `IAuthentication`
      - **Methods**: `authenticateUser()`, `grantAccess()`

3. **Database**
    - **Description**: Stores robot keys, passwords, and usernames of users subscribed to the product. Ensures unique keys, passwords, and usernames.
    - **Subsystem Model**:
      - **Class**: `Databse`
      - **Attributes**: `dbID`, `userData`
      - **Methods**: `storeData()`, `retrieveData()`
    - **Interface Specifications**:
      - **Interfaces**: `IDatabase`
      - **Methods**: `storeData()`, `retrieveData()`


<h2> 3.3 Design Rationale </h2>
We chose this architecture because we needed something modulus in order to do things properly for the scope of our project. When it comes to the authentication process it was tedious in knowing how we would come about it, but we knew that if we made it modular it would make it less tedious in our side. The way we did it is by creating a Database that the authenticator would interact with in order to generate keys for the robot that would not create replicas based on the ones that are currently on the database. That was one rationale that we chose for this project. 
<br><br>
Another is by keeping the ros2 system on the raspberry pi very interactive between many different pieces of hardware and software. With the ROS2 most of the functionalities that will be introduced will always have to be modulus in order for us to communicate between many different areas of hardware and software. The way we structured our decomposition above makes it easier for us to understand how we will simplify yet comprehend how our system should be.

    
<h2> 4.0 Data Design </h2>

<h3> 4.1 Data Description </h3>
When it comes to data and obtaining historical data for the machine learning model we will be using dataframes in order to store the data properly, ranging from battery life to weight distribution. When it comes to Databases the information will also be stored in a table of data. Other forms of data storing will be used in other applications when it comes to the robot itself

<h3> 4.2 Data Dictionary </h3>


| Object|Attributes|Methods|
|-------|----------|-------|
| **Authentication**| `authID`: String,<br> `robotKey`: String,<br> `userCredentials`: Object| `authenticateUser()`,<br>`grantAccess()`|
| **AuthProcess**| `username`: String,<br> `password`: String| `inputUsername()`,<br> `inputPassword()`|
| **Data**| `batteryInfo`: Float,<br> `weightInfo`: Float,<br> `distanceInfo`: Float,<br> `temperatureInfo`: Float| `getBatteryInfo()`,<br> `getWeightInfo()`,<br> `getDistanceInfo()`,<br> `getTemperatureInfo()`|
| **Database**| `dbID`: String,<br> `userData`: Object| `storeData()`,<br> `retrieveData()`|
| **DistanceNode**| `distanceID`: String,<br> `startPoint`: Object,<br> `endPoint`: Object| `calculateDistance()`|
| **ExternalWeightNode**| `weightID`: String,<br> `currentWeight`: Float| `connectToDevice()`,<br> `sendWeightData()`|
| **LearningModel**| `modelID`: String,<br> `pastData`: Object| `analyzeData()`,<br> `optimizeMovement()`|
| **MailAppInteraction**| `interactionID`: String,<br> `emailStatus`: String| `sendEmail()`|
| **MailApplication**| `mailID`: String,<br> `feedback`: Object| `receiveEmail()`,<br> `processFeedback()`|
| **MobileApp**| `appID`: String,<br> `specs`: Object| `displaySpecs()`,<br> `controlRobot()`|
| **MobileInteraction**| `interactionID`: String,<br> `mobileStatus`: String| `backendToFrontend()`,<br> `controlRobot()`|
| **MotorControllerNode**| `controllerID`: String,<br> `currentPosition`: Object,<br> `targetPosition`: Object | `calculatePath()`,<br> `moveToTarget()`|
| **MotorDriverNode**| `driverID`: String,<br> `motorSpeed`: Float,<br> `batteryLevel`: Float| `controlSpeed()`,<br> `monitorBattery()`|
| **MotorNode**| `motorID`: String,<br> `powerSupply`: Float| `controlMotor()`|
| **RealTimeDataRetrieval**| `dataID`: String,<br> `batteryLife`: Float,<br> `weightGain`: Float,<br> `timestamp`: DateTime| `retrieveBatteryLife()`,<br> `retrieveWeightGain()`,<br> `updateTimestamp()`|
| **RobotAuthKey**| `keyID`: String,<br> `keyValue`: String| `generateKey()`,<br> `validateKey()`|
| **RobotServer**| `serverID`: String,<br> `status`: String| `initialize()`,<br> `sendMessage()`,<br> `receiveMessage()`|
| **SensorsNode**| `sensorID`: String,<br> `objectDistance`: Float| `detectObject()`,<br> `sendAlert()`|
| **ServerFollowBot**| `botID`: String,<br> `status`: String| `connectToClientNodes()`,<br> `connectToMobileApp()`,<br> `connectToWebsite()`|
| **UniversalTopic**| `topicID`: String,<br> `messageQueue`: Queue| `publishMessage()`,<br> `subscribe()`|
| **Website**| `websiteID`: String,<br> `content`: String| `displayInfo()`,<br> `interactWithRobot()`|
| **WebsiteInteraction**| `interactionID`: String,<br> `websiteStatus`: String| `backendToFrontend()`,<br> `controlRobot()`|

<h2> 5. Component Design </h2>


#### Authentication
- **authenticateUser()**
  - Input: `robotKey`, `userCredentials`
  - Process: Validate `robotKey` and `userCredentials`
  - Output: Authentication status

- **grantAccess()**
  - Input: Authentication status
  - Process: Check if authentication is successful
  - Output: Access granted or denied

#### AuthProcess
- **inputUsername()**
  - Input: `username`
  - Process: Store `username`
  - Output: get access to your account once password is in

- **inputPassword()**
  - Input: `password`
  - Process: Store `password`
  - Output: get access to your account

#### Data
- **getBatteryInfo()**
  - Input: Battery potentiometer counter
  - Process: Retrieve `batteryInfo`
  - Output: `batteryInfo`

- **getWeightInfo()**
  - Input: Weight measurer module
  - Process: Retrieve `weightInfo`
  - Output: `weightInfo`

- **getDistanceInfo()**
  - Input: UWB, Bluetooth, or GPS
  - Process: Retrieve `distanceInfo`
  - Output: `distanceInfo`

- **getTemperatureInfo()**
  - Input: Temperature module
  - Process: Retrieve `temperatureInfo`
  - Output: `temperatureInfo`

#### Database
- **storeData()**
  - Input: `userData`
  - Process: Store `userData` in database
  - Output: None

- **retrieveData()**
  - Input: Query
  - Process: Retrieve data from database
  - Output: `userData`

#### DistanceNode
- **calculateDistance()**
  - Input: `startPoint`, `endPoint`
  - Process: Calculate distance between `startPoint` and `endPoint`
  - Output: Distance

#### ExternalWeightNode
- **connectToDevice()**
  - Input: Device ID
  - Process: Establish connection to device
  - Output: Connection status

- **sendWeightData()**
  - Input: `currentWeight`
  - Process: Send `currentWeight` to device
  - Output: None

#### LearningModel
- **analyzeData()**
  - Input: `pastData`
  - Process: Analyze `pastData`
  - Output: Analysis results

- **optimizeMovement()**
  - Input: Analysis results
  - Process: Optimize robot movement
  - Output: Optimized movement parameters

#### MailAppInteraction
- **sendEmail()**
  - Input: Email content
  - Process: Send email to website owner
  - Output: Owner recieves email from users message input

#### MailApplication
- **receiveEmail()**
  - Input: None
  - Process: Receive email from users
  - Output: Email content

- **processFeedback()**
  - Input: Email content
  - Process: Analyze feedback
  - Output: Feedback analysis

#### MobileApp
- **displaySpecs()**
  - Input: `specs`
  - Process: Display `specs` on mobile app
  - Output: None

- **controlRobot()**
  - Input: Control commands
  - Process: Send control commands to robot
  - Output: Robot could move or follow a set of tasks

#### MobileInteraction
- **backendToFrontend()**
  - Input: Backend data
  - Process: Transfer data to frontend
  - Output: Data transfer successful or not

- **controlRobot()**
  - Input: Control commands
  - Process: Send control commands to robot
  - Output: Robot executes those commands

#### MotorControllerNode
- **calculatePath()**
  - Input: `currentPosition`, `targetPosition`
  - Process: Calculate path from `currentPosition` to `targetPosition`
  - Output: Path

- **moveToTarget()**
  - Input: Path
  - Process: Move motor along path
  - Output: motor turns on in order to move towards target

#### MotorDriverNode
- **controlSpeed()**
  - Input: Speed value
  - Process: Adjust motor speed
  - Output: motors speed is adjusted

- **monitorBattery()**
  - Input: Battery potentiometer reading
  - Process: Monitor battery level
  - Output: `batteryLevel`

#### MotorNode
- **controlMotor()**
  - Input: Control commands
  - Process: Execute motor control commands
  - Output: motor commands are executed

#### RealTimeDataRetrieval
- **retrieveBatteryLife()**
  - Input: Battery potentiometer current data reading
  - Process: Retrieve current battery life
  - Output: `batteryLife`

- **retrieveWeightGain()**
  - Input: Weight Module
  - Process: Retrieve current weight gain
  - Output: `weightGain`

- **updateTimestamp()**
  - Input: None
  - Process: Update timestamp of data retrieval
  - Output: `timestamp`

#### RobotAuthKey
- **generateKey()**
  - Input: None
  - Process: Generate a new authentication key
  - Output: `keyValue`

- **validateKey()**
  - Input: `keyValue`
  - Process: Validate the authentication key
  - Output: Validation status

#### RobotServer
- **initialize()**
  - Input: None
  - Process: Initialize the robot server
  - Output: Initialization status

- **sendMessage()**
  - Input: Message
  - Process: Send message to client nodes
  - Output: nodes recieves message

- **receiveMessage()**
  - Input: None
  - Process: Receive message from client nodes
  - Output: Message

#### SensorsNode
- **detectObject()**
  - Input: Lidar sensors, light sensors, etc.
  - Process: Detect object using sensors
  - Output: Object detection status

- **sendAlert()**
  - Input: Object detection status
  - Process: Send alert when object is detected
  - Output: Stop or avoid obstacle when object is detected

#### ServerFollowBot
- **connectToClientNodes()**
  - Input: None
  - Process: Connect to client nodes
  - Output: Connection status

- **connectToMobileApp()**
  - Input: None
  - Process: Connect to mobile app
  - Output: Connection status

- **connectToWebsite()**
  - Input: None
  - Process: Connect to website
  - Output: Connection status

#### UniversalTopic
- **publishMessage()**
  - Input: Message
  - Process: Publish message to topic
  - Output: None

- **subscribe()**
  - Input: None
  - Process: Subscribe to topic
  - Output: Subscription status

#### Website
- **displayInfo()**
  - Input: Information
  - Process: Display information about the robot
  - Output: information of robot is displayed

- **interactWithRobot()**
  - Input: Interaction commands
  - Process: Execute interaction commands with the robot
  - Output: interaction command is executed

#### WebsiteInteraction
- **backendToFrontend()**
  - Input: Backend data
  - Process: Transfer data to frontend
  - Output: None

- **controlRobot()**
  - Input: Control commands
  - Process: Send control commands to robot
  - Output: control command is executed

<h2> 6. Human Interface Design </h2>

<h3> Mobile App: </h3>
As a user when it comes to both the mobild application, it will contain most of the major functionalities. For instance with the mobile app you will be able to see how much battery life is currently on the system, as well as how much weight, the current distance it is away from you, as well as the interior temperature. With the mobile app you will be able to as well interact with the device by controlling its movement if needed. You will be able to test given features with it. Look at the specs of the robot, as well as look at the health of the robot. Parts and services will also be shown of the application itself. The app will be able to as well send you notifications based on how much health is currently on the system, whether if the robot ran into some issues, or is in need of assistance. You as a user will be able to use the app throughout many different mobile devices ranging from apple to android. 
<br><br>

#### Important Functionalities 
Visually on the top right corner of the screen will indicate the battery life of your robot. The middle of the screen will consist of a 3d model version of the robot, while beneath the robot will indicate the amount of weight that is currently on the system. In the middle above the robot will indicate the current temperature within the interior of the robot. A small tab button on the bottom right corner will allow the user to see how far away the robot is from the user. 
<br><br>

#### Settings
on the top left corner will be a setting icon for the robot, where you will be able to find the specs of the robot, changing capabilities for when you want to change the distance between you and the robot, as well as the ability to switch on human control access towards the robot. When switching on human access within the mobile app, the ui will change to a control panel where you will now be able to control the robot through touch screen.

#### Authentication
When accessing the app it will first bring you to an authenticator screen, where you will need to input your username or password . If the user is signing in for the first time then they'll also need to input the robots authentication key in order to access their specific robot that they purchased, as well as their email. However once they do it the first time they won't need to do it again. As a user you will be able to change your password, or username if you forgot. In order to do so, an email will be sent to the user in which they will have to confirm or not that they want a change for a new username or password.


### Website: 
As for the website, it will have minor interactions with the user. But for the user, the website will offer another variety of options that is quite different compared to the mobile app. For instance, the web interface will consist of a variety of tabs to open and see. One tab will consist of a feedback page/guide where you as the user that is currently an owner of the device will be able to ask questions or discuss topics based on the robotic device that you have on hand. Questions can vary from hardware parts, to ways in keeping the robot clean, updating its software, or even future changes in parts for the robot. 
<br><br>

#### Relevant tabs for user to go about
Other tabs will consists of information of the robot, as well as a video recording in how the robot interacts with it's surroundings. Another tab will be accessible to owners of the robot where they will be able to interact with their robot and see how well it's able to avoid obstacles while being able to follow a coordinated path. You will be able to control the robot with this minor interaction that will be found on the web page.
<br><br>

#### News Posting
Another important feature that we would like to add is a news posting tab,
where people will be able to get notified in future updates based on the robots development progress, or even updates on future releases for the robot itself, such as enhancements in parts or software.

#### Authentication
As mentioned within the Mobile App user interface, it will be the same. However the difference will be that you don't have to sign in immediately, The webpage is meant for informational purposes. If you wish to create an account or sign in. A user profile icon for that will be found above in the right hand corner of your screen.

### 6.2 Screen Images

#### Mobile App:
![image](/Images/AuthenticationScreen.png)

*Authentication Screen*

![image](/Images/mainDashboard.png)

*Main Dashboard*

![image](/Images/SettingsScreen.png)

*Setting Screen*

![image](/Images/ControlPanelsScreen.png)

*Control Panels Screen*

#### Website:

![image](/Images/WebsiteFrontPage.png)

*Front page of website*

![image](/Images/FeedbackPageWebsite.png)

*Feedback page of website*

![image](/Images/AboutUsPageWebsite.png)

*About us page of website*

![image](/Images/VideoOfRobotPage.png)

*Video of robot* 

<br>

### 7. Requirements Traceability Matrix

| Requirement-ID| Requirement Description| Design Component| Data Design Component| Interface Design Component|
|----------------|----------------|---------------|------------------|-----------------|
| FR-001| User Authentication| AuthProcess| Database| Authentication|
| FR-002| Display Battery Life| MobileApp| Data| RealTimeDataRetrieval|
| FR-003| Display Weight Information| MobileApp| Data| RealTimeDataRetrieval| FR-004| Display Distance Information| MobileApp| Data| RealTimeDataRetrieval|
| FR-005| Display Temperature Information| MobileApp| Data| RealTimeDataRetrieval|
| FR-006| Control Robot Movement| MobileApp| MotorControllerNode| MotorDriverNode|
| FR-007| Send Notifications| MobileApp| Data| RealTimeDataRetrieval|
| FR-008| User Feedback and Guide| Website| Database| MailApplication|
| FR-009| Display Robot Information| Website| Data| RealTimeDataRetrieval|
| FR-010| Video Recording of Robot Interaction| Website| Data| RealTimeDataRetrieval|
| FR-011| Robot Interaction and Control| Website| MotorControllerNode| MotorDriverNode|
| FR-012| News Posting and Updates| Website| Database| MailApplication|
| FR-013| Generate and Validate Robot Authentication Key| RobotAuthKey| Database| Authentication|
| FR-014| Analyze Past Data for Movement Optimization| LearningModel| Data| RealTimeDataRetrieval|
| FR-015| Store and Retrieve User Data| Database| Database| Authentication|
