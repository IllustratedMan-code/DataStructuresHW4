#include "building.h"
#include "scheduler.h"
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
  C.tick();
  S.processTime(C.getTime());
  for (auto &f : floors) {
    f->CheckElevator();
  }
  for (auto &e : elevators) {
    e->move();
  }
}

void building::Print() {
  for (auto &e : elevators) {
    std::cout << "Elevator On floor: " << e->getCurrentFloor() << std::endl;
    std::cout << "Elevator Capacity: " << e->getRemainingCapacity()
              << std::endl;
    std::cout << std::endl;
  }
  for (auto &f : floors) {
    std::cout << f->name << ": " << f->people.size() << std::endl;
  }
}

void building::addEvent(std::string floorName, int NumberOfPeople, int time) {
  event e(floorName, NumberOfPeople, time);
  S.addEvent(e);
}
