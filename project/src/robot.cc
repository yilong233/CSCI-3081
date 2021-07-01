#include "../include/robot.h"
#include "json_helper.h"
#include <math.h>
namespace csci3081 {

//
Robot::Robot(const picojson::object& details) {

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
  hasPackage = false;  // does the drone carry a package now
  pathToPackageIndex = 0;
  pathToCustomerIndex = 0;
  version = 0;
  dynamic = false;
  type = "robot";
  details_ = details;
  sleep = false;
  try{
  	float cap = JsonHelper::GetDouble(details, "battery_capacity");
  	battery = new Battery(cap);
  }
  catch(std::logic_error e){
  	battery = new Battery();
  }

}
Robot::~Robot(){
	delete battery;
}


float Robot::GetSpeed() { return speed; }

void Robot::SetSpeed(float s) { speed = s; }

vector<vector<float>> Robot::GetPathToPackage() { return pathToPackage; }
/// Set the path of drone from origin to package position.
void Robot::SetPathToPackage(vector<vector<float>> path) { pathToPackage=path; }
/// Return the path of drone from package position to customer position.
vector<vector<float>> Robot::GetPathToCustomer() { return pathToCustomer; }
/// Set the path of drone from package position to customer position.
void Robot::SetPathToCustomer(vector<vector<float>> path) { pathToCustomer=path; }
/// Return the package that drone delivers.
Package* Robot::GetPackage() { return package_; }
/// Set the package that drone delivers.
void Robot::SetPackage(Package* p) { package_ = p; }
/// Return the customer of the package.
Customer* Robot::GetCustomer() { return customer_; }
/// Set the customer of the package.
void Robot::SetCustomer(Customer* c) { customer_ = c; }
/// Return ture if drone is delivering a package.
bool Robot::IfHasPackage() { return hasPackage; }
/// Set the state of hasPackage.
void Robot::SetHasPackager(bool h) { hasPackage = h; }
/// observers for the robots.
void Robot::NotifyForRobot(std::string value, Robot* d)
  {
    picojson::object notify;

    if(value == "moving")
    {
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

Battery* Robot::GetBattery(){
	return battery;
}


void Robot::move(float time){
  if (!hasPackage){   // If the drone does not have a package, then it will go to where the package is.
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
        NotifyForRobot("moving", this);
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

// the robot drops off the package
void Robot::drop(){
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
        NotifyForRobot("idle", this);
}
void Robot::dropnocharge(){
	
        dynamic = false;
        NotifyForRobot("idle", this);
        sleep = true;
}
}
