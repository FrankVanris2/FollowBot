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

<h2> Robotic Overview<br> </h2>

<h4>Goal:</h4>
The Goal of the robot is for it to carry up to 50 lbs of your belongings and follow you and manuever through different obstacles along the way<br><br>


We will be playing with different kinds of motors, sensors, and modules to determine the best way for the robot to follow the user while maneuvering through different obstacles in a very fast pace. We also want to try and create a device that insentivies the idea of keeping costs to a minimum.<br><br>

<h4> Weight Carrying and Following: </h4>
The user itself will be able to place any type of belongings within the device such as food, electronics, books, sport items, clothing, and much more. The robot while carrying your belongings will track you based on your phones position and its current position via the GPS module that will be installed within the robot itself.<br><br>


<h4> Sensors: </h4>
The robot while following you will consist of many sensors that will be used in order to avoid and move away from any obstacles that will get in it's way. Forms of avoidance will vary between lidar sensors, computer vision, and echo locative tracking. The choices between many of these sensors will be decided as a team and based on how accurate any of these sensors are when it comes to avoiding obstacles as quickly as possible.<br><br>

<h4> Hardware </h4>
When designing the Hardware the idea of cost will be in mind. Hardware during the beginning will be done and created through 3D printing and simple wood work. Designing such hardware will be done through a variety of different design application such as FreeCAD, Fusion360, and Blender. For our preferences when it comes to robotics, freeCAD has the best variety in options and workbenches that us developers and engineers can use when developing and designing the hardware for our robot. <br><br>
When it comes to electronic hardware development and electric wiring, the final design will be created via a pcb manufacturer.

<h4> Real-Time Updates </h4>
Through the mobile app the robot will be able to provide you with real-time updates on battery life, distance between you and the robot, the temperature within the capsule of the robot, as well as the weight distribution that is currently taking place on the robot. When battery life is low, or if the robot is in need of help or repair, it will send the user a notification if any problems are going to occur.

<h4> Machine Learning Models </h4>
When designing and creating the software for the robot, we should also try to add some form of machine learning to the robot itself. The capability for the robot to learn it's own mistakes through reinforcement learning could be quite beneficial when trying to find better ways for this robot to perform while conserving on battery life at the same time. Our goal is to try to conserve as much battery life so that the robot can be used on a daily basis without the worry of consistently charging up the system.

<h4> Authentication/ Security </h4>
When designing and providing a robot for a user our duty is to make sure the robot is secure and reliable to that specific user. That is why we plan on adding an authentication process when properly initializing your robot on your account through the mobile app and the website. We will have a secure number configuration that is different between all robots. A configuration that varies between numbers and letters, that no one will be able to change. This type of configuration will happen only once so that the user does not have to repeatedly initialize the robot when using.

<h4> Cost: </h4>
While playing with different kinds of motors, motor drivers, microcontroller, and material for constructing the robot we will also need to justify a price range for the robot that has to be and <b>MUST</b> be under $500 and at best under $300. The device should be stable useful and beneficial to the consumer that purchases the robot. And the cost should greatly intrigue the consumer in buying our product. However as developers and engineers for the product our goal is to make sure that the device is <b> Worth </b> their money, and try to go <b> ABOVE AND BEYOND </b> with our product.


<h2> System Overview<br> </h2>

<h2>uwb controller<br> </h2>
	To allow the robot to follow us 
	???????<br><br>

<h2>app<br> </h2>

<h4>Goal:</h4>
    The goal of app is to control, maniuplte the robot and  given status report.

<h4>requirement :</h4>

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

<h2>website<br> </h2>


## Website Requirements

<h4>Goal:</h4>
   The goal of the website is to inform the users what the robot does and send queries back to the owners of the websites. 

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


<h2>Robotic Architecture</h2>

![alt text](RoboticArchitecture.png)
*Robot Architecture*

![alt text](realTime_historicalDataRetrieval.png)
*Data Retrieval for app and learning model*
 
 <h2>Systems Architecture:</h2>

![alt text](SystemsArchitecture.png)
*Interaction between website app and robot*

![alt text](<Authentication Process Design.png>)
*Authentication process for robot*

<h2>Architectural Design for both Robotic and System sides: </h2>

<h3> Robot Architectural Design </h3>

<h4> Robot Architecture </h4>
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

<h3> Systems Architectural Design </h3>

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

### Robot Architectural Design

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

### Systems Architectural Design

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


<h2> Design Rationale </h2>
We chose this architecture because we needed something modulus in order to do things properly for the scope of our project. When it comes to the authentication process it was tedious in knowing how we would come about it, but we knew that if we made it modular it would make it less tedious in our side. The way we did it is by creating a Database that the authenticator would interact with in order to generate keys for the robot that would not create replicas based on the ones that are currently on the database. That was one rationale that we chose for this project. 

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

