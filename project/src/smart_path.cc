#include "../include/smart_path.h"
#include "json_helper.h"
#include <math.h>
#include <iostream>
#include "entity_base.h"
#include "battery.h"
#include "customer.h"
#include "package.h"
#include "vector3D.h"
#include <EntityProject/graph.h>
#include <vector>
#include <string>

namespace csci3081 {

SmartPath::SmartPath(){}
// return the smart path
vector<vector<float>> SmartPath::GetPath(vector<float> v1,vector<float> v2,const IGraph* gragh){
	return gragh->GetPath(v1,v2);
}
}
