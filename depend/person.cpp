#include "person.h"
#include <iostream>
using namespace std;

person::operator int() { return Destination; }
int person::getCurrentFloor() { return CurrentFloor; }
int person::getDestination() { return Destination; }
bool person::getDirection() { return Direction; }
person::person(int CurrentFloor, int Destination) {
  this->CurrentFloor = CurrentFloor;
  this->Destination = Destination;
  if (CurrentFloor > Destination) {
    Direction = 0;
  } else {
    Direction = 1;
  }
}
