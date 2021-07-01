#include "../include/drone.h"
#include "../include/smart_path.h"
#include "../include/beeline_path.h"
#include "../include/parabolic_path.h"
#include "json_helper.h"
#include <math.h>
#include <iostream>
#include <string>

namespace csci3081 {

//
Drone::Drone(const picojson::object& details) {

  position = JsonHelper::GetStdFloatVector(details, "position");
  direction = JsonHelper::GetStdFloatVector(details, "direction");
  id = count; // id should not be 1, it should be the real id. We should fix it.
  count++;

  name = JsonHelper::GetString(details, "name");
  radius = JsonHelper::GetDouble(details, "radius");
  speed = JsonHelper::GetDouble(details, "speed");
  pathToPackage = {};
  pathToCustomer = {};
  package_ = NULL;  //the pointer to the package carried by the drone
  customer_ = NULL;  //the pointer to the customer the drone go to
  empty = NULL;
  hasPackage = false;  // does the drone carry a package now
  pathToPackageIndex = 0;
  pathToCustomerIndex = 0;
  version = 0;
  dynamic = false;
  type = "drone";
  details_ = details;
  observers_ = {};
  sleep = false;
  try{
  	path = JsonHelper::GetString(details, "path");
  }
  catch(std::logic_error e){
  	path = "smart";
  }
  try{
  	float cap = JsonHelper::GetDouble(details, "battery_capacity");
  	battery = new Battery(cap);
  }
  catch(std::logic_error e){
  	battery = new Battery();
  }
}
Drone::~Drone(){
	delete strategy;
	delete battery;
}

float Drone::GetSpeed() { return speed; }

void Drone::SetSpeed(float s) { speed = s; }

vector<vector<float>> Drone::GetPathToPackage() { return pathToPackage; }
/// Set the path of drone from origin to package position.
void Drone::SetPathToPackage(vector<vector<float>> path) { pathToPackage=path; }
/// Return the path of drone from package position to customer position.
vector<vector<float>> Drone::GetPathToCustomer() { return pathToCustomer; }
/// Set the path of drone from package position to customer position.
void Drone::SetPathToCustomer(vector<vector<float>> path) { pathToCustomer=path; }
/// Return the package that drone delivers.
Package* Drone::GetPackage() { return package_; }
/// Set the package that drone delivers.
void Drone::SetPackage(Package* p) { package_ = p; }
/// Return the customer of the package.
Customer* Drone::GetCustomer() { return customer_; }
/// Set the customer of the package.
void Drone::SetCustomer(Customer* c) { customer_ = c; }
/// Return ture if drone is delivering a package.
bool Drone::IfHasPackage() { return hasPackage; }
/// Set the state of hasPackage.
void Drone::SetHasPackage(bool h) { hasPackage = h; }
/// observers for the drone.

void Drone::SetEmpty(IEntity* e){empty =e;}
IEntity* Drone::GetEmpty(){return empty;}

void Drone::NotifyForDrone(std::string value, Drone* d)
  {
    picojson::object notify;

    if(value == "moving")
    {
      // push the state value
      notify["type"] = picojson::value("notify");
      notify["value"] = picojson::value("moving");
		  if (hasPackage) {notify["path"] = JsonHelper::EncodeArray(pathToCustomer);}
		  else {notify["path"] = JsonHelper::EncodeArray(pathToPackage);}
    }

    else if(value == "idle")
    {
      notify["type"] = picojson::value("notify");
      notify["value"] = picojson::value("idle");
    }

    picojson::value event(notify);
    for (int i = 0; i < observers_.size(); i++) {
      observers_.at(i)->OnEvent(event, *d);
      }
  }

/// strategy function
vector<vector<float>> Drone::GetPath(vector<float> v1,vector<float> v2,const IGraph* graph){
	if (path == "smart"){
		strategy = new SmartPath();
	}
	else if (path == "beeline"){
		strategy = new BeelinePath();
	}
	else if (path == "parabolic"){
		strategy = new ParabolicPath();
	}
	return strategy->GetPath(v1,v2,graph);
}

Battery* Drone::GetBattery(){
	return battery;
}

void Drone::move(float time){
	if (empty != NULL){
		vector<float> nextPoint = pathToPackage[pathToPackageIndex];
    Vector3D diff = Vector3D ({nextPoint[0]-position[0],nextPoint[1]-position[1],nextPoint[2]-position[2]});
    if (diff.magnitude() > speed * time){  //check if the speed is too fast, if so move with the max speed we set.
      diff.normalize();
      direction = diff.GetVec();
      position[0] = position[0] + direction[0] * speed * time;
      position[1] = position[1] + direction[1] * speed * time;
      position[2] = position[2] + direction[2] * speed * time;

    }
    else {  // if not, move to next point that smart path suggest.
      position = nextPoint;
      pathToPackageIndex++;

      if (pathToPackageIndex == pathToPackage.size() ){ // if drone got to where the package is, pick up the package.
        
        if (JsonHelper::GetString(empty->GetDetails(), "type") == "drone"){
        	dynamic_cast<Drone*>(empty)->GetBattery()->SetRemaining(battery->GetRemaining()/2);
        	dynamic_cast<Drone*>(empty)->GetBattery()->SetEmpty(false);
        	dynamic_cast<Drone*>(empty)->NotifyForDrone("moving", dynamic_cast<Drone*>(empty));
        }
        else if (JsonHelper::GetString(empty->GetDetails(), "type") == "robot"){
        	dynamic_cast<Robot*>(empty)->GetBattery()->SetRemaining(battery->GetRemaining()/2);
        	dynamic_cast<Robot*>(empty)->GetBattery()->SetEmpty(false);
        	dynamic_cast<Robot*>(empty)->NotifyForRobot("moving", dynamic_cast<Robot*>(empty));
        }
        battery-> SetRemaining(battery->GetRemaining()/2);
        dynamic_cast<EntityBase*>(empty) -> SetDynamic(true);        
        pathToPackageIndex = 0;
  			pathToPackage = {};
  			hasPackage = false;
  			dynamic = false;
  			empty = NULL;
        NotifyForDrone("idle", this);
      }
    }
	}
  else if (!hasPackage){   // If the drone does not have a package, then it will go to where the package is.
    vector<float> nextPoint = pathToPackage[pathToPackageIndex];
    Vector3D diff = Vector3D ({nextPoint[0]-position[0],nextPoint[1]-position[1],nextPoint[2]-position[2]});
    if (diff.magnitude() > speed * time){  //check if the speed is too fast, if so move with the max speed we set.
      diff.normalize();
      direction = diff.GetVec();
      position[0] = position[0] + direction[0] * speed * time;
      position[1] = position[1] + direction[1] * speed * time;
      position[2] = position[2] + direction[2] * speed * time;

    }
    else {  // if not, move to next point that smart path suggest.
      position = nextPoint;
      pathToPackageIndex++;

      if (pathToPackageIndex == pathToPackage.size() ){ // if drone got to where the package is, pick up the package.
        hasPackage = true;
        package_ -> SetDynamic(true);
        this -> GetPackage() -> NotifyForPackage("en route" , this -> GetPackage());
        NotifyForDrone("moving", this);
      }
    }
  }
  else{  //If the drone has a package, the it will move with the package to where the customer is.
    vector<float> nextPoint = pathToCustomer[pathToCustomerIndex];
    Vector3D diff = Vector3D ({nextPoint[0]-position[0],nextPoint[1]-position[1]
                             ,nextPoint[2]-position[2]});
    if (diff.magnitude() > speed * time){
      diff.normalize();
      direction = diff.GetVec();
      position[0] = position[0] + direction[0] * speed * time;
      position[1] = position[1] + direction[1] * speed * time;
      position[2] = position[2] + direction[2] * speed * time;
      package_->SetPosition(this->position);

    }
    else {
      position = nextPoint;
      package_->SetPosition(position);
      pathToCustomerIndex++;

      if (pathToCustomerIndex == pathToCustomer.size() ){ // if drone got the where the customer is, drop the package
      	drop();
      }
    }
  }
	battery->ReduceRemaining(time);
	battery->CheckEmpty();

}

// the drone drops off the package
void Drone::drop(){
	this -> GetPackage() -> NotifyForPackage("delivered" , this -> GetPackage());
  pathToCustomerIndex = 0;
  pathToCustomer = {};
  customer_ = NULL;
  package_->SetPosition({0,0,0});
  package_ = NULL;
  pathToPackageIndex = 0;
  pathToPackage = {};
  hasPackage = false;
  dynamic = false;
  NotifyForDrone("idle", this);
}
void Drone::dropnocharge(){
  dynamic = false;
  NotifyForDrone("idle", this);
  sleep = true;
}
}
