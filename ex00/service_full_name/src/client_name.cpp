#include "ros/ros.h"
#include "service_full_name/summ_full_name.h"
#include <cstdlib>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "client_name");
  if (argc != 4)
  {
    ROS_INFO("usage: add_two_ints_client X Y");
    return 1;
  }

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<service_full_name::summ_full_name>("summ_full_name");
  service_full_name::summ_full_name srv;
  srv.request.last_name = argv[1];
  srv.request.name = argv[2];
  srv.request.first_name = argv[3];
  if (client.call(srv))
  {
    ROS_INFO("Sum: %s", srv.response.full_name.c_str());
  }
  else
  {
    ROS_ERROR("Failed to call service add_two_ints");
    return 1;
  }

  return 0;
}
