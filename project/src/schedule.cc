#include "../include/schedule.h"
#include "json_helper.h"
#include <math.h>
#include <iostream>
//#include "entity_base.h"
//#include "battery.h"
#include "customer.h"
#include "drone.h"
#include "robot.h"
#include "package.h"
#include "vector3D.h"
//#include <EntityProject/graph.h>
#include <vector>
#include <string>

namespace csci3081 {

	Schedule::Schedule(){}
	Schedule::~Schedule(){}
	// return the smart path
	int Schedule::GetMinDistanceIndex(std::vector<IEntity*> entities_, IEntity* package){
		
		int index = -2;
		float minDistance = 100000000;
		float distance;
		for(int i = 0; i<entities_.size();i++){
			if (JsonHelper::GetString(entities_[i]->GetDetails(), "type") == "drone"        // choose drone and the robot entities
			 || JsonHelper::GetString(entities_[i]->GetDetails(), "type") == "robot"){
				// judge whether the drone or the robot is dynamic and is not sleep
			 	if (entities_[i]->IsDynamic() == false&&  dynamic_cast<EntityBase*>( entities_[i])->IsSleep() == false){

			 // push the value
			 	std::vector<float> packagePosition = package->GetPosition();
			 	std::vector<float> entityPosition = entities_[i]->GetPosition();
			 	Vector3D diff = Vector3D ({packagePosition[0]-entityPosition[0],packagePosition[1]-entityPosition[1],packagePosition[2]-entityPosition[2]});
				distance = diff.magnitude();

				if ( distance < minDistance ){
					minDistance = distance;
					index = i;
				}
				}
			}
		}
		return index;
	}
	int Schedule::GetMinRechargeDistanceIndex(std::vector<IEntity*> entities_, IEntity* empty){
		
		int index = -2;
		float minDistance = 100000000;
		float distance;
		for(int i = 0; i<entities_.size();i++){
			if (JsonHelper::GetString(entities_[i]->GetDetails(), "type") == "drone"){
				// judge whether the drone or the robot is dynamic and is not sleep
				
			 	if (entities_[i]->IsDynamic() == false &&  dynamic_cast<EntityBase*>( entities_[i])->IsSleep() == false&&   (dynamic_cast<Drone*>(entities_[i])->GetBattery()->GetRemaining()>1000)){

			 // push the value
			 	std::vector<float> emptyPosition = empty->GetPosition();
			 	std::vector<float> entityPosition = entities_[i]->GetPosition();
			 	Vector3D diff = Vector3D ({emptyPosition[0]-entityPosition[0],emptyPosition[1]-entityPosition[1],emptyPosition[2]-entityPosition[2]});
				distance = diff.magnitude();

				if ( distance < minDistance ){
					minDistance = distance;
					index = i;
				}
				}
			}
		}
		return index;
	}
	void Schedule::ScheduleDelivery(IEntity* package, IEntity* dest, IEntity* tran, const IGraph* graph_){
		if (JsonHelper::GetString(tran->GetDetails(), "type") == "drone"){
			Drone* drone_ = dynamic_cast<Drone*>(tran);
		  if (drone_->IsDynamic() == false ){
				drone_ -> SetDynamic(true);
				drone_ -> SetPackage(dynamic_cast<Package*>(package));
				drone_ -> SetCustomer(dynamic_cast<Customer*>(dest));
				drone_ -> SetPathToPackage(drone_->GetPath(drone_->GetPosition(),package->GetPosition(),graph_));
				drone_ -> SetPathToCustomer(drone_->GetPath(package->GetPosition(),dest->GetPosition(),graph_));
				drone_ -> GetPackage() -> NotifyForPackage("scheduled" , drone_ -> GetPackage());
				drone_ -> NotifyForDrone("moving", drone_);
		  }
		}

		// push the detail into the robot
		else if (JsonHelper::GetString(tran->GetDetails(), "type") == "robot"){
		  Robot* robot_ = dynamic_cast<Robot*>(tran);
		  if (robot_->IsDynamic() == false){
				robot_ -> SetDynamic(true);
				robot_ -> SetPackage(dynamic_cast<Package*>(package));
				robot_ -> SetCustomer(dynamic_cast<Customer*>(dest));
				robot_ -> SetPathToPackage(graph_->GetPath(robot_->GetPosition(),package->GetPosition()));
				robot_ -> SetPathToCustomer(graph_->GetPath(package->GetPosition(),dest->GetPosition()));
				robot_ -> GetPackage() -> NotifyForPackage("scheduled" , robot_ -> GetPackage());
				robot_ -> NotifyForRobot("moving", robot_);
		  }
		}
	}
	void Schedule::ScheduleRecharge(IEntity* empty, IEntity* tran, const IGraph* graph_){
		
			Drone* drone_ = dynamic_cast<Drone*>(tran);
			
		  if (drone_->IsDynamic() == false ){
				drone_ -> SetDynamic(true);
				drone_ -> SetSleep(false);
				drone_ -> SetEmpty(empty);
				drone_ -> SetPathToPackage(drone_->GetPath(drone_->GetPosition(),empty->GetPosition(),graph_));
				drone_ -> NotifyForDrone("moving", drone_);
		  }
	}

		  
		
	
}
