#ifndef building_H
#define building_H
#include "elevator.h"
#include "floor.h"
#include "scheduler.h"
#include <memory>
#include <vector>

class building {
  std::vector<std::shared_ptr<floor>> floors;
  std::vector<std::shared_ptr<elevator>> elevators;
  scheduler S;

public:
  void addFloor(floor F);
  void Tick(); // advance time
  void Print();
};

#endif
