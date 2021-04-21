#include "person.h"
#include <iostream>
using namespace std;

person::operator int() { return Destination; }
int person::getCurrentFloor() { return CurrentFloor; }
int person::getDestination() { return Destination; }
bool person::getDirection() { return Direction; }
