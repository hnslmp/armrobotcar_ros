#include <iostream>
#include <ros/ros.h>
#include <sensor_msgs/Joy.h>
#include <std_msgs/UInt16.h>

using namespace std;

ros::Publisher joy_publisher;

void joyCallback(const sensor_msgs::Joy::ConstPtr& msg){
  //Robot Arm
  if(msg->axes[6] == 1){
    std_msgs::UInt16 msg;
    msg.data = 0;
    joy_publisher.publish(msg);
    ROS_INFO("0");
  }
  else if(msg->axes[6] == -1){
    std_msgs::UInt16 msg;
    msg.data = 1;
    joy_publisher.publish(msg);
    ROS_INFO("1");
  }
  else if(msg->axes[7] == 1){
    std_msgs::UInt16 msg;
    msg.data = 2;
    joy_publisher.publish(msg);
    ROS_INFO("2");
  }
  else if(msg->axes[7] == -1){
    std_msgs::UInt16 msg;
    msg.data = 3;
    joy_publisher.publish(msg);
    ROS_INFO("3");
  }
  else if(msg->buttons[3] == 1){
    std_msgs::UInt16 msg;
    msg.data = 4;
    joy_publisher.publish(msg);
    ROS_INFO("4");
  }
  else if(msg->buttons[0] == 1){
    std_msgs::UInt16 msg;
    msg.data = 5;
    joy_publisher.publish(msg);
    ROS_INFO("5");
  }
  else if(msg->buttons[2] == 1){
    std_msgs::UInt16 msg;
    msg.data = 6;
    joy_publisher.publish(msg);
    ROS_INFO("6");
  }
  else if(msg->buttons[1] == 1){
    std_msgs::UInt16 msg;
    msg.data = 7;
    joy_publisher.publish(msg);
    ROS_INFO("7");
  }
  else if(msg->buttons[4] == 1){
    std_msgs::UInt16 msg;
    msg.data = 8;
    joy_publisher.publish(msg);
    ROS_INFO("8");
  }
  else if(msg->buttons[5] == 1){
    std_msgs::UInt16 msg;
    msg.data = 9;
    joy_publisher.publish(msg);
    ROS_INFO("9");
  }
  else if(msg->axes[5] == -1){
    std_msgs::UInt16 msg;
    msg.data = 10;
    joy_publisher.publish(msg);
    ROS_INFO("10");
  }
  else if(msg->axes[2] == -1){
    std_msgs::UInt16 msg;
    msg.data = 11;
    joy_publisher.publish(msg);
    ROS_INFO("11");
  }

  //Car Motor
  else if(msg->axes[1] == 1){
    std_msgs::UInt16 msg;
    msg.data = 12;
    joy_publisher.publish(msg);
    ROS_INFO("12");
  }
  else if(msg->axes[1] == -1){
    std_msgs::UInt16 msg;
    msg.data = 13;
    joy_publisher.publish(msg);
    ROS_INFO("13");
  }
  else if(msg->axes[0] == -1){
    std_msgs::UInt16 msg;
    msg.data = 14;
    joy_publisher.publish(msg);
    ROS_INFO("14");
  }
  else if(msg->axes[0] == 1){
    std_msgs::UInt16 msg;
    msg.data = 15;
    joy_publisher.publish(msg);
    ROS_INFO("15");
  }

  //Move Button
  else if(msg->buttons[9] == 1){
    std_msgs::UInt16 msg;
    msg.data = 16;
    joy_publisher.publish(msg);
    ROS_INFO("16");
  }
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "joycontrol");
    ros::NodeHandle nh;
    joy_publisher = nh.advertise<std_msgs::UInt16>("joycontrol", 8);
    ros::Subscriber joy_subscriber = nh.subscribe("joy", 8, joyCallback);
    ros::spin();
}
