# include <ros/ros.h>
# include <geometry_msgs/Twist.h>
# include <std_srvs/Empty.h>


class VelocityFilter
{
public:
  VelocityFilter(ros::NodeHandle& nh)
    : velocity_sub_(nh.subscribe("turtle1/cmd_vel", 10, &VelocityFilter::filter, this)),
      velocity_pub_(nh.advertise<geometry_msgs::Twist>("filtered_velocity", 10)),
      filter_switch_serv_(nh.advertiseService("filter_switch", &VelocityFilter::filter_switch, this)),
      filter_switched_on_("true")
  {
    max_ang_vel_loaded_ = ros::param::get("~max_vel", max_ang_vel_);
  }

  void filter(const geometry_msgs::Twist& velocity_cmd)
  {
    if(filter_switched_on_)
    {
      if(!max_ang_vel_loaded_)
      {
        ROS_FATAL_STREAM("Maximum Angular Velocity NOT LOADED");
      } else if(velocity_cmd.angular.z < max_ang_vel_)
      {
        velocity_pub_.publish(velocity_cmd);
      }
    } else
    {
      velocity_pub_.publish(velocity_cmd);
    }
  }

  bool filter_switch(std_srvs::Empty::Request &req, std_srvs::Empty::Response &resp)
  {
    filter_switched_on_ = !filter_switched_on_;
  }

private:
  ros::Subscriber velocity_sub_;
  ros::Publisher velocity_pub_;
  ros::ServiceServer filter_switch_serv_;

  bool filter_switched_on_;
  double max_ang_vel_;
  bool max_ang_vel_loaded_;
};

int main(int argc, char** argv)
{
  ros::init(argc, argv, "filtered_angular_velocity");
  ros::NodeHandle nh;
  VelocityFilter filter(nh);

  ros::spin();
}
