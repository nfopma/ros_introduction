#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  ros::init(argc, argv, "publish_velocity");
  ros::NodeHandle nh;


  // Create the publisher object
  ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 1000);

  // Seed the random nr generator
  srand(time(0));

  // Publishing Loop
  ros::Rate rate(2); // Helpful for timed breaks in the while loop! In the normal case, the node would subscribe to the clock I think to specify this variable.
  while(ros::ok()) {
    geometry_msgs::Twist msg;
    msg.linear.x = double(rand())/double(RAND_MAX);
    msg.angular.z = 2*double(rand())/double(RAND_MAX) - 1;

    // Publish the message
    pub.publish(msg);

    // Send message to rosout
    ROS_INFO_STREAM("Sending random velocity command:"<< " linear=" << msg.linear.x << " angular=" << msg.angular.z);

    // Use ros::Rate object to continue with the next loop after exactly .5 seconds
    rate.sleep();
  }
}
