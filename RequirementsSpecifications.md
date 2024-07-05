<h1>Software Requirements Specifications<br>
for<br>
Follow Bot</h1>

<h2> Version 1.0 approved<br>
<br>
Prepared by Frank Vanris, Igor Janotti<br><br>
Bellevue College<br><br>
7/4/2024<br><br></h2>

<h2> 1. Introduction </h2><br><br>

**1.1 Problem statement**<br><br>
*To provide individuals with a robot that can carry their belongings, while weighing the benefits against the costs.*<br><br>

**1.2 Summary**<br><br>
*Designed to assist individuals in transporting their belongings across various environments, this robot is particularly beneficial for those who face physical challenges. Despite its high-quality features, we’ve strived to keep the cost as affordable as possible, aligning it with our budget constraints.*<br><br>

**<h3>1.3 Product Scope</h3>**<br><br>
**1.3.1 In scope**<br>
* *The individual will be allowed to put up to 50 lbs of weight onto the robot itself with no hassle whatsoever.*<br>
* *The robot will be able to avoid obstacles while following the individual with their belongings.*<br>
* *The robot will contain a mobile user interface for the individual to use in order to control/look at the specs and health of the robot.*<br>
* *Battery life for the robot should be above 8 hours of life and the device must be rechargable.*<br>
* *Cost of product must be at most under $500 and at best under $300.*<br><br>

**1.3.2 Out of scope**<br>
* *Developing advanced AI capabilities for the robot, such as voice recognition or autonomous decision-making.*<br>
* *Designing and implementing a system for the robot to climb stairs or navigate uneven terrain.*<br>
* *Creating a solar-powered charging system for the robot.*<br>
* *Building a system for the robot to recognize and respond to specific individuals.*<br>
* *Developing a complex security system for the robot, such as fingerprint recognition or encryption for the mobile user interface.*<br>
* *Implementing a system for the robot to handle fragile items or sort belongings into specific categories.*<br><br>

**<h3>1.4 References</h3>**<br>
Here are the given links to certain documents and websites that will guide us for making the hardware & software:<br><br>
links:<br><br>
**Hardware**:<br>
* https://forum.arduino.cc/t/robot-following-one-specific-human/182826/6 (Robot following questionaire)
* https://shorturl.at/YFixs (L293D Motor driver datasheet)
* https://5.imimg.com/data5/PX/UK/MY-1833510/l293d-based-arduino-motor-shield.pdf (L293D based motorshield)
* https://www.wevolver.com/article/sensors-in-robotics (sensory intel)
* https://en.wikipedia.org/wiki/Lidar (Lidar sensors)
* https://shorturl.at/MdsLB (How to choose the right battery for your robotics system?)
* https://www.wiferion.com/us/wireless-charging-for-robots/#:~:text=Inductive%20Charging%3A%20This%20is%20the,receiver%20coil%20in%20the%20robot. (Induction charging)
* https://www.sparkfun.com/datasheets/GPS/Modules/LS20030~3_datasheet_v1.2.pdf (GPS module Datasheet)

**Software**: <br>
* https://docs.ros.org/en/foxy/index.html (ROS2)
* https://docs.arduino.cc/ (Arduino Docs)
* https://www.instructables.com/Building-a-Mobile-App-to-Control-Arduino-Board-Via/ (Mobile application interface with hardware)
* https://www.imec-int.com/drupal/sites/default/files/2018-11/Accurate%20and%20secure%20Distance%20Measurement%20with%20Bluetooth.pdf (Bluetooth distance measuring)
* https://www.swri.org/industry/industrial-robotics-automation/blog/web-based-robot-user-interface (webpage interface between robotics)

**<h1>2. Overall Description**</h1><br>
**2.1 Compete analysis**<br>

| Top Competitor | Strengths | Weaknesses | Opportunities | Threats |
| --- | --- |--- |--- |--- |
| Gita(mini) & Gita(plus) | - both devices based on the type can carry up to 20-40 lbs <br> <br> - can follow the user and holder of the device while avoiding obstacles along the way <br> <br> - Contains an arrayset of sensors in order to track its leader and avoid obstacles along the way <br><br> - contains a bluetooth speaker that is used for music| - primary focus is to carry your groceries<br><br> -is not meant for rural or tedious terrain <br><br> - battery life can only hold up for 4 hours at most <br><br> - the price range for such a device is above $1000 | - Creating a product that will be able to carry more weight compared to the counterparts. <br> <br> - improve the battery life to withstand as much as 8 hours or more <br><br> - improve the costs for such a robot so that is affordable for any consumer | - improvement and increase of weight lifting for a device similar to what we plan to create <br><br> - The costs for a robot from a competitor decreases to a cosumer level friendly product |


