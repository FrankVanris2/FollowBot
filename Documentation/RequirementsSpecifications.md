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
* *The mobile app should be cross-platform between all mobile devices*.<br>
* *The user will be able to sign in to the mobile app with a authentication protocol that will require the key of the robot near by.*<br>
* *Website will consists of guides for the user in order to communicate any questions or problems with their device.*<br>
* *The robot will contain a mobile user interface for the individual to use in order to control/look at the specs and health of the robot.*<br>
* *Battery life for the robot should be above 8 hours of life and the device must be rechargable.*<br>
* *Allow for historical data retrieval based on the battery life, autonomous movement of the robot, as well as distance control in order to find better ways for autonomous movement through machine learning models.*<br>
* *Cost of product must be at most under $500 and at best under $300.
*<br><br>

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
* https://www.jetbrains.com/help/kotlin-multiplatform-dev/cross-platform-frameworks.html (cross platform frameworks)
* https://tinyurl.com/3stbh3s6 (Security & Authentications)
* https://daylightstrategy.com/ga4service/?gad_source=1&gclid=Cj0KCQjwzva1BhD3ARIsADQuPnU6rwu4H3Qc2IQ3Jj3uZGuMOJurd5xP66cfLx0qRI_F3QYRlXfNR4QaAn_IEALw_wcB (Google Analytics services)
**<h1>2. Overall Description**</h1><br>
**2.1 Compete analysis**<br>

| Top Competitor | Strengths | Weaknesses | Opportunities | Threats |
| --- | --- |--- |--- |--- |
| Gita(mini) & Gita(plus) | - both devices based on the type can carry up to 20-40 lbs <br> <br> - can follow the user and holder of the device while avoiding obstacles along the way <br> <br> - Contains an arrayset of sensors in order to track its leader and avoid obstacles along the way <br><br> - contains a bluetooth speaker that is used for music| - primary focus is to carry your groceries<br><br> -is not meant for rural or tedious terrain <br><br> - battery life can only hold up for 4 hours at most <br><br> - the price range for such a device is above $1000 | - Creating a product that will be able to carry more weight compared to the counterparts. <br> <br> - improve the battery life to withstand as much as 8 hours or more <br><br> - improve the costs for such a robot so that is affordable for any consumer | - improvement and increase of weight lifting for a device similar to what we plan to create <br><br> - The costs for a robot from a competitor decreases to a cosumer level friendly product |

**2.2 User Classes and Customer Profile**<br>
* The who for our user classes include Students, Elderly, Families, Workers, the Disabled, and Individuals <br>
* The when for all of our users would be when they need to travel by foot with belongins that they do not wish to carry. <br>
* The how would be by a connection between a users cellular phone via bluetooth and the robot itself in order for it to start following the user <br>
* Frequency will be based on how far they will need to travel by foot, and how many belongings that they do not wish to carry with them. <br><br>

**Intended Users:**
| Who | What | Where | Why | When | How |
| --- | --- |--- |--- |--- |--- |
| Students | The robot is designed to carry students' belongings such as books, notebooks, and computers. | Schools ranging from elementary to university level. | To alleviate the burden of carrying heavy textbooks between classes or storing them in lockers. | During school hours and while moving from one location to another. | Students can place their belongings into the robot and control it via a mobile app connected through Bluetooth. |
| Elderly | The robot can carry belongings for elderly individuals, especially when items are heavy or inconvenient to carry by hand. | Residential areas, open spaces, marketplaces, etc. | To assist elderly individuals in carrying heavy items during their daily activities. | Whenever an elderly individual needs to carry belongings or purchase items to store in the robot. | Elderly individuals can place their belongings into the robot and control it via a mobile app connected through Bluetooth. |
| Families | The robot can carry a family's belongings, including food, drinks, toys, medical necessities, and heavy loads. | Residential areas, open spaces, marketplaces, etc. | To help family members avoid the inconvenience of carrying heavy items by hand during outings. | When the family is traveling on foot to places like recreational spaces, beaches, city parks, and events. | Families can place their belongings into the robot and control it via a mobile app connected through Bluetooth. |
| Workers | The robot can carry personal belongings or necessary equipment for workers. | Workplaces. | To assist workers in carrying personal or work-related belongings that may be heavy or inconvenient. | When a worker needs to bring belongings to work, or when the workplace requires robots to transport work-related items from station to station. | Workers can place their belongings into the robot and control it via a mobile app connected through Bluetooth. |
| The Disabled | The robot can carry personal or work-related belongings for individuals with disabilities. | Any location where the robot is needed by the disabled individual. | To assist disabled individuals in carrying their belongings, providing them with greater independence. | Anytime the robot is needed by the disabled individual, such as going to the store, walking downtown, or moving around residential areas. | Disabled individuals can place their belongings into the robot and control it via a mobile app connected through Bluetooth. |
| Individuals | The robot can carry personal or work-related belongings for any individual. | Any location where the robot is needed by the individual. | To provide individuals with a convenient way to transport their belongings, whether due to weight or personal preference. | Anytime the robot is needed by the individual, such as going to the store, walking downtown, or moving around residential areas. | Individuals can place their belongings into the robot and control it via a mobile app connected through Bluetooth. |

