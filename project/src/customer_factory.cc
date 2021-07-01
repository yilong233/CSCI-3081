#include "customer_factory.h"

namespace csci3081 {

  CustomerFactory::CustomerFactory(){}
  CustomerFactory::~CustomerFactory(){

  }

  // create customer factory
  IEntity* CustomerFactory::CreateEntity(const picojson::object& val){
  	if (JsonHelper::GetString(val, "type") == "customer") {
    	return new Customer(val);
  	}
  	return NULL;
  }
}
