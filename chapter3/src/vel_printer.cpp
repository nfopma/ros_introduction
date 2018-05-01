#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <stdlib.h>

// Callback function
void velocityMessageReceived(const geometry_msgs::Twist & velocityMessage ) {
  ROS_INFO_STREAM("Linear Velocity: " << velocityMessage.linear.x
<< ", Angular Velocity: " << velocityMessage.angular.z);
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "subscribe_to_velocity");
  ros::NodeHandle velocityHandle;

  ros::Subscriber velocitySubscriber = velocityHandle.subscribe("filtered_velocity", 1000, &velocityMessageReceived);
  ros::spin();
}