**In Reality:**<br>
This robot is versatile and can be used by any individual, regardless of their current activity. Whether it's for work-related tasks, family outings, or simply to carry personal belongings, this robot is designed to meet the individual's needs. <br><br>

**2.3 Design and Implementation Constraints**<br>

The construction of the robot presents a significant challenge, given the intricate engineering required to create a device capable of carrying and autonomously following a user. The hardware components and their assembly will demand meticulous attention and precision.

On the software side, we are currently utilizing a newer version of ROS2, specifically the Jazzy version, which is compatible with Raspberry Pi model 5, the newest one. This will allow us to use complex and newly added packages which will then improve the development for our robot and the software that will be used with the robot.

In terms of project success, our primary focus will be on systematic organization and incremental prototyping. We plan to develop a prototype during the first quarter and progressively refine it. Our goal is to deliver a practical and beneficial product for any consumer seeking a robot to carry their belongings.

**2.4 Assumptions and Dependencies**<br>


The successful completion of this project hinges on several factors. A significant challenge could arise from changes in the hardware and software resources required for the robot’s optimal functionality. However, these potential issues are secondary to the primary challenge of maintaining the product’s price under $500. This price point will be a constant consideration throughout the development of our product, but our determination and strategic planning aim to achieve or come close to this goal.

Potential changes in hardware and software could cause temporary delays in the product’s development. The procurement of necessary materials for the hardware aspect of the project could affect our timeline. Similarly, on the software side, the development of the website and app may encounter delays due to software requirements, errors, and bugs. However, based on our past experiences, we are confident in our team’s ability to address these issues promptly and meet our project deadline.

We plan to use reliable hardware that has proven effective in both major manufacturing environments and hobbyist builds. For the software, we will develop an API to establish a connection between the robot and the website/mobile app. This will allow users to visually monitor the robot’s activities, battery life, and control the device based on user input.
<br><br>

**<h1>3. Specific Requirements**</h1><br>

**3.1 User Interfaces**<br>


![image](/Images/WebsiteFrontPage.png)

*front page of website filled with information*

![image](/Images/AboutUsPageWebsite.png)

*about us page which will contain a bio and photos of the developers*

![image](/Images/VideoOfRobotPage.png)

*video of the robot and app in action*

![image](/Images/FeedbackPageWebsite.png)

*feedback page for the user to input questions or suggestions*

![image](/Images/MobileApp.png)

*Mobile app that interfaces with the robot itself*

**Homepage (Large Screen):**

The homepage will prominently feature the product logo in the top left corner. The product’s name and image will be centrally displayed, serving as the focal point of the webpage. Navigation tabs at the top will provide easy access to specific product information that users are likely to seek. A summary positioned near the bottom, just below the robot’s image, will succinctly convey the product’s primary function and its global applicability to all consumers.

The website’s design will reflect the product’s branding, incorporating elements such as the logo, color scheme, and visual identity. Specific elements will highlight our robotic product. The layout will be optimized for a cohesive and visually appealing user experience across various device screen sizes.

A section of the website will consist of discussion pages that will provide guides and support that will be essential for helping those who have questions or are in need of assistance with the robot they have on hand.

The webpage on hand will have some form of minor interaction with the robot. The interaction will be a form of movemental patterns. We plan on adding 2 specific interactions.

1. Moving in a circle while avoiding obstacles
2. Allowing the user to control the robots movement

The user will also be allowed to sign into his account when on the website, and will be able to see their purchases as well as their discussions that they have been in or created. They will as well be notified for future updates about the product in general.

**Mobile App:**

The mobile app, available for free on all major mobile app stores (including Apple and Android), will provide users with vital information about the robot. Upon opening the app, users will be greeted with an iconic image of an animated robot, followed by an authentication screen.

