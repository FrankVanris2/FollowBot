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
* *Implementing a system for the Followbot to handle fragile items or sort belongings into specific categories.*
* *The ability for FollowBot to go up stairs, and go through doors and tedious environments.*
<br><br>

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
* https://onlinelibrary.wiley.com/doi/10.1155/2022/8274455 (WiFi Triangulation)
* https://pmc.ncbi.nlm.nih.gov/articles/PMC7436166/ (RSSI for WiFi positioning)
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

**<h2>3.1 User Interfaces</h2>**<br>

<h3> Website UI </h3>


![image](/Images/website/HomeScreen.png)

***Home Screen of website***
* On the homepage of the website, users will find a series of tabs that provide insightful information about FollowBot, its mobile app, and the developers behind it. These tabs allow users to easily navigate and learn more about the project's various aspects.

<br>

![image](/Images/website/AboutUsPageScreen.png)

***About us page which will contain a bio and photos of the developers***
* One of the tabs will provide detailed information about all the developers who worked on this project. You can scroll from top to bottom to learn about the entire development process of FollowBot.

<br>

![image](/Images/website/AboutMobileAppScreen.png)

***The About Mobile App page explains how the mobile app interacts with FollowBot***
* A Tab that contains insightful information about the mobile app
<br>

![image](/Images/website/AboutFollowBotScreen.png)

***The About FollowBot page***
* It contains information on everything about FollowBot such as it's specs and it's purpose.
<br>

![image](/Images/website/NewsScreen.png)

***The News page***
* It will contain updates in what the team has been working on 
<br>

![image](/Images/website/NewsArticleScreen.png)

***News Article page***
* When clicking on a news article you will be brought to another page where you can read the news.
<br>

![image](/Images/website/ForumsScreen.png)

***Forums page***
* When clicking on the Forums Tab you will see a lot of posts and categories of posts that you can click on to obtain answers to questions that you may have had.
* The Forums page will also allow you to upvote or downvote posts as well as reply to posts if you have an account.
<br>

![image](/Images/website/LoginScreen.png)

***Login screen***
* When clicking the login button you will be met with a slide in screen where you will need to input your username and password.
* If you do not have an account you will be able to sign up.
<br>

![image](/Images/website/SignUpScreen.png)

***Sign Up page***
* When you click on the sign up option you'll be met with another page where you'll need to input your first/last name, your username, and your password.
* Once you do that you'll need to click next.
<br>

![image](/Images/website/FollowBotKeySignUpScreen.png)

***Sign Up Private Key Page***
* When you click next you will be met with another page to input your FollowBots Private Key if you have one. If you do not have one you can click Finish and you will have your account set up without any FollowBot on your account.
* If you have more than one FollowBot you can input as many private keys as you like.
<br>

![image](/Images/website/UserLoggedInScreen.png)

***Logged In Screen***
* When you are logged in you will be brought back to the homepage where you will see that you are signed in.
* When clicking your name you will be met with a drop down bar of certain mini tabs that you can click on ranging from your posts to you logging out.
<br>

![image](/Images/website/UserProfileScreen.png)

***User Profile Page***
* When clicking on the User profile Icon, you will be brought to your user profile where you can check your everything that is related to your FollowBot (If you have one).
<br>

![image](/Images/website/AnalyticsScreen.png)

***Analytics Page***
* When you click on the analytics button, you will be met with everything analytics wise to your FollowBot.
<br>

![image](/Images/website/ControlsScreen.png)

***Controls Page***
* When you click on the Robotic Controls button, you will be met with a screen where you can Control your FollowBot if you are connected to it, as well as receive a live feed of what the FollowBot is visually seeing.
<br>

![image](/Images/website/MappingScreen.png)

***Mapping Page***
* When you click on the Mapping button, you will be met with a screen of the Bellevue College campus. The Mapping System will locate FollowBot and See if it is directly in BC. If it is you will be allowed to map your FollowBot to any specific location on BC if safe to do so.
<br>

![image](/Images/website/MyAccountScreen.png)

