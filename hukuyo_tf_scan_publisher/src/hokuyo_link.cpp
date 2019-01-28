#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <tf/transform_datatypes.h>



int main(int argc, char** argv){
  ros::init(argc, argv, "hukuyo_tf_scan_publisher");
  ros::NodeHandle node;

 while (node.ok()){

  static tf::TransformBroadcaster br;


  tf::Transform transform;
  transform.setOrigin(tf::Vector3(0,0,0));
  tf::Quaternion q;
  q.setRPY(0, 0, 0); // Applying a quaternion rotation 
  transform.setRotation(q);
  br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "map", "laser"));

}


};
