cmake_minimum_required(VERSION 2.8.3)
project(tf_msg)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs genmsg darknet_ros_msgs)


## Generate added messages and services
generate_messages(DEPENDENCIES std_msgs)

## Declare a catkin package
catkin_package()

## Build talker and listener
include_directories(include ${catkin_INCLUDE_DIRS})


add_executable(tf_msg src/tf_msg.cpp)
target_link_libraries(tf_msg ${catkin_LIBRARIES})
add_dependencies(tf_msg tf_msg_generate_messages_cpp)
