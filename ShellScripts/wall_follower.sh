#!/bin/sh
xterm -e " roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=/home/workspace/catkin_ws/src/World/udacious.world " &
sleep 5
xterm -e " rosrun gmapping slam_gmapping scan:=scan " &
sleep 5
xterm -e " roslaunch turtlebot_rviz_launchers view_navigation.launch " &
sleep 5
xterm -e " rosrun wall_follower wall_follower "
