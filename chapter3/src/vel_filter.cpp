#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <stdlib.h>

class VelocityCmdManipulator
{
public:
  VelocityCmdManipulator(ros::NodeHandle& nh)
    : filter_count_(0)
    , velocity_pub_(nh.advertise<geometry_msgs::Twist>("filtered_velocity", 1000))
    , velocity_sub_(nh.subscribe("turtle1/cmd_vel",1000, &VelocityCmdManipulator::filter, this))
  {}


  void filter(const geometry_msgs::Twist& velocity_cmd)
  {
    ROS_INFO_STREAM("velocityListener::callback is being called, angular velocity: " << velocity_cmd.angular.z);
    if(velocity_cmd.angular.z >= 0)
    {
      velocity_pub_.publish(velocity_cmd);
    }
    else
    {
      filter_count_++;
    }
  }

  int filter_count_;
  ros::Publisher velocity_pub_;
  ros::Subscriber velocity_sub_;
};

int main(int argc, char**argv)
{
  ros::init(argc, argv, "vel_filter");
  ros::NodeHandle nh;

  VelocityCmdManipulator filter(nh);

  ros::Rate rate(10);

  while(ros::ok())
  {
    ROS_INFO_STREAM_THROTTLE(5, "Data dropped: " << filter.filter_count_);
    rate.sleep();
    ros::spinOnce();
  }

}