***My Account page***
* When you click on the my account screen you will be met with a list of buttons you can click from, as well as see the FollowBots that are accessable through your account.
<br>

![image](/Images/website/SignalScreen.png)

***Signal page***
* When you have FollowBot Around, you will be able to check the signal to see if you are connected to any of your FollowBots. 
* Developer: (For testing purposes) we will print out the private key just to see it's able to retrieve that information. Will be applicable and useful to see if we can have multiple FollowBots interact with one another without any interference
<br>

![image](/Images/website/LiveFeedScreen.png)

***Live Feed page***
* The Live Feed page will allow the user to see visually what FollowBot is seeing when going to a specific location.
<br>

![image](/Images/website/MyPostsScreen.png)

***My Posts page***
* This page will contain your posts and your replies that you have made to other peoples posts or yourself for clarifications.
<br>

![image](/Images/website/SettingsScreen.png)

***Settings page***
* This page will include your basic commands to change the look of your environment as well as prevent or allow notifications to your phone or email. Along with it you will be able to Delete your Data or export it into a csv.
* Rules will also be mentioned where you can read up on what you can and can't do with FollowBot.
<br>

![image](/Images/website/DarkModeScreen.png)

***Darkmode screen***
* When you click the lightmode/darkmode icon in settings you will be able to change the color format of the website. 
<br>

![image](/Images/website/PrivacyAndDataScreen.png)

***Privacy & Data page***
* When clicking the privacy & data icon you will be met with another page where you can either delete all of your data OR export your data into a csv.
<br>

![image](/Images/website/RulesScreen.png)

***Rules page***
* When you click on the rules button you'll be met with the rules page where you'll read everything that you can and can't do with FollowBot.
<br>

![image](/Images/website/AddFollowBotScreen.png)

***Add FollowBot Page***
* When you click on the Add FollowBot Icon, you will be met with another page where you can add one or more FollowBots into your account.
* We will be adding an Admin feature later on which will prevent a user from adding more FollowBots unless they are a admin.
<br>

<h3> Mobile App UI </h3>

![image](/Images/mobileapp/signin.png)

***Landing page for the mobile app***
* The mobile app is intended for users that own or have been assigned a FollowBot. When using the app for the first time, the user will be prompted to register an account alongside an access key. Otherwise, the user may log in and have access to subsequent features.

![image](/Images/mobileapp/features.png)

***Features that are accessible with a registered FollowBot***
* Once logged in, the user will be met with this dashboard (1).
* The mobile app will display the bot's battery life and distance from the device.
* (2) a mobile mapping interface, allowing for track their bot in real time and directing it to a registered location.
* (3) manual motor control
* (4) news about the FollowBot, including software updates and scheduled maintenance.
* (5) notifications pertaining to their bot such as activity and status.

![image](/Images/mobileapp/settings.png)
***User settings***
* clicking the settings button on the feature dashboard will bring you to this page (6).
* (7) privacy & data: information about our data collection done by the FollowBot with the available option of opting out.
* (8) guideline of rules: what you can and can (should) not do with the FollowBot. 


<h3> Robotic UI Interface </h3>

![image](/Images/SPI%20TFT%20RoboticInterface.png)

***Login Screen, Connection Successful Screen & Connection Unsuccessful Screen***
* When it comes to connecting to a network, the robotic interface on the standalone device will allow us to input our ssid and password for a network.
* If the connection is successful you will be met with a friendly screen saying you are connected. You will be allowed to be go back to the login page if you wish.
* If the connection isn't successful you will be met with a sad screen saying that you could not connect to the Network. You will be able to direct back to the login page so you can try again.

**Business Capabilities**

Businesses will be able to register as an admin for their corporation, enabling them to control multiple FollowBots. As an admin, additional authentication will be required. The (yes & no) placeholder is for us to discuss and finalize the authentication design for admins.

As an admin, you will have the ability to share your FollowBot with other users or students in need for a limited period. HOWEVER, due to the increased server usage for retrieving data from multiple FollowBots, admins will need to sign up for a monthly subscription to use our services when managing multiple FollowBots.

