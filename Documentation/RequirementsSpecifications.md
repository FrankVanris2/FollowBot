<h1>Software Requirements Specifications<br>
for<br>
FollowBot</h1>

<h2> Version 1.0 approved<br>
<br>
Prepared by Frank Vanris, Igor Janotti, Trong Duong, Joseph Hoang<br><br>
Bellevue College<br><br>
Last Modified: 11/11/2024<br><br></h2>

<h2> 1. Introduction </h2><br><br>

**1.1 Problem statement**<br><br>
*To give the disabled access to a device that will map their location in order to follow and warn them of obstacles in the way. To provide individuals with a FollowBot that can carry their belongings, while weighing the benefits against the costs.*<br><br>

**1.2 Summary**<br><br>
*Designed to assist individuals in transporting their belongings across various environments, this FollowBot is particularly beneficial for those who face physical challenges. Despite its high-quality features, we’ve strived to keep the cost as affordable as possible, aligning it with our budget constraints.*<br><br>

**<h3>1.3 Product Scope</h3>**<br><br>
**1.3.1 In scope**<br>
* *The individual will be allowed to put up to 50 lbs of weight onto the FollowBot itself with no hassle whatsoever.*<br>
* *The FollowBot will recognize the registered user and follow them while carrying their belongings. .*<br>
* *Design and implement a machine learning object recognition model for classifications such as: stairs, signs, obstacles, people who are not the user.*<br>
* *Design a NoSQL database for the user to opt into uploading product data for continuous improvement of the model.*<br>
* *Develop AI capabilities for the FollowBot, such as voice recognition to allow for voice commands such as: “Go to…”, “Stop”.*<br>
* *Integrate mapping capabilities for the FollowBot to know nearby tags (viable paths, ramps, entrances) which the bot may auto-path to in the event of obstruction.*<br>
* *Develop a mapping interface for the user to direct the bot to a target location, so the FollowBot may be delivered or be a delivery service.*<br>
* *Develop a companion, multi-platform application for the user to access the mapping interface, FollowBot stats (battery life, temperature, weight), and live location.*<br>
* *A user may register themselves to the robot via access key and authorization protocol through the application.*<br>
* *The companion application will also provide additional sources of information, such as FAQs, user forums, and contacting a developer for questions or problems.*<br>
* *In the event that the FollowBot cannot self-correct or navigate beyond an obstacle, the user will be notified and allowed manual control of the bot through the application.*<br>
* *Developing a complex security system for the FollowBot, such as encryption or two-factor authorization.*<br>
* *The mobile app should be cross-platform between all mobile devices*.<br>
* *will contain a mobile user interface for the individual to use in order to control/look at the specs and health of the FollowBot.*<br>
* *Battery life for the FollowBot should be above 8 hours of life and the device must be rechargeable.*<br>
* *Building a system for the FollowBot to recognize and respond to specific individuals.*<br>
* *Allow for historical data retrieval based on the battery life, autonomous movement of the FollowBot, as well as distance control in order to find better ways for autonomous movement through machine learning models.*<br>
* *Developing advanced AI capabilities for the FollowBot, such as voice recognition or autonomous decision-making.*<br>
* *Cost of product must be at most under \$500 and at best under \$300.*<br><br>

**1.3.2 Out of scope**<br>
* *Creating a solar-powered charging system for the FollowBot.*<br>
* *Implementing a system for the FollowBot to handle fragile items or sort belongings into specific categories.*
* *The ability for FollowBot to go upstairs, and go through doors and tedious environments.*
<br><br>

**<h3>1.4 References</h3>**<br>
Here are the given links to certain documents and websites that will guide us for making the hardware & software:<br><br>
links:<br><br>
**Hardware**:<br>
* https://forum.arduino.cc/t/Followbot-following-one-specific-human/182826/6 (FollowBot following questionnaire)
* https://shorturl.at/YFixs (L293D Motor driver datasheet)
* https://5.imimg.com/data5/PX/UK/MY-1833510/l293d-based-arduino-motor-shield.pdf (L293D based motor shield)
* https://www.wevolver.com/article/sensors-in-robotics (sensory intel)
* https://en.wikipedia.org/wiki/Lidar (Lidar sensors)
* https://shorturl.at/MdsLB (How to choose the right battery for your robotics system?)
* https://www.wiferion.com/us/wireless-charging-for-robots/#:~:text=Inductive%20Charging%3A%20This%20is%20the,receiver%20coil%20in%20the%20robot (Induction charging)
* https://www.sparkfun.com/datasheets/GPS/Modules/LS20030~3_datasheet_v1.2.pdf (GPS module Datasheet)

