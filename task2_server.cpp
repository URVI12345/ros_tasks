#include "ros/ros.h"
#include "beginner_tutorials/task2.h"
#include "beginner_tutorials/sleep.h"
#include <cmath>
class displacement{
public:
  double disp(beginner_tutorials::task2::Request  &req,
         beginner_tutorials::task2::Response &res)
{
        ros::NodeHandle n;
        ros::ServiceClient client = n.serviceClient<beginner_tutorials::task2>("sleep_server");
int x2= req.x;
int y2= req.y;
int z2= req.z;
disp_x=abs(x2-x1);
disp_y=abs(y2-y1);
disp_z=abs(z2-z1);
double disp=disp_x+disp_y+disp_z;
beginner_tutorials::sleep srv;
srv.request.disp= disp;
if (client.call(srv)) {
      ROS_INFO("achieving displacement...");
    }
    else {
      ROS_ERROR("Failed to call service sleep_server");
      return 1;
    }
    ros::ServiceServer S1 = n.advertiseService("task2",sleep);
    ros::spin();
}
bool sleep(beginner_tutorials::sleep::Request  &req,
         beginner_tutorials::sleep::Response &res)
{
        float time = req.disp;
         ros::Duration(time).sleep();
ROS_INFO ("setpoint %ld, %ld, %ld attained", (long int)req.n);
return 0;
}
private:
	int x1=0;
	int y1=0;
	int z1=0;
	int disp_x=0;
	int disp_y=0;
	int disp_z=0;
};
int main(int argc, char **argv)
{
  ros::init(argc, argv, "task2_server");
  displacement d1;
  ros::NodeHandle n;
  ros::ServiceServer service = n.advertiseService("task2",disp);
  ROS_INFO("calculating displacement...");
  ros::spin();
  return 0;
}
