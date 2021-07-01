#include "vector2D.h"
#include <math.h>
namespace csci3081 {
  Vector2D::Vector2D(){
    vec={0,0,0};
  }

  Vector2D::Vector2D(std::vector<float> c){
    vec = c;
  }

  void Vector2D::normalize(){
    float mag = magnitude();
    if (mag==0)
      return;
    vec[0] = vec[0]/mag;
    vec[1] = 0;
    vec[2] = vec[2]/mag;
  }

  float Vector2D::magnitude(){
    return sqrt(vec[0]*vec[0] + vec[2]*vec[2]);
  }

  void Vector2D::setVec(std::vector<float> c){
    vec = c;
  }
  const std::vector<float>& Vector2D::GetVec() const{
    return vec;
  }
}
