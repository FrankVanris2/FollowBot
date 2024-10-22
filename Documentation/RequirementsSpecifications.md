<h1>Software Requirements Specifications<br>
for<br>
Follow Bot</h1>

<h2> Version 1.0 approved<br>
<br>
Prepared by Frank Vanris, Igor Janotti, Trong Duong, Joseph Hoang<br><br>
Bellevue College<br><br>
7/4/2024<br><br></h2>

<h2> 1. Introduction </h2><br><br>

**1.1 Problem statement**<br><br>
*To give the disabled access to a device that will map their location in order to follow and warn them of obstacles in the way. To provide individuals with a Followbot that can carry their belongings, while weighing the benefits against the costs.*<br><br>

**1.2 Summary**<br><br>
*Designed to assist individuals in transporting their belongings across various environments, this Followbot is particularly beneficial for those who face physical challenges. Despite its high-quality features, we’ve strived to keep the cost as affordable as possible, aligning it with our budget constraints.*<br><br>

**<h3>1.3 Product Scope</h3>**<br><br>
**1.3.1 In scope**<br>
* *The individual will be allowed to put up to 50 lbs of weight onto the Followbot itself with no hassle whatsoever.*<br>
* *The Followbot will be able to avoid obstacles while following the individual with their belongings.*<br>
* *Developing a complex security system for the Followbot, such as fingerprint recognition or encryption for the mobile user interface.*<br>
* *Designing and implementing a machine learning object recognition model  system for things such as (stairs, signs, obstacles, people)*<br>
* *The mobile app should be cross-platform between all mobile devices*.<br>
* *The user will be able to sign in to the mobile app with a authentication protocol that will require the key of the Followbot near by.*<br>
* *Website will consists of guides for the user in order to communicate any questions or problems with their device.*<br>
* *The Followbot will contain a mobile user interface for the individual to use in order to control/look at the specs and health of the Followbot.*<br>
* *Battery life for the Followbot should be above 8 hours of life and the device must be rechargable.*<br>
* *Building a system for the Followbot to recognize and respond to specific individuals.*<br>
* *Allow for historical data retrieval based on the battery life, autonomous movement of the Followbot, as well as distance control in order to find better ways for autonomous movement through machine learning models.*<br>
* *Developing advanced AI capabilities for the Followbot, such as voice recognition or autonomous decision-making.*<br>
* *Cost of product must be at most under $500 and at best under $300.*<br><br>

**1.3.2 Out of scope**<br>
* *Creating a solar-powered charging system for the Followbot.*<br>
* *Implementing a system for the Followbot to handle fragile items or sort belongings into specific categories.*<br><br>

**<h3>1.4 References</h3>**<br>
Here are the given links to certain documents and websites that will guide us for making the hardware & software:<br><br>
links:<br><br>
**Hardware**:<br>
* https://forum.arduino.cc/t/Followbot-following-one-specific-human/182826/6 (Followbot following questionaire)
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
* https://www.swri.org/industry/industrial-robotics-automation/blog/web-based-Followbot-user-interface (webpage interface between robotics)
* https://www.jetbrains.com/help/kotlin-multiplatform-dev/cross-platform-frameworks.html (cross platform frameworks)
* https://tinyurl.com/3stbh3s6 (Security & Authentications)
* https://daylightstrategy.com/ga4service/?gad_source=1&gclid=Cj0KCQjwzva1BhD3ARIsADQuPnU6rwu4H3Qc2IQ3Jj3uZGuMOJurd5xP66cfLx0qRI_F3QYRlXfNR4QaAn_IEALw_wcB (Google Analytics services)

**<h1>2. Overall Description**</h1><br>
**2.1 Compete analysis**<br>

| Top Competitor | Strengths | Weaknesses | Opportunities | Threats |
| --- | --- |--- |--- |--- |
| Gita(mini) & Gita(plus) | - both devices based on the type can carry up to 20-40 lbs <br> <br> - can follow the user and holder of the device while avoiding obstacles along the way <br> <br> - Contains an arrayset of sensors in order to track its leader and avoid obstacles along the way <br><br> - contains a bluetooth speaker that is used for music| - primary focus is to carry your groceries<br><br> - battery life can only hold up for 4 hours at most <br><br> - the price range for such a device is above $1000 | - Creating a product that will be able to carry more weight compared to the counterparts. <br> <br> - improve the battery life to withstand as much as 8 hours or more <br><br> - improve the costs for such a Followbot so that is affordable for any consumer <br><br> - Adding Mapping capabilities so that the Followbot can do more <br><br> - The device will be able to follow it's own path without the user in mind <br><br> - Adding security capabilities to prevent other users with interfering with the device | - improvement and increase of weight lifting for a device similar to what we plan to create <br><br> - The costs for a Followbot from a competitor decreases to a cosumer level friendly product |