**3.2 Functional Requirements**<br>
* Mapping mechanics for the FollowBot to go to specific locations around the registered campus.
* Computer vision mechanics and learning models in order for the FollowBot to identify user when following.
* The functional requirements for this project includes a FollowBot that will follow the user while avoiding obstacles and allow the user to place their belongings within it. 
* At the same time the user will be able to control certain mechanics of the FollowBot within the mobile app. 
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


**3.4 Data Requirements:**

* we will communicate between modules through buffers: `char[]`

* we will communicate to applications using file types: `JSON`

* `uint8_t` will be used for simple integer returns and encoding

* We will implement a data structure, such as a `HashTable`, for ease of retrieval of client data from our database

* our bot will capture photos to be processed by our machine learning model:  photo format i.e. `JPEG`, `PNG`


**<h1>4. Breakdown of work/Project timeline plan**</h1><br>

<br>

| Requirements | Quarters | Assigned to: |
| --- | --- | --- |
| Req. 1: General Documentation for the product and prototyping FollowBot | Q1 | Frank, Igor, Trong, Joseph|
| Req. 2: Revising and polishing general documentation, developing the website, modifying the prototype with initial following mechanics for testing purposes, and beginning minor development on the mobile app. | Q2 | Frank, Igor, Trong, Joseph | 
| Req. 3: Polishing and refining FollowBot and the website, continuing smooth development of the mobile app, and researching and developing machine learning models for pathfinding capabilities and object avoidance/detection. Also working on the mapping system and further refining the website. | Q3  |  Frank, Igor, Trong, Joseph  |   
| Req. 4: Polishing and refining the website and mobile app, enhancing security capabilities, developing machine learning models, improving mapping capabilities around Bellevue College, and continuing to polish and improve FollowBot. | Q4  | Frank, Igor, Trong, Joseph |
| Future: We plan to add facial recognition to the mobile app for easy access to FollowBot profile pages, implement voice recognition for seamless communication with FollowBot, further polish the website and mobile app for better user experience, and research innovative ways to integrate OpenAI technology into all FollowBot devices. | Q5 | Frank, Igor, Trong, Joseph |

<h3> Complete timeline: </h3>

![image](/Images/Timeline1.png)
![image](/Images/Timeline2.png)
![image](/Images/Timeline3.png)
![image](/Images/Timeline4.png)


| Essential-Backlog User Stories | Milestone | Assigned to: |
| --- | --- | --- |
| A user will be able to click tabs on the website to seek information about the FollowBot, how it performs, and how it works. | M1 | Igor |
| The user can register a personal account and link it to their FollowBot. | M2 | Igor |
| The user can connect their FollowBot via the website to test its functionality for testing purposes. | M3 | … |
| The user can register and log in to connect their bot to the network via a supplemental screen module on the physical bot. | M4 | Frank |
| The FollowBot will stay one meter behind the user. | M5 | … | 
| The FollowBot will recognize simple voice commands (i.e., “Stop”, “Go to…”) and respond appropriately. | M6 | … | 
| The user can access the application regardless of platform. | M7 | … | 
| The application will constantly update to retrieve information from the FollowBot about its battery life, temperature, and weight. | M8 | Frank |
| The battery life will be able to last for more than 4 hours. | M9 | Frank |
| The user will be able to map the FollowBot from location to location. | M10 | Joseph |
| The user will be able to request a FollowBot from another location to their position via a mapping tool. | M11 | Joseph |
| The FollowBot will rely on computer vision to identify a target user. | M12 | Trong, Joseph |
| The FollowBot will use computer vision for object detection and take appropriate actions for obstacles. | M13 | Trong |
| The FollowBot, in the event of getting stuck, will attempt to self-correct. If it fails, the bot will notify the user and allow manual control. | M14 | … |
| Restricted administrator privileges will allow access to historical data which may be integrated to improve functionalities. | M15 | … |
| The user can be confident in the security of their data, relying on the robust database, authentications, and opting out of data collection. | M16 | … |







