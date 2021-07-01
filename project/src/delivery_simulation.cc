#include "delivery_simulation.h"
#include "entity_base.h"
#include "json_helper.h"
#include "drone.h"
#include "package.h"
#include "vector3D.h"
#include "composite_factory.h"
#include "drone_factory.h"
#include "package_factory.h"
#include "customer_factory.h"
#include "robot_factory.h"
#include "schedule.h"
//#include <EntityProject/graph.h>
#include <unistd.h>
#include <iostream>
namespace csci3081 {

DeliverySimulation::DeliverySimulation() {
	drone_ = NULL;
	robot_ = NULL;
	schedule_ = new Schedule();
}

DeliverySimulation::~DeliverySimulation() {
	for (int i =0;i<entities_.size(); i++){
		delete entities_[i];
	}
	delete graph_;
	delete schedule_;
}

IEntity* DeliverySimulation::CreateEntity(const picojson::object& val) {
	CompositeFactory composite;
	composite.AddFactory(new DroneFactory());
	composite.AddFactory(new PackageFactory());
	composite.AddFactory(new CustomerFactory());
	composite.AddFactory(new RobotFactory());
	IEntityFactory* factory = &composite;
	return factory->CreateEntity(val);
}

void DeliverySimulation::AddFactory(IEntityFactory* factory) {}

void DeliverySimulation::AddEntity(IEntity* entity) {
	dynamic_cast<EntityBase*> (entity) -> SetObserver(observers_);
	entities_.push_back (entity);
}

void DeliverySimulation::SetGraph(const IGraph* graph) { graph_ = graph; }

void DeliverySimulation::ScheduleDelivery(IEntity* package, IEntity* dest) {
	dynamic_cast<Package*>(package)->SetCustomer(dynamic_cast<Customer*>(dest));
	int index;
	index = schedule_ -> GetMinDistanceIndex(entities_, package);
	// if there is not available droen or robot, then push it into unScheduledPackage queue
	if(index == -2){
		unScheduledPackage.push(package);
	}
	// push the detail into the drone
	else{
		schedule_ -> ScheduleDelivery(package, dest, entities_[index], graph_);
		
	}
}

void DeliverySimulation::ScheduleRecharge(IEntity* empty) {
	
	int index;
	index = schedule_ -> GetMinRechargeDistanceIndex(entities_, empty);
	// if there is not available droen or robot, then push it into unScheduledPackage queue
	if(index!=-2){
		schedule_ -> ScheduleRecharge(empty, entities_[index], graph_);
		emptyCarriers.pop();
	}
}

void DeliverySimulation::AddObserver(IEntityObserver* observer) {
		observers_.push_back(observer);
}

void DeliverySimulation::RemoveObserver(IEntityObserver* observer) {
	observers_.erase(std::remove(observers_.begin(),observers_.end(),observer),observers_.end());
}

const std::vector<IEntity*>& DeliverySimulation::GetEntities() const { return entities_; }

void DeliverySimulation::Update(float dt) {
	for(int i = 0; i<entities_.size();i++){
  	if (JsonHelper::GetString(entities_[i]->GetDetails(), "type") == "drone"){
  		drone_ = dynamic_cast<Drone*>(entities_[i]);
  		if (drone_->IsDynamic()){
  			if (drone_->GetBattery()->IsEmpty()){
  				emptyCarriers.push(drone_); // send the package's information in the queue to the drone
  				drone_ -> dropnocharge();
  			}
  			else{
    			drone_ -> move(dt);
    		}
  		}
  		else if (!unScheduledPackage.empty() ){
  			ScheduleDelivery(unScheduledPackage.front(), dynamic_cast<Package*>(unScheduledPackage.front())->GetCustomer());
 				unScheduledPackage.pop();
  		}
  		else if (!emptyCarriers.empty() && (dynamic_cast<Drone*>(entities_[i])->GetBattery()->GetRemaining()>1000) ){
  			ScheduleRecharge(emptyCarriers.front());
 				
  		}
  	}
  	else if (JsonHelper::GetString(entities_[i]->GetDetails(), "type") == "robot"){
  		robot_ = dynamic_cast<Robot*>(entities_[i]);
			if (robot_->IsDynamic()){
				if (robot_->GetBattery()->IsEmpty()){
  				emptyCarriers.push(robot_); 
  				robot_ -> dropnocharge();
  			}
  			else{
    			robot_ -> move(dt);
    		}
			}
			else if (!unScheduledPackage.empty() ){
  			ScheduleDelivery(unScheduledPackage.front(), dynamic_cast<Package*>(unScheduledPackage.front())->GetCustomer());
 				unScheduledPackage.pop();
  		}
  	}
	}
}


// DO NOT MODIFY THE FOLLOWING UNLESS YOU REALLY KNOW WHAT YOU ARE DOING
void DeliverySimulation::RunScript(const picojson::array& script, IEntitySystem* system) const {
  JsonHelper::PrintArray(script);
  IDeliverySystem* deliverySystem = dynamic_cast<IDeliverySystem*>(system);
	if (deliverySystem) {

	    // To store the unadded entities_
	    std::vector<IEntity*> created_entities;

		for (unsigned int i=0; i < script.size(); i++) {
			const picojson::object& object = script[i].get<picojson::object>();
			const std::string cmd = object.find("command")->second.get<std::string>();
			const picojson::object& params = object.find("params")->second.get<picojson::object>();
			// May want to replace the next few if-statements with an enum
			if (cmd == "createEntity") {
				IEntity* entity = NULL;
				entity = deliverySystem->CreateEntity(params);
				if (entity) {
					created_entities.push_back(entity);
				} else {
					std::cout << "Null entity" << std::endl;
				}
			}
			else if (cmd == "addEntity") {
				int ent_index = static_cast<int>(params.find("index")->second.get<double>());
				if (ent_index >= 0 && ent_index < created_entities.size()) {
					deliverySystem->AddEntity(created_entities[ent_index]);
				}
			}
			else if (cmd == "scheduleDelivery" ) {
				int pkg_index = static_cast<int>(params.find("pkg_index")->second.get<double>());
				int dest_index = static_cast<int>(params.find("dest_index")->second.get<double>());
				if (pkg_index >= 0 && pkg_index < system->GetEntities().size()) {
					IEntity* pkg = deliverySystem->GetEntities()[pkg_index];
					if (dest_index >= 0 && pkg_index < system->GetEntities().size()) {
						IEntity* cst = system->GetEntities()[dest_index];
						if (pkg && cst) {
							deliverySystem->ScheduleDelivery(pkg, cst);
						}
					}
				}
				else {
					std::cout << "Failed to schedule delivery: invalid indexes" << std::endl;
				}
			}
		}
	}
}

}