**Software**: <br>
* https://docs.ros.org/en/foxy/index.html (ROS2)
* https://docs.arduino.cc/ (Arduino Docs)
* https://www.instructables.com/Building-a-Mobile-App-to-Control-Arduino-Board-Via/ (Mobile application interface with hardware)
* https://docs.ultralytics.com/guides/raspberry-pi/ (“You Only Look Once” ML model documentation)
* https://pmc.ncbi.nlm.nih.gov/articles/PMC7436166/ (SRRI)
* https://onlinelibrary.wiley.com/doi/10.1155/2022/8274455 (WiFi Triangulation)
* https://pmc.ncbi.nlm.nih.gov/articles/PMC7436166/ (RSSI for WiFi positioning)
* https://www.swri.org/industry/industrial-robotics-automation/blog/web-based-Followbot-user-interface (webpage interface between robotics)
* https://www.jetbrains.com/help/kotlin-multiplatform-dev/cross-platform-frameworks.html (cross-platform frameworks)
* https://tinyurl.com/3stbh3s6 (Security & Authentications)
* https://daylightstrategy.com/ga4service/?gad_source=1&gclid=Cj0KCQjwzva1BhD3ARIsADQuPnU6rwu4H3Qc2IQ3Jj3uZGuMOJurd5xP66cfLx0qRI_F3QYRlXfNR4QaAn_IEALw_wcB (Google Analytics services)

**<h1>2. Overall Description**</h1><br>
**2.1 Compete analysis**<br>

| Top Competitor | Strengths | Weaknesses | Opportunities | Threats |
| --- | --- |--- |--- |--- |
| Gita(mini) & Gita(plus) | - both devices based on the type can carry up to 20-40 lbs <br> <br> - can follow the user and holder of the device while avoiding obstacles along the way <br> <br> - Contains an array-set of sensors in order to track its leader and avoid obstacles along the way <br><br> - contains a bluetooth speaker that is used for music| - primary focus is to carry your groceries<br><br> - battery life can only hold up for 4 hours at most <br><br> - the price range for such a device is above $1000 | - Creating a product that will be able to carry more weight compared to the counterparts. <br> <br> - improve the battery life to withstand as much as 8 hours or more <br><br> - improve the costs for such a Followbot so that is affordable for any consumer <br><br> - Adding Mapping capabilities so that the Followbot can do more <br><br> - The device will be able to follow its own path without the user in mind <br><br> - Adding security capabilities to prevent other users with interfering with the device | - improvement and increase of weight lifting for a device similar to what we plan to create <br><br> - The costs for a Followbot from a competitor decreases to a consumer level friendly product |

**2.2 User Classes and Customer Profile**<br>
* The who for our user classes include Students, Elderly, Families, Workers, the Disabled, and Individuals <br>
* The when for all of our users would be when they need to travel by foot with belongings that they do not wish to carry. <br>
* The how would be that the FollowBot would be allowed to travel to a specific location or have the FollowBot recognize the user either by connection or shape in order for it to follow them. <br>
* Frequency will be based on how far the FollowBot will need to travel to a given location with a user or by a task from a user <br><br>

**Intended Users:**
**Intended Users:**

