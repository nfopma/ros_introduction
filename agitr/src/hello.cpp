// ROS version of "Hello, world" program. 

#include <ros/ros.h>

int main(int argc, char **argv) {

	// Initialize the ROS system. 
	ros::init(argc, argv, "hello_ros");

	// Establish this program as a ROS node. 
	ros::NodeHandle nh;

	ROS_INFO_STREAM("HELLO, ROS!");
}

