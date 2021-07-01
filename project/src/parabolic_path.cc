#include "../include/parabolic_path.h"
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

ParabolicPath::ParabolicPath(){}

// return the parabolic path
vector<vector<float>> ParabolicPath::GetPath(vector<float> v1,vector<float> v2,const IGraph* gragh){
	vector<float> diff = {v2[0]-v1[0],v2[1]-v1[1],v2[2]-v1[2]};
	vector<float> mid = {(v2[0]+v1[0])/2,(v2[1]+v1[1])/2,(v2[2]+v1[2])/2};

	int step = 100;
	int hight = 200;
	vector<vector<float>> path ;
	for (int i =0;i<step;i++){
		vector<float> V = {v1[0]+ diff[0]*i/step, v1[1]+ diff[1]*i/step, v1[2]+ diff[2]*i/step};
		float y = (1-(pow(V[0]-mid[0],2) + pow(V[1]-mid[1],2) + pow(V[2]-mid[2],2))/(pow(mid[0]-v1[0],2) + pow(mid[1]-v1[1],2) + pow(mid[2]-v1[2],2)))*hight;
		V[1] = V[1] + y;
		path.push_back(V);
	}

	return path;
}
}