| Who                | What                                                                                                                    | Where                                       | Why                                                                                                                  | When                                        | How                                                                                                                                                    |
|--------------------|-------------------------------------------------------------------------------------------------------------------------|---------------------------------------------|-----------------------------------------------------------------------------------------------------------------------|---------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------|
| Business Campuses | The FollowBot will map out the campus to be equipped with surrounding tags and to go to specific locations.             | The Campus                                  | To allow for transportation of items between designated locations to reduce weight load on workers or students.      | Whenever the device is needed.              | The mapping interface will allow users to send the bot to a given location. The map will be based on the campus for easy navigation by the FollowBot.   |
| The Disabled       | The FollowBot can carry personal or work-related belongings for individuals with disabilities.                          | Any location needed by the disabled individual. | To assist disabled individuals in carrying belongings, relieving such concerns.                                       | Anytime, such as going to the store, walking downtown, etc. | Disabled individuals can place belongings into the FollowBot and rely on its computer vision follow mechanics and a provided application. |
| Elderly            | The FollowBot can carry belongings for elderly individuals, especially heavy or inconvenient items.                    | Residential areas, marketplaces, etc.       | To assist elderly individuals in carrying heavy items during daily activities.                                        | Whenever needed.                             | Elderly individuals can place belongings into the FollowBot, using its computer vision follow mechanics and the application.                           |
| Students           | The FollowBot is designed to carry belongings such as books, notebooks, and computers.                                 | Schools ranging from elementary to university | To alleviate the burden of carrying textbooks between classes or storing them in lockers.                             | During school hours or while moving around. | Students can place belongings into the FollowBot and rely on its follow mechanics and the application.                                                |
| Families           | The FollowBot can carry belongings including food, drinks, toys, medical items, and heavy loads.                       | Residential areas, open spaces, etc.        | To help family members avoid carrying heavy items by hand during outings.                                             | When traveling to recreational spaces, etc. | Families can place belongings into the FollowBot and rely on its follow mechanics and the application.                                                |
| Workers            | The FollowBot can carry personal or necessary equipment for workers.                                                   | Workplaces                                  | To assist workers in carrying personal or work-related belongings that are heavy or inconvenient.                     | When needed to bring belongings to work.    | Workers can place belongings into the FollowBot and rely on its follow mechanics and the application.                                                |
| Individuals        | The FollowBot can carry personal or work-related belongings for any individual.                                        | Any location needed by the individual       | To provide individuals a way to transport belongings due to weight or preference.                                     | Anytime, e.g., shopping or walking downtown. | Individuals can place belongings into the FollowBot and rely on its follow mechanics and the application.                                                |

**In Reality:**<br>
This device will give more accessibility to users that need assistance when carrying their belongings. This FollowBot is versatile and can be used by any individual, regardless of their current activity. Whether it's for work-related tasks, family outings, or simply to carry personal belongings, this FollowBot is designed to meet the individual's needs. <br><br>

**2.3 Design and Implementation Constraints**<br>

The construction of the FollowBot presents a significant challenge, given the intricate engineering required to create a device capable of carrying and autonomously following a user. The hardware components and their assembly will demand meticulous attention and precision.

On the software side we are utilizing the Arduino Uno Rev4 with PlatformIO for managing motor sensors. Meanwhile, we are leveraging the Raspberry Pi with the Robot Operating System (ROS2) for efficient logical processing, communication, and data flow.  We will be developing a companion application for the user to access aforementioned features and further documentation.. Mapping capabilities and path-finding algorithms will be applied to the FollowBot in order to avoid obstacles while following a designated path to a specific location. Computer vision techniques will be used to allow the FollowBot to follow the user if needed in order for it to carry their belongings. Modules for WiFi and GPS will come with software to improve general motion, enhance mapping, and the machine learning model.

In terms of project success, our primary focus will be on systematic organization (front-end, back-end, robotics) and incremental prototyping with progressive refinement. Our goal is to deliver a practical and beneficial product for any consumer seeking a FollowBot to carry their belongings or allow the FollowBot to go to designated places.

**2.4 Assumptions and Dependencies**<br>

The successful completion of this project hinges on several factors. A significant challenge could arise from changes in the hardware and software resources required for the FollowBot’s optimal functionality. However, these potential issues are secondary to the primary challenge of maintaining the product’s price under $500. This price point will be a constant consideration throughout the development of our product, but our determination and strategic planning aim to achieve or come close to this goal.

Potential changes in hardware and software could cause temporary delays in the product’s development. The procurement of necessary materials for the hardware aspect of the project could affect our timeline. Similarly, on the software side, the development of the application and machine learning models may encounter delays due to software requirements, errors, and bugs. However, based on our past experiences, we are confident in our team’s ability to address these issues promptly and meet our project deadline.

We plan to use reliable hardware that has proven effective in both major manufacturing environments and hobbyist builds. For the software, we will develop an API to establish a client-server model between the FollowBot and the application interface. . This will allow users to visually monitor the FollowBot’s activities, performance, and control the device based on user input.

