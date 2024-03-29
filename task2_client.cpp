#include "ros/ros.h"
#include "beginner_tutorials/task2.h"
#include <cstdlib>
#include "std_msgs/Int64.h"

int main(int argc, char **argv)
{
	ros::init(argc, argv, "disp_client");
	ros::NodeHandle n;
	ros::ServiceClient client = n.serviceClient<beginner_tutorials::task2>("task2_server");
	beginner_tutorials::task2 srv;
	for (const auto& coord : config) {
    long int x = coord["x"].as<long int>();
    long int y = coord["y"].as<long int>();
    long int z = coord["z"].as<long int>();
	beginner_tutorials::task2 srv;
    srv.request.x = x;
    srv.request.y = y;
    srv.request.z = z;
    if (client.call(srv)) {
      ROS_INFO("setpoints %ld, %ld, %ld ...",x,y,z);
    }
    else {
      ROS_ERROR("Failed to call service task2_server");
      return 1;
    }
  }
	
	ros::spin();

	return 0;
}
