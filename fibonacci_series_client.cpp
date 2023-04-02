#include "ros/ros.h"
#include "beginner_tutorials/Fibonacci.h"
#include <cstdlib>
#include "std_msgs/Int64.h"

void chatterCallback(const std_msgs::Int64::ConstPtr& msg)
{
  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<beginner_tutorials::Fibonacci>("fibonacci_series");
  beginner_tutorials::Fibonacci srv;
  srv.request.n = msg->data;
  if (client.call(srv))
  {
    ROS_INFO("Num: %ld", (long int)srv.response.out);
   ros::Publisher fibonacci_pub = n.advertise<std_msgs::Int64>("fibonacci_output", 1000);
long int res = (long int)srv.response.out;
while (ros::ok())
{
     std_msgs::Int64 int_msg;
      int_msg.data = res;
      ROS_INFO("%ld",int_msg.data);
      fibonacci_pub.publish(int_msg);
      ros::spinOnce();}
      }
  else
  {
    ROS_ERROR("Failed to call service fibonacci_series");
  }
return;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "fibonacci_series_client");
  if ( argc != 1)
  {
  ROS_INFO("usage: fibonacci_series_client X Y");
  return 1;
  }
  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("fibonacci_input", 1000, chatterCallback);
  ros::ServiceClient fibonacci_client = n.serviceClient<beginner_tutorials::Fibonacci>("fibonacci_series");

  beginner_tutorials::Fibonacci srv;
  ros::spin();
  
 return 0;
}