To support the machine learning model and enable seamless data flow between the FollowBot, its application interface, and storage solutions, we will utilize Amazon Web Services (AWS) and MongoDB. Leveraging AWS as our primary cloud infrastructure will enable reliable and scalable resources for data processing, model training, and storage. This will allow better ability to manage and update the machine learning model while relieving some stress to the physical bot. MongoDB will be used to store the data collected by the FollowBot, including user credentials, historical data, and any image data required for model training. MongoDB flexibility in adjusting data structures will offer an ideal solution to handling structured and unstructured data.  

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
* It contains information on everything about FollowBot such as its specs, and its purpose.
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
* The Forums page will also allow you to upvote or down-vote posts as well as reply to posts if you have an account.
<br>

![image](/Images/website/LoginScreen.png)

***Login screen***
* When clicking the login button you will be met with a slide in screen where you will need to input your username and password.
* If you do not have an account you will be able to sign up.
<br>

![image](/Images/website/SignUpScreen.png)

***Sign Up page***
* When you click on the signup option you'll be met with another page where you'll need to input your first/last name, your username, and your password.
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
* When clicking your name you will be met with a drop-down bar of certain mini tabs that you can click on ranging from your posts to you logging out.
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

***Main Dashboard after logging in***
* Once logged into the FollowBot Mobile App, you will be greeted by the main dashboard. This screen features a 3D image of your FollowBot, along with icons displaying vital information: battery life, weight carried, current temperature, and distance between you and your FollowBot. 

* In the top left corner of your screen, you'll see a gear icon representing the settings tab of the mobile app. Clicking it will present you with a variety of options, including dark mode or light mode settings and FollowBot user controls.

* Near the bottom of the screen, there are three sets of buttons for the user to click. The notifications tab allows users to receive alerts from FollowBot whenever it needs assistance.

* The news tab will provide users with exciting updates and news about FollowBot directly from the team.

* The store tab will offer options for purchasing spare parts or upgrades that users might need in the future.

**Homepage (Large Screen):**

The homepage will prominently feature the product logo in the top left corner. The product’s name and image will be centrally displayed, serving as the focal point of the webpage. Navigation tabs at the top will provide easy access to specific product information that users are likely to seek. A summary positioned near the bottom, just below the FollowBot’s image, will succinctly convey the product’s primary function and its global applicability to all consumers.

The website’s design will reflect the product’s branding, incorporating elements such as the logo, color scheme, and visual identity. Specific elements will highlight our robotic product. The layout will be optimized for a cohesive and visually appealing user experience across various device screen sizes.

A section of the website will consist of discussion pages that will provide guides and support that will be essential for helping those who have questions or are in need of assistance with the Followbot they have on hand.

The webpage on hand will have some form of minor interaction with the Followbot. The interaction will be a form of movemental patterns. We plan on adding 2 specific interactions.

1. Moving in a circle while avoiding obstacles
2. Allowing the user to control the FollowBots movement

The user will also be allowed to sign in to their account when on the website, and will be able to see their purchases as well as their discussions that they have been in or created. They will as well be notified for future updates about the product in general.

**Mobile App:**

The mobile app, available for free on all major mobile app stores (including Apple and Android), will provide users with vital information about the Followbot. Upon opening the app, users will be greeted with an iconic image of an animated Followbot, followed by an authentication screen.

If the user does not currently have an account, they will need to create one and input their FollowBot’s authentication key. (Every Followbot has a unique key that is different from another). Once they complete the authentication, the mobile app will present them with a 3D model of the Followbot they currently have on hand.

The top right corner will display a battery life indicator, while the top left corner will show the FollowBot’s internal temperature. Positioned centrally at the bottom, just below the 3D model, an indicator will display the FollowBot’s current carrying capacity, informing users of the weight the Followbot is presently carrying. Keep noted that this is all real time data.

The mobile app will also be able to send the user notifications based on whether the health of the Followbot is stable, if the Followbot is able to track the user, or if certain components of the Followbot are outdated and in need of repair.

The mobile app will consist of a mapping feature where you will be able to map your FollowBot to a specific location or direct it back to your location if it's at another place.

When it comes to FollowBot Control, There will be a difference between a regular user and a admin user. A admin user will be allowed to take into control many FollowBots. A Regular user can only control one FollowBot. As an Admin you will be allowed to share FollowBot with other users who are in need for a limited amount of time.

Another notable feature that will be implemented through the app is the ability to control the Followbot. This will be meant for correcting it's position towards the user, playing with the Followbot, or just for testing purposes.

