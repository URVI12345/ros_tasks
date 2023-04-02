#include "ros/ros.h"
#include "beginner_tutorials/Fibonacci.h"

bool add(beginner_tutorials::Fibonacci::Request  &req,
         beginner_tutorials::Fibonacci::Response &res)
{
  int a=req.n;
  int n1=0;
  int n2=1;
  int ans=0;
  if (a==1) ans=0;
  else if (a==2) ans=1;
  else
  {
  for (int i=0;i<a-2;i++)
  {
          ans=n1+n2;
          n1=n2;
          n2=ans;
  }
  }
  ros::Duration(5).sleep();
  res.out=ans;
  ROS_INFO("request: x=%ld, y=%ld", (long int)req.n);
  ROS_INFO("sending back response: [%ld]", (long int)res.out);
  return true;
}
int main(int argc, char **argv)
{
  ros::init(argc, argv, "fibonacci_series_server");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("fibonacci_series", add);
  ROS_INFO("Ready to find fibonacci number");
  ros::spin();

  return 0;
}

