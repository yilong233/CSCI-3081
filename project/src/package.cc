#include "package.h"
#include "json_helper.h"

namespace csci3081 {

Package::Package() {
	customer = NULL;
  position = {};
  id = 0;
  name = "";
  radius = 0;
  weight = 0;
  type = "package";

}


Package::Package(const picojson::object& details){
  customer = NULL;
  position = JsonHelper::GetStdFloatVector(details, "position");
  direction = JsonHelper::GetStdFloatVector(details, "direction");
  id = count;
  count++;
  name = JsonHelper::GetString(details, "name");
  radius = JsonHelper::GetDouble(details, "radius");
  weight = 0;
  type = "package";
	version = 0;
  dynamic = false;
  details_ = details;
}



float Package::GetWeight() const{
  return weight;
}

void Package::Setweight(float w){
  weight = w;
}

Customer* Package::GetCustomer() const{
  return customer;
}

void Package::SetCustomer(Customer* cus){
  customer = cus;
}

/// observers for the packages.
void Package::NotifyForPackage(std::string value, Package* d)
  {
    picojson::object notify;

    if(value == "scheduled")
    {
      notify["type"] = picojson::value("notify");
      notify["value"] = picojson::value("scheduled");

    }

    else if(value == "en route")
    {
      notify["type"] = picojson::value("notify");
      notify["value"] = picojson::value("en route");
    }

    else if(value == "delivered")
    {
      notify["type"] = picojson::value("notify");
      notify["value"] = picojson::value("delivered");
    }

    picojson::value event(notify);
    for (int i = 0; i < observers_.size(); i++) {
      observers_.at(i)->OnEvent(event, *d);
      }
  }


}
