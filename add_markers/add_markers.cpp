#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include "nav_msgs/Odometry.h"

ros::Subscriber odom_subscriber;
ros::Publisher marker_pub;
visualization_msgs::Marker marker;
bool item_picked_up = false;

void odom_callback(const nav_msgs::Odometry::ConstPtr& msg){
  float x = msg->pose.pose.position.x;
  float y = msg->pose.pose.position.y;

  if(!item_picked_up && fabs(x - 6.0) <= 0.5 && fabs(y + 6.0) <= 0.5){
    marker.action = visualization_msgs::Marker::DELETE;
    marker_pub.publish(marker);
    item_picked_up = true;
  } else if(item_picked_up && fabs(x - 5.7) < 0.5 && fabs(y - 0.9) < 0.5){
    marker.action = visualization_msgs::Marker::ADD;
    marker.pose.position.x = 5.7;
    marker.pose.position.y = 0.9;
    marker_pub.publish(marker);
  }
}

int main( int argc, char** argv )
{
  ros::init(argc, argv, "add_markers");
  ros::NodeHandle n;
  ros::Rate r(1);
  marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);

  // Set our initial shape type to be a cube
  uint32_t shape = visualization_msgs::Marker::CUBE;
  // Set the frame ID and timestamp.  See the TF tutorials for information on these.
  marker.header.frame_id = "/map";
  marker.header.stamp = ros::Time::now();

  // Set the namespace and id for this marker.  This serves to create a unique ID
  // Any marker sent with the same namespace and id will overwrite the old one
  marker.ns = "pickup_item";
  marker.id = 0;

  // Set the marker type.  Initially this is CUBE, and cycles between that and SPHERE, ARROW, and CYLINDER
  marker.type = shape;

  // Set the marker action.  Options are ADD, DELETE, and new in ROS Indigo: 3 (DELETEALL)
  marker.action = visualization_msgs::Marker::ADD;

  // Set the pose of the marker.  This is a full 6DOF pose relative to the frame/time specified in the header
  marker.pose.position.x = 6.0;
  marker.pose.position.y = -6.0;
  marker.pose.position.z = 0;
  marker.pose.orientation.x = 0.0;
  marker.pose.orientation.y = 0.0;
  marker.pose.orientation.z = 0.0;
  marker.pose.orientation.w = 1.0;

  // Set the scale of the marker -- 1x1x1 here means 1m on a side
  marker.scale.x = 0.5;
  marker.scale.y = 0.5;
  marker.scale.z = 0.5;

  // Set the color -- be sure to set alpha to something non-zero!
  marker.color.r = 0.0f;
  marker.color.g = 1.0f;
  marker.color.b = 0.0f;
  marker.color.a = 1.0;

  marker.lifetime = ros::Duration();
  while (marker_pub.getNumSubscribers() < 1)
  {
    if (!ros::ok())
    {
      return 0;
    }
    ROS_WARN_ONCE("Please create a subscriber to the marker");
    sleep(1);
  }
  marker_pub.publish(marker);

  odom_subscriber = n.subscribe("/odom", 1000, odom_callback);

  ros::spin();

  return 0;
}
