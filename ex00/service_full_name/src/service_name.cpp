#include "ros/ros.h"
#include "service_full_name/summ_full_name.h"

bool add(service_full_name::summ_full_name::Request  &req,
         service_full_name::summ_full_name::Response &res)
{
 res.full_name = std::string(req.last_name) + req.name + req.first_name;
  ROS_INFO("request: x=%s, y=%s name=%s", req.last_name.c_str(), req.name.c_str(), req.first_name.c_str());
  ROS_INFO("sending back response: [%s]", res.full_name.c_str());
  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "service_name");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("summ_full_name", add);
  ROS_INFO("Ready to add two ints.");
  ros::spin();

  return 0;
}
