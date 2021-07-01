#include "vector3D.h"
#include <math.h>
#include <vector>
namespace csci3081 {
  Vector3D::Vector3D(){
    vec={0,0,0};
  }

  Vector3D::Vector3D(std::vector<float> c){
    vec = c;
  }

  void Vector3D::normalize(){
    float mag = magnitude();
    if (mag==0)
      return;
    vec[0] = vec[0]/mag;
    vec[1] = vec[1]/mag;
    vec[2] = vec[2]/mag;
  }

  float Vector3D::magnitude(){
    return sqrt(vec[0]*vec[0]+vec[1]*vec[1]+vec[2]*vec[2]);
  }

  void Vector3D::setVec(std::vector<float> c){
    vec = c;
  }
  const std::vector<float>& Vector3D::GetVec() const{
    return vec;
  }
}