**2.2 User Classes and Customer Profile**<br>
* The who for our user classes include Students, Elderly, Families, Workers, the Disabled, and Individuals <br>
* The when for all of our users would be when they need to travel by foot with belongings that they do not wish to carry. <br>
* The how would be that the Followbot would be allowed to travel to a specific location or have the Followbot recognize the user either by connection or shape in order for it to follow them. <br>
* Frequency will be based on how far the Followbot will need to travel to a given location with a user or by a task from a user <br><br>

**Intended Users:**
| Who | What | Where | Why | When | How |
| --- | --- |--- |--- |--- |--- |
| BC  | The Followbot will map out the BC Campus in order for it to go to specific locations. | Bellevue College Campus | To allow for transportations of items between designated locations in order to reduce weightload on the workers and students. | Whenever the device is needed. | A user will be allowed to send the device to a given location through the mobile app. Mapping capabilities will be based off of BC campus to allow easy knowledge to the Followbot in order for it to go to a specific location. | 
| The Disabled | The Followbot can carry personal or work-related belongings for individuals with disabilities. | Any location where the Followbot is needed by the disabled individual. | To assist disabled individuals in carrying their belongings, providing them with greater independence. | Anytime the Followbot is needed by the disabled individual, such as going to the store, walking downtown, or moving around residential areas. | Disabled individuals can place their belongings into the Followbot and control it via a mobile app using computer vision. |
| Elderly | The Followbot can carry belongings for elderly individuals, especially when items are heavy or inconvenient to carry by hand. | Residential areas, open spaces, marketplaces, etc. | To assist elderly individuals in carrying heavy items during their daily activities. | Whenever an elderly individual needs to carry belongings or purchase items to store in the Followbot. | Elderly individuals can place their belongings into the Followbot and control it via a mobile app using computer vision. |
| Students | The Followbot is designed to carry students' belongings such as books, notebooks, and computers. | Schools ranging from elementary to university level. | To alleviate the burden of carrying heavy textbooks between classes or storing them in lockers. | During school hours and while moving from one location to another. | Students can place their belongings into the Followbot and control it via a mobile app using computer vision. |
| Families | The Followbot can carry a family's belongings, including food, drinks, toys, medical necessities, and heavy loads. | Residential areas, open spaces, marketplaces, etc. | To help family members avoid the inconvenience of carrying heavy items by hand during outings. | When the family is traveling on foot to places like recreational spaces, beaches, city parks, and events. | Families can place their belongings into the Followbot and control it via a mobile app using computer vision. |
| Workers | The Followbot can carry personal belongings or necessary equipment for workers. | Workplaces. | To assist workers in carrying personal or work-related belongings that may be heavy or inconvenient. | When a worker needs to bring belongings to work, or when the workplace requires robots to transport work-related items from station to station. | Workers can place their belongings into the Followbot and control it via a mobile app using computer vision. |
| Individuals | The Followbot can carry personal or work-related belongings for any individual. | Any location where the Followbot is needed by the individual. | To provide individuals with a convenient way to transport their belongings, whether due to weight or personal preference. | Anytime the Followbot is needed by the individual, such as going to the store, walking downtown, or moving around residential areas. | Individuals can place their belongings into the Followbot and control it via a mobile app using computer vision. |


**In Reality:**<br>
This device will be able to map to specific locations that will give more accessibility to users that need assistance when carrying their belongings or when having an item transported to them. This Followbot is versatile and can be used by any individual, regardless of their current activity. Whether it's for work-related tasks, family outings, or simply to carry personal belongings, this Followbot is designed to meet the individual's needs. <br><br>

**2.3 Design and Implementation Constraints**<br>

The construction of the Followbot presents a significant challenge, given the intricate engineering required to create a device capable of carrying and autonomously following a user. The hardware components and their assembly will demand meticulous attention and precision.

On the software side we are utilizing the Arduino Uno Rev4 in order to send and do important tasks for the user. We will be developing a webpage and a app with valuabe information for the user to use when needed. Mapping capabilities and path-finding algorithms will be applied to the Followbot in order to avoid obstacles while following a designated path to a specific location. Computer vision techniques will be used to allow the Followbot to follow the user if needed in order for it to carry their belongings. Sensors such as Lidar, RGB etc. will come with software that will allow us to really improve the machine learning models that we will apply.

In terms of project success, our primary focus will be on systematic organization and incremental prototyping. We plan to develop a prototype during the first quarter and progressively refine it. Our goal is to deliver a practical and beneficial product for any consumer seeking a Followbot to carry their belongings or allow the Followbot to go to designated places.

