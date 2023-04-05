#include "ros/ros.h"
#include "beginner_tutorials/task2.h"
#include <cmath>
//service
bool disp(beginner_tutorials::task2::Request  &req,
         beginner_tutorials::task2::Response &res, int &x1,int &y1,int &z1)
{
int x2= req.x;
int y2= req.y;
int z2= req.z;
int disp= abs(x2-x1) + abs(y2-y1) + abs(z2-z1);
int time= disp;
x1= x2;
y1= y2;
z1= z2;
ros::Duration(time).sleep();
ROS_INFO ("setpoint %ld, %ld, %ld attained", (long int)req.n);
}
int main(int argc, char **argv)
{
  ros::init(argc, argv, "task2_server");
  ros::NodeHandle n;

  int x1=0;
  int y1=0;
  int z1=0;
  ros::ServiceServer service = n.advertiseService("task2",disp(x1,y1,z1);
  ROS_INFO("calculating displacement...");
  ros::spin();

  return 0;
}

