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

<h4> Cost: </h4>
While playing with different kinds of motors, motor drivers, microcontroller, and material for constructing the robot we will also need to justify a price range for the robot that has to be and <b>MUST</b> be under $500 and at best under $300. The device should be stable useful and beneficial to the consumer that purchases the robot. And the cost should greatly intrigue the consumer in buying our product. However as developers and engineers for the product our goal is to make sure that the device is <b> Worth </b> their money, and try to go <b> ABOVE AND BEYOND </b> with our product.


<h2> System Overview<br> </h2>




