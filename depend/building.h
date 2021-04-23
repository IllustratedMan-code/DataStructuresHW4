#ifndef building_H
#define building_H
#include "clock.h"
#include "elevator.h"
#include "floor.h"
#include "scheduler.h"
#include <memory>
#include <string>
#include <vector>

class building {
  std::vector<std::shared_ptr<floor>> floors;
  std::vector<std::shared_ptr<elevator>> elevators;
  scheduler S;
  class clock C;

public:
  void addFloor(floor F);
  void addEvent(std::string floorName, int NumberOfPeople, int time);
  void Tick(); // advance time
  void Print();
};

#endif
