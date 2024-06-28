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