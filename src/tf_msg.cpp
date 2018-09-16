#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
#include <darknet_ros_msgs/BoundingBox.h>
#include <darknet_ros_msgs/BoundingBoxes.h>

ros::Publisher chatter_pub;

void tfCallback(const darknet_ros_msgs::BoundingBoxes::ConstPtr& msg);

int main(int argc, char **argv)
{

  ros::init(argc, argv, "tf_msg");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("/darknet_ros/bounding_boxes", 1000, tfCallback);
  chatter_pub = n.advertise<std_msgs::String>("/detection", 1000);
  ros::spin();

 
  return 0;
}

void tfCallback(const darknet_ros_msgs::BoundingBoxes::ConstPtr& msg)
{
  ros::NodeHandle n;

  ROS_INFO("I heard: [%s]", msg->bounding_boxes[0].Class.c_str());
  std_msgs::String str;
 
  str.data = msg->bounding_boxes[0].Class.c_str();

  ROS_INFO("I publish %s", str.data.c_str());
  chatter_pub.publish(str);

}
