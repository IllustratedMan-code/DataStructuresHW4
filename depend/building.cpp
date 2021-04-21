#include "building.h"
#include <algorithm>

void building::addFloor(floor F) {
  floors.push_back(F);
  bool check = false;
  for (auto &e : elevators) {
    if (e == F.e) {
      check = true;
    }
  }
  if (!check) {
    elevators.push_back(F.e);
  }
}

void building::Tick() {
  for (auto &e : elevators) {
    e->move();
  }
  for (auto &f : floors) {
    f.CheckElevator();
  }
}
