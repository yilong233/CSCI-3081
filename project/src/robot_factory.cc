#include "robot_factory.h"

namespace csci3081 {

  RobotFactory::RobotFactory(){}
  RobotFactory::~RobotFactory(){

  }
  // create the robot factory
  IEntity* RobotFactory::CreateEntity(const picojson::object& val){
  	if (JsonHelper::GetString(val, "type") == "robot") {
    	return new Robot(val);
  	}
  	return NULL;
  }
}
