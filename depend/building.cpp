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
  int s = 0;
  for (auto &f : floors) {
    s += f->CheckElevator();
  }
  for (auto &e : elevators) {
    e->move();
  }
  DestinationSum = s;
}

void building::Print() {
  for (auto &e : elevators) {
    std::cout << "Elevator On floor: " << e->getCurrentFloor() << std::endl;
    std::cout << "Elevator Capacity: " << e->getRemainingCapacity()
              << std::endl;
  }
  for (auto &f : floors) {
    std::cout << f->name << ": " << f->people.size() << std::endl;
  }
  std::cout << DestinationSum << " People have reached their destination."
            << std::endl;
  std::cout << "The current time in building ticks is: " << C.getTime()
            << std::endl;
  std::cout << std::endl;
}

void building::addEvent(std::string floorName, int NumberOfPeople, int time) {
  event e(floorName, NumberOfPeople, time);
  S.addEvent(e);
}
