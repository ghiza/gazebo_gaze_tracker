#ifndef CYLINDER_CONTROLLER_HH
#define CYLINDER_CONTROLLER_HH

#include <gazebo/gazebo.hh>
#include <gazebo/physics/PhysicsIface.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo/transport/TransportIface.hh>
#include <gazebo/msgs/msgs.hh>

namespace gazebo
{
	class CylinderController: public WorldPlugin
	{
	public: void Load(physics::WorldPtr _parent, sdf::ElementPtr /*_sdf*/);

	public: void Init();

	public: void OnUpdate();

	public: void SubscribeToGazeTopic();

	public: void callback(const boost::shared_ptr<const gazebo::msgs::Pose> &_msg);

	private: gazebo::transport::NodePtr node;

	private: gazebo::transport::SubscriberPtr poseSub;

	private: physics::ModelPtr gazeCylinder;

	private: math::Pose newPose;

	private: math::Vector3 cylinderPosition;

	private: math::Quaternion cylinderOrientation;

	private: event::ConnectionPtr updateConnection;
	};
}

#endif