**3.2 Functional Requirements**<br>
* The user will be able to place their belongings within the FollowBot without affecting the further functionalities.
* Mapping mechanics for the FollowBot to go to specific locations around the bot’s designated campus.
* Computer vision mechanics and learning models in order for the FollowBot to identify the registered user when following.
* The FollowBot that will follow the user while avoiding obstacles.
* The FollowBot will respond appropriately to user voice commands, and ultimately be able to self-handle unique instances.
* At the same time the user will be able to control certain mechanics of the FollowBot within the application.
* The application needs to send notifications to the user about the FollowBots needs, as well as possible issues.
* Historical data may be stored and retrieved to continuously improve the machine learning model and optimize functionalities such as autonomous movement and battery life.
* The user will be able to opt out of data collection, so that paths and images taken will remain local and not be uploaded to the collective database.
* And as a consumer that wishes to purchase the product, they will be able to visit the website that contains information about our product. And purchase our product from the site. <br>

**3.3 Performance and Software Quality Requirements**<br>

1. **Reliability**: The FollowBot should operate without failure under specified conditions for a designated period of time. It should be able to recover from potential failures without significant downtime.<br><br>
2. **Efficiency**: The FollowBot should make optimal use of system resources such as memory, disk space, and processing power. The mobile app and website should load quickly and respond to user input without delay.<br><br>
3. **Usability**: The FollowBot, mobile app, and website should be user-friendly and intuitive. Users should be able to understand and use the system without extensive training or technical knowledge.<br><br>
4. **Maintainability**: The software should be designed in a way that allows for easy updates and modifications. The code should be well-documented and follow best practices for readability and maintainability.<br><br>
5. **Machine Learning**: Creating a learning model to identify specific objects for object avoidance and path-finding.<br><br>
6. **Mapping**: Using mapping APIs or BC map for pathfinding with FollowBot in order for it to go from location to location.<br><br>
6. **Portability**: The mobile app should be compatible with various operating systems (iOS, Android) and the website should be accessible from different browsers (Chrome, Firefox, Safari, Edge).<br><br>
7. **Scalability**: The system should be able to handle an increasing number of tasks effectively. It should be designed to scale up or down based on demand.<br><br>
8. **Security**: The system should protect against unauthorized access and data breaches. User data should be encrypted and the system should comply with relevant privacy regulations.<br><br>
9. **Interoperability**: The FollowBot should be able to interact effectively with other systems or devices. It should follow standard protocols for communication and data exchange.<br><br>
10. **Battery Life**: The FollowBot should be able to operate for a reasonable amount of time on a single charge. Power management features should be implemented to extend battery life.<br><br>
11. **Load Capacity**: The FollowBot should be able to carry up to 50 lbs of weight without impacting its performance or stability.<br><br>


**3.4 Data Requirements:**

* we will communicate between modules through buffers: `char[]`

* we will communicate to applications using file types: `JSON`

* `uint8_t` will be used for simple integer returns and encoding

* We will implement a data structure, such as a `HashTable` and dataframes, for ease of retrieval of client data from our database

* our bot will capture photos to be processed by our machine learning model:  photo format i.e. `JPEG`, `PNG`


**<h1>4. Breakdown of work/Project timeline plan**</h1><br>

<br>

| Requirements                                                                                                                                                                                                                                                                                                                                 | Quarters | Assigned to: |
|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------| --- | --- |
| Req. 1: General Documentation for the product and prototyping FollowBot initial chassis.                                                                                                                                                                                                                                                     | Q1 | Frank, Igor, Trong, Joseph|
| Req. 2: Revising and polishing general documentation, developing the website, modifying the prototype with initial following mechanics for testing purposes, and beginning minor development on the mobile app.                                                                                                                              | Q2 | Frank, Igor, Trong, Joseph | 
| Req. 3: Polishing and refining FollowBot and the website, continuing development of the mobile app.Developing and evaluating machine learning models for pathfinding capabilities and object detection. Developing ability for the FollowBot to recognize simple voice commands. Developing the mapping system. Reiterating the application to include new functionalities. | Q3  |  Frank, Igor, Trong, Joseph  |   
| Req. 4: Refining the website and mobile app, strengthening security capabilities, maintaining functionality and improving following, voice recognition, and mapping mechanics. | Q4  | Frank, Igor, Trong, Joseph |
| Future: Reiterate on the website and mobile app for better user experience, and research innovative ways to integrate OpenAI technology into all FollowBot devices. Integrate inverse kinematics for the bot to handle slopes, stairs. | Q5 | Frank, Igor, Trong, Joseph |

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







