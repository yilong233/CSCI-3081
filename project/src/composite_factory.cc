#include "composite_factory.h"

namespace csci3081 {

  CompositeFactory::CompositeFactory(){}
  CompositeFactory::~CompositeFactory(){

  }

  // create entities
  entity_project::IEntity* CompositeFactory::CreateEntity(const picojson::object& val){
  	for (int i=0; i<factories.size();i++){
  		entity_project::IEntity* entity = factories[i]->CreateEntity(val);
  		if (entity){
  			return entity;
  		}
  	}
  	return NULL;
  }

  // add factories
  void CompositeFactory::AddFactory(IEntityFactory* newFac){
  	factories.push_back (newFac);
	}
}
