#include "ros/ros.h"
#include "beginner_tutorials/task2.h"
#include <cstdlib>
#include "std_msgs/Int64.h"

void ChatterCallBack(const std_msgs::Int64::ConstPtr& msg)
{
	ros::NodeHandle n;
	ros::ServiceClient task_client = n.serviceClient<beginner_tutorials::task2>("displacement");
	beginner_tutorials::task2 srv;
	srv.request.x = msg->data;
	if (task_client.call(srv))
	{
	ros::Publisher pub = n.advertise<std_msgs::Int64>("setpoint", 1000);
	long int res = (long int)srv.response.d;
while (ros::ok())
{
     std_msgs::Int64 int_msg;
      int_msg.data = res;
      ROS_INFO("%ld",int_msg.data);
      pub.publish(int_msg);
      ros::spinOnce();
      }
}
  else
  {
    ROS_ERROR("Failed to call service displacement");
  }
return;
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "disp_client");
	ros::NodeHandle n;

	ros::Subscriber sub = n.subscribe("set_points",1000, ChatterCallBack);
	ros::ServiceClient client = n.serviceClient<beginner_tutorials::task2>("displacement");

	beginner_tutorials::task2 srv;
	ros::spin();

	return 0;
}
