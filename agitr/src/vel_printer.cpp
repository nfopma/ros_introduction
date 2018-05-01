#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <stdlib.h>

// Callback function
void velocityMessageReceived(const geometry_msgs::Twist & velocityMessage ) {
  ROS_INFO_STREAM("Linear Velocity: " << velocityMessage.linear.x
<< ", Angular Velocity: " << velocityMessage.angular.z);
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "vel_printer");
  ros::NodeHandle velocityHandle;

  ros::Subscriber velocitySubscriber = velocityHandle.subscribe("turtle1/cmd_vel", 1000, &velocityMessageReceived);
  ros::spin();
}