**2.4 Assumptions and Dependencies**<br>


The successful completion of this project hinges on several factors. A significant challenge could arise from changes in the hardware and software resources required for the FollowBots’s optimal functionality. However, these potential issues are secondary to the primary challenge of maintaining the product’s price under $500. This price point will be a constant consideration throughout the development of our product, but our determination and strategic planning aim to achieve or come close to this goal.

Potential changes in hardware and software could cause temporary delays in the product’s development. The procurement of necessary materials for the hardware aspect of the project could affect our timeline. Similarly, on the software side, the development of the website, app, and machine learning models may encounter delays due to software requirements, errors, and bugs. However, based on our past experiences, we are confident in our team’s ability to address these issues promptly and meet our project deadline.

We plan to use reliable hardware that has proven effective in both major manufacturing environments and hobbyist builds. For the software, we will develop an API to establish a connection between the Followbot and the website/mobile app. This will allow users to visually monitor the FollowBot’s activities, battery life, and control the device based on user input. We will also develop software that will allow mapping capabilities for the Followbot to travel to specific locations, as well as improving or using machine learning models in order for it to identify obstacles or the user that is following.
<br><br>

**<h1>3. Specific Requirements**</h1><br>

**3.1 User Interfaces**<br>


![image](/Images/WebsiteFrontPage.png)

*front page of website filled with information*

![image](/Images/AboutUsPageWebsite.png)

*about us page which will contain a bio and photos of the developers*

![image](/Images/VideoOfRobotPage.png)

*video of the Followbot and app in action*

![image](/Images/FeedbackPageWebsite.png)

*feedback page for the user to input questions or suggestions*

![image](/Images/MobileApp.png)

*Mobile app that interfaces with the Followbot itself*

**Homepage (Large Screen):**

The homepage will prominently feature the product logo in the top left corner. The product’s name and image will be centrally displayed, serving as the focal point of the webpage. Navigation tabs at the top will provide easy access to specific product information that users are likely to seek. A summary positioned near the bottom, just below the FollowBot’s image, will succinctly convey the product’s primary function and its global applicability to all consumers.

The website’s design will reflect the product’s branding, incorporating elements such as the logo, color scheme, and visual identity. Specific elements will highlight our robotic product. The layout will be optimized for a cohesive and visually appealing user experience across various device screen sizes.

A section of the website will consist of discussion pages that will provide guides and support that will be essential for helping those who have questions or are in need of assistance with the Followbot they have on hand.

The webpage on hand will have some form of minor interaction with the Followbot. The interaction will be a form of movemental patterns. We plan on adding 2 specific interactions.

1. Moving in a circle while avoiding obstacles
2. Allowing the user to control the FollowBots movement

The user will also be allowed to sign into his account when on the website, and will be able to see their purchases as well as their discussions that they have been in or created. They will as well be notified for future updates about the product in general.

**Mobile App:**

The mobile app, available for free on all major mobile app stores (including Apple and Android), will provide users with vital information about the Followbot. Upon opening the app, users will be greeted with an iconic image of an animated Followbot, followed by an authentication screen.

If the user does not currently have an account, they will need to create one and input their FollowBot’s authentication key. (Every Followbot has a unique key that is different from another). Once they complete the authentication, the mobile app will present them with a 3D model of the Followbot they currently have on hand.

The top right corner will display a battery life indicator, while the top left corner will show the FollowBot’s internal temperature. Positioned centrally at the bottom, just below the 3D model, an indicator will display the FollowBot’s current carrying capacity, informing users of the weight the Followbot is presently carrying. Keep noted that this is all real time data.

The mobile app will also be able to send the user notifications based on whether the health of the Followbot is stable, if the Followbot is able to track the user, or if certain components of the Followbot are outdated and in need of repair.

The mobile app will consist of a mapping feature where you will be able to map your FollowBot to a specific location or direct it back to your location if it's at another place.

Another notable feature that will be implemented through the app is the ability to control the Followbot. This will be meant for correcting it's position towards the user, playing with the Followbot, or just for testing purposes.

**3.2 Functional Requirements**<br>
* Mapping mechanics for the Followbot to go to specific locations around Bellevue College.
* Computer vision mechanics and learning models in order for the Followbot to identify user when following.
* The functional requirements for this project includes a Followbot that will follow the user while avoiding obstacles and allow the user to place their belongings within it. 
* At the same time the user will be able to control certain mechanics of the Followbot within the mobile app. 
* The mobile app needs to send notifications to the user about the FollowBots needs, as well as possible issues.

