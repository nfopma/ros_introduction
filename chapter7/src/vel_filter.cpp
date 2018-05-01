# include <ros/ros.h>
# include <geometry_msgs/Twist.h>


class VelocityFilter
{
public:
  VelocityFilter(ros::NodeHandle& nh)
    : velocity_sub_(nh.subscribe("turtle1/cmd_vel", 10, &VelocityFilter::filter, this)),
      velocity_pub_(nh.advertise<geometry_msgs::Twist>("filtered_velocity", 10))
  {
    max_ang_vel_loaded = ros::param::get("~max_vel", max_ang_vel);
  }

  void filter(const geometry_msgs::Twist& velocity_cmd)
  {
    if(!max_ang_vel_loaded)
    {
      ROS_FATAL_STREAM("Maximum Angular Velocity NOT LOADED");
    } else
    if(velocity_cmd.angular.z < max_ang_vel)
    {
      velocity_pub_.publish(velocity_cmd);
    }
  }

private:
  ros::Subscriber velocity_sub_;
  ros::Publisher velocity_pub_;
  double max_ang_vel;
  bool max_ang_vel_loaded;
};

int main(int argc, char** argv)
{
  ros::init(argc, argv, "filtered_angular_velocity");
  ros::NodeHandle nh;
  VelocityFilter filter(nh);

  ros::spin();
}
