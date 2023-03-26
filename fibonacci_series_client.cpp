#include "ros/ros.h"
#include "beginner_tutorials/Fibonacci.h"
#include <cstdlib>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "fibonacci_series_client");
  if (argc != 2)
  {
    ROS_INFO("usage: fibonacci_series_client X Y");
    return 1;
  }
  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<beginner_tutorials::Fibonacci>("fibonacci_series");
  beginner_tutorials::Fibonacci srv;
  srv.request.n = atoll(argv[1]);
  if (client.call(srv))
  {
    ROS_INFO("Num: %ld", (long int)srv.response.out);
  }
  else
  {
    ROS_ERROR("Failed to call service fibonacci_series");
    return 1;
  }

  return 0;
}