* Store the data that is currently being taken as historical data to be used as a way to understand and learn how to incorporate a form of machine learning for the Followbot. This will give us better ways to understand battery power, battery control, as well as ways in enhancing the autonomous movement of the FollowBots behavior.

* And as a consumer that wishes to purchase the product, they will be able to visit the website that contains information about our product. And purchase our product from the site. <br>

**3.3 Performance and Software Quality Requirements**<br>

1. **Reliability**: The Followbot should operate without failure under specified conditions for a designated period of time. It should be able to recover from potential failures without significant downtime.<br><br>
2. **Efficiency**: The Followbot should make optimal use of system resources such as memory, disk space, and processing power. The mobile app and website should load quickly and respond to user input without delay.<br><br>
3. **Usability**: The Followbot, mobile app, and website should be user-friendly and intuitive. Users should be able to understand and use the system without extensive training or technical knowledge.<br><br>
4. **Maintainability**: The software should be designed in a way that allows for easy updates and modifications. The code should be well-documented and follow best practices for readability and maintainability.<br><br>
5. **Machine Learning**: Creating a learning model to identify specific objects for object avoidance and path-finding.<br><br>
6. **Mapping**: Using Google maps or BC map for pathfinding with FollowBot in order for it to go from location to locaiton.<br><br>
6. **Portability**: The mobile app should be compatible with various operating systems (iOS, Android) and the website should be accessible from different browsers (Chrome, Firefox, Safari, Edge).<br><br>
7. **Scalability**: The system should be able to handle an increasing number of tasks effectively. It should be designed to scale up or down based on demand.<br><br>
8. **Security**: The system should protect against unauthorized access and data breaches. User data should be encrypted and the system should comply with relevant privacy regulations.<br><br>
9. **Interoperability**: The Followbot should be able to interact effectively with other systems or devices. It should follow standard protocols for communication and data exchange.<br><br>
10. **Battery Life**: The Followbot should be able to operate for a reasonable amount of time on a single charge. Power management features should be implemented to extend battery life.<br><br>
11. **Load Capacity**: The Followbot should be able to carry up to 50 lbs of weight without impacting its performance or stability.<br><br>

**<h1>4. Breakdown of work/Project timeline plan**</h1><br>

<br>

| Requirements | Quarters | Assigned to: |
| --- | --- | --- |
| Req. 1: General Documentation for the product | Q1 | Frank, Igor, Trong, Joseph|
| Req. 2: prototyping the Followbot, mobile app, & website | Q2 | Frank, Igor, Trong, Joseph | 
| Req. 3: polishing/refining the Followbot, mobile app, & website | Q3  |  Frank, Igor, Trong, Joseph  |   
| Req. 4: Bug fixing, Security fixing, and polishing the Followbot, mobile app, & website | Q4  | Frank, Igor, Trong, Joseph |

| none-backlog User Stories | Millstone | Assigned to: |
| --- | --- | --- |
| A user will be allowed to click tabs in the website in order to seek information about the Followbot and how it performs and works. | M1  | Igor |   
| The user will be allowed to find the website via a google search in order to seek information about the Followbot | M2 | Igor |
| The User will be allowed to seek the cost of such a Followbot on the website | M3 | Igor |
| The user will be allowed to sign in to their account within the website | M4 | Igor |
| The User will be allowed to connect their Followbot (if they have one) via the website to test it's functionality for fun and testing purposes | M5 | Frank, Igor |
| When clicking the connect button on the app, the bluetooth will connect with any Follow bot Followbot in the area | M6 | Frank|
| The Followbot will follow the user always behind and stay about 1 meter away from the user, the user is allowed to move close to the Followbot without the Followbot moving away from the user. | M7 | Frank | 
| The Mobile App will constantly update to retrieve information from the Followbot about it's battery life, temperature, and weight | M8  | Frank |
| The battery life will be able to last for more than 4 hours | M9 | Frank |
| A developer will be able to test their code on a virtual FollowBot when the actual FollowBot is not around for testing | m10 | Frank |
| The user will be able to map the FollowBot from location to location if needed | m11 | Joseph |
| A user will be able to direct the FollowBot from another location to  their position via the mapping tool on the mobile app | m12 | Joseph |
| A developer will store the maps in a database for easy access and easy control for when FollowBot is in different locations | m13 | Joseph |
| The Developer will allow the Folowbot to follow the user by using forms of computer vision | m14 | Trong |
| A user will be able to keep FollowBot near them at all times. Especially when there are obstacles along the way | m15 | Trong |
| A developer will use a camera in order for FollowBot to visualize and see us with Computer Vision | m15 | Trong |
| A developer will be able to test their code on a virtual Followbot when the actual Followbot is not around for testing | m10 | Frank |






