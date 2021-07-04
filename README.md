# ROS ArmRobotCar pkg
6dof Arm Robot Car is my final project assignment for my embedded system college course. 
It is an instrument that can pick up, move and put items from one position to another, 
This device has actuators, namely 4 DC motors to move places and a 6dof robot arm to move 
objects consisting of 6 servo motors connected on frames. Unlike the existing robotic arm, 
controlling this instrument is done using an Arduino microcontroller and a Single Board Computer 
(SBC) NVIDIA Jetson Nano. The addition of the SBC component makes the instrument controllable 
via joystick input media by connecting SBC and Arduino using the rosserial_arduino communication 
protocol in the Robot Operating System (ROS) framework. This connection also allows the instrument 
to experience additional features such as wireless remote control and the addition of a camera 
component for remote monitoring features. 
![alt text](https://github.com/hnslmp/armrobotcar_ros/blob/master/documents/Armrobotcar.png)   
 
## Explanation Video in Bahasa Indonesia
ROS ArmRobotCar explanation video for my embedded system final project assignment:  
https://youtu.be/bmdtt4ihS68

## Dependencies 
* joy, http://wiki.ros.org/joy  
* rosserial_arduino, http://wiki.ros.org/rosserial_arduino
* cv_bridge, http://wiki.ros.org/cv_bridge
* OpenCV 4.5.2, https://docs.opencv.org/4.5.2/
* Tkinter
* PIL 

## Features
* Manual Move
* Controller Move
* Save Point
* Move to Save Point
* Dc Motor

## Joystick Layout
![alt text](https://github.com/hnslmp/armrobotcar_ros/blob/master/documents/Joystick%20Layout.png)    

## Microcontroller Schematic
![alt text](https://github.com/hnslmp/armrobotcar_ros/blob/master/documents/Schematic.png)    

## Hardware 
Hardware list : 
https://github.com/hnslmp/armrobotcar_ros/blob/master/documents/Component%20List.csv

Total Cost: Approx 260 USD  

Date: 07/04/2021  
