# Important commands/information for ROS2 (Linux)

<h2>Starting from personal PC</h2>

When starting the ROS2 you will need to ssh into the raspberry pi from a personal pc via this command
```
ssh ubuntu@10.0.0.252
```
when enabling X11 do this command:
```
ssh -X ubuntu@10.0.0.252
```

Doing this will then give you a prompt for the password to the pi, the password is: robotics101
<h2>Sourcing the setup files: </h2>  

```
source /opt/ros/foxy/setup.bash
```

**(optional/necessary)** adding to sheet startup script: (Note: if need to remove, locate startup script file)
```
echo "source /opt/ros/foxy/setup.bash" >> ~/.bashrc
```

<h2> Check environment variables </h2>

```
printenv | grep -i ROS
```

When doing this you should see the following:

```
ROS_VERSION=2
ROS_PYTHON_VERSION=3
ROS_DISTRO=foxy
```


The `ROS_DOMAIN_ID` variable:

```
export ROS_DOMAIN_ID=<your_domain_id>
```
When it comes to the ID its specified to keep things in the range between 0 and 101 inclusivly. 

**(optional/necessary)** Adding to sheet to startup script: (Note: if need to remove, locate startup script file)
```
echo " export ROS_DOMAIN_ID=<your_domain_id>" >> ~/.bashrc
```

The `ROS_LOCALHOST_ONLY` variable:  
```
export ROS_LOCALHOST_ONLY=1
```
This variable allows you to limit the ROS 2 communication to localhost only. This means your ROS 2 system, and its topics, services, and actions will not be visible to other computers on the local network.

**(optional/necessary)** Adding to sheet to startup script: (Note: if need to remove, locate startup script file)

```
echo "export ROS_LOCALHOST_ONLY=1" >> ~/.bashrc
```

<h3>Note: </h3>

When needing to remove a given command within .bashrc you will need to go into that file via these commands:

```
#for locating the file
ls -a

#for entering into the file
vi .bashrc
```

Important commands when editing a file:

```
i: for inserting

esc: for getting out of inserting

Shift ZZ: for saving the file and quickly exiting out of the file

:q! -> for exiting the file without saving
```

<h1> Important for using TurtleSim </h1>

Turtlesim is a visual platform that is used for testing purposes when you want to see visually what will happen with your robot. The issue though when using turtlesim is that it requires you to have a pre installed GUI that can be used between your current machine and your ubuntu machine running on your Raspberry pi. Thus meaning you need to make sure you have a gui installed. Follow these instructions on this site in order to gain the prerequisites for setting up the turtlesim correctly:
https://docs.ros.org/en/foxy/Tutorials/Beginner-CLI-Tools/Introducing-Turtlesim/Introducing-Turtlesim.html

If you reached this point in the tutorial, and obtained the error instead of the screen then this is where I tell you in how to fix the issue:

```
#When running this you will either obtain a message or the display screen with the turtle:
ros2 run turtlesim turtlesim_node
```
Now how will you fix this issue you may ask? Well the simple answer is that you need to install a GUI for the Windows SubSystem of Linux since Linux doesn't have a built in version. You will need to download Xming or VcXsrv

I downloaded Xming so here is the site to it:
http://www.straightrunning.com/XmingNotes/

once you have that installed you will need to open it, it will be called Xlaunch. Click `next` till you reach *extra settings*. When your in extra settings click `Disable access control`, this will allow you access to use Xming from any machine/client which is necessary for running any type of visual software on your ubuntu machine through your windows machine.

after accomplishing this you will then need to go into your ubuntu machine, when inside you will need to open your `.bashrc` file when inside you will need to include this:

```
#Display for running any visual client and other forms of software
export DISPLAY=YOUR_IP_ADDRESS_ON_CURRENT_MACHINE:0

#Example
export Display=10.0.0.245:0  #No spaces
```

once you have accomplished this save the file and exit it, restart your environment by closing out and reopening the command prompt and sshing again. 

Now without any further a due rerun the specific turtlesim line above to see the turtle on the screen. You will be amazed by its gracefulness.


<h2>Testing TurtleSim </h2>
now to test if turtle sim is working correctly, you will need to input this same command in one terminal:

```
ros2 run turtlesim turtlesim_node
```

then in a seperate terminal you will need to input this command:
```
ros2 run turtlesim turtle_teleop_key
```

When doing this it will allow you to control the terminal within the display window with the arrow keys when currently in the terminal where you inputted that command.
