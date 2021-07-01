#include "customer.h"

namespace csci3081 {

Customer::Customer(){
	position = {};
  id = 0;
  name = "";
  radius = 0;
  type = "customer";
}

Customer::Customer(const picojson::object& details){
  position = JsonHelper::GetStdFloatVector(details, "position");
  direction = JsonHelper::GetStdFloatVector(details, "direction");
  id = count;
  count++;
  name = JsonHelper::GetString(details, "name");
  radius = JsonHelper::GetDouble(details, "radius");
  type = "customer";
	version = 0;
  dynamic = false;
  details_ = details;
}

}
