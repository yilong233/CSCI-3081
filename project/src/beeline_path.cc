#include "../include/beeline_path.h"
#include "json_helper.h"
#include <math.h>
#include <iostream>
#include "entity_base.h"
#include "battery.h"
#include "customer.h"
#include "package.h"
#include "vector3D.h"
#include <vector>
#include <string>

namespace csci3081 {

BeelinePath::BeelinePath(){}

// return the beeline path
vector<vector<float>> BeelinePath::GetPath(vector<float> v1,vector<float> v2,const IGraph* gragh){
	return {v1,{v1[0],370,v1[2]},{v2[0],370,v2[2]},v2};
}

}
