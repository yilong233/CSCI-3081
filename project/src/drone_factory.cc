#include "drone_factory.h"

namespace csci3081 {

  DroneFactory::DroneFactory(){}
  DroneFactory::~DroneFactory(){

  }

  // create drone factory
  IEntity* DroneFactory::CreateEntity(const picojson::object& val){
  	if (JsonHelper::GetString(val, "type") == "drone") {
    	return new Drone(val);
  	}
  	return NULL;
  }
}