If the user does not currently have an account, they will need to create one and input their robot’s authentication key. (Every robot has a unique key that is different from another). Once they complete the authentication, the mobile app will present them with a 3D model of the robot they currently have on hand.

The top right corner will display a battery life indicator, while the top left corner will show the robot’s internal temperature. Positioned centrally at the bottom, just below the 3D model, an indicator will display the robot’s current carrying capacity, informing users of the weight the robot is presently carrying. Keep noted that this is all real time data.

The mobile app will also be able to send the user notifications based on whether the health of the robot is stable, if the robot is able to track the user, or if certain components of the robot are outdated and in need of repair.

Another notable feature that will be implemented through the app is the ability to control the robot. This will be meant for correcting it's position towards the user, playing with the robot, or just for testing purposes.

**3.2 Functional Requirements**<br>
* The functional requirements for this project includes a robot that will follow the user while avoiding obstacles and allow the user to place their belongings within it. 
* At the same time the user will be able to control certain mechanics of the robot within the mobile app. 
* The mobile app needs to send notifications to the user about the robots needs, as well as possible issues.

* Store the data that is currently being taken as historical data to be used as a way to understand and learn how to incorporate a form of machine learning for the robot. This will give us better ways to understand battery power, battery control, as well as ways in enhancing the autonomous movement of the robots behavior.

* And as a consumer that wishes to purchase the product, they will be able to visit the website that contains information about our product. And purchase our product from the site. <br>

**3.3 Performance and Software Quality Requirements**<br>

1. **Reliability**: The robot should operate without failure under specified conditions for a designated period of time. It should be able to recover from potential failures without significant downtime.<br><br>
2. **Efficiency**: The robot should make optimal use of system resources such as memory, disk space, and processing power. The mobile app and website should load quickly and respond to user input without delay.<br><br>
3. **Usability**: The robot, mobile app, and website should be user-friendly and intuitive. Users should be able to understand and use the system without extensive training or technical knowledge.<br><br>
4. **Maintainability**: The software should be designed in a way that allows for easy updates and modifications. The code should be well-documented and follow best practices for readability and maintainability.<br><br>
5. **Portability**: The mobile app should be compatible with various operating systems (iOS, Android) and the website should be accessible from different browsers (Chrome, Firefox, Safari, Edge).<br><br>
6. **Scalability**: The system should be able to handle an increasing number of tasks effectively. It should be designed to scale up or down based on demand.<br><br>
7. **Security**: The system should protect against unauthorized access and data breaches. User data should be encrypted and the system should comply with relevant privacy regulations.<br><br>
8. **Interoperability**: The robot should be able to interact effectively with other systems or devices. It should follow standard protocols for communication and data exchange.<br><br>
9. **Battery Life**: The robot should be able to operate for a reasonable amount of time on a single charge. Power management features should be implemented to extend battery life.<br><br>
10. **Load Capacity**: The robot should be able to carry up to 50 lbs of weight without impacting its performance or stability.<br><br>

**<h1>4. Breakdown of work/Project timeline plan**</h1><br>

<br>

| Requirements | Quarters | Assigned to: |
| --- | --- | --- |
| Req. 1: General Documentation for the product | Q1 | Frank, Igor|
| Req. 2: prototyping the robot, mobile app, & website | Q2 | Frank, Igor | 
| Req. 3: polishing/refining the robot, mobile app, & website | Q3  |  Frank, Igor  |   
| Req. 4: Bug fixing, Security fixing, and polishing the robot, mobile app, & website | Q4  | Frank, Igor |

| User Stories | Millstone | Assigned to: |
| --- | --- | --- |
| A user will be allowed to click tabs in the website in order to seek information about the robot and how it performs and works. | M1  | Igor |   
| The user will be allowed to find the website via a google search in order to seek information about the robot | M2 | Igor |
| The User will be allowed to seek the cost of such a robot on the website | M3 | Igor |
| The user will be allowed to sign in to their account within the website | M4 | Igor |
| The User will be allowed to connect their robot (if they have one) via the website to test it's functionality for fun and testing purposes | M5 | Frank, Igor |
| When clicking the connect button on the app, the bluetooth will connect with any Follow bot robot in the area | M6 | Frank|
| The robot will follow the user always behind and stay about 1 meter away from the user, the user is allowed to move close to the robot without the robot moving away from the user. | M7 | Frank | 
| The Mobile App will constantly update to retrieve information from the robot about it's battery life, temperature, and weight | M8  | Frank |
| The battery life will be able to last for more than 4 hours | M9 | Frank |






