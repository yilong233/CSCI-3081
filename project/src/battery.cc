#include "battery.h"

namespace csci3081 {

Battery::Battery(){
  maxCharge = 10000;
  remaining = 10000;
  empty = false;
}

Battery::Battery(float m) {
  maxCharge = 10000;
  remaining = m;
  empty = false;
}

void Battery::SetRemaining(float m){
  remaining = m;
}

float Battery::GetMax() const{
  return maxCharge;
}

float Battery::GetRemaining() const{
  return remaining;
}

void Battery::ReduceRemaining(float m){
  remaining -= m;
}

bool Battery::IsEmpty() const{
  return empty;
}

void Battery::SetEmpty(bool e) {
   empty = e;
}

void Battery::CheckEmpty(){
  if (remaining <= 0){
    empty = true;
  }
}

}
