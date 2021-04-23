#include "building.h"
#include <algorithm>
#include <memory>

void building::addFloor(floor F) {
  std::shared_ptr<floor> NewF(new floor(F));
  floors.push_back(NewF);
  S.addFloor(NewF);
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

void building::Print() {
  for (auto &e : elevators) {
    std::cout << "Elevator On floor " << e->getCurrentFloor() << std::endl;
  }
}
