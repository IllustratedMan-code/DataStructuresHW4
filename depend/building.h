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
  std::vector<std::shared_ptr<floor>> floors;       // floors in the building
  std::vector<std::shared_ptr<elevator>> elevators; // elevators in the building
  scheduler S;   // Scheduler spawns people on floors
  class clock C; // keeps track of the current time in the building
  std::vector<person>
      UnloadedPeople; // people that are being Unloaded onto floors from the
                      // elevator in the current tick

public:
  void addFloor(floor F); // adds a floor
  void
  addEvent(std::string floorName, int NumberOfPeople,
           int time); // adds a scheduler entry that will spawn a certain number
                      // of randomly generated people at a specific time
  void Tick();        // advance time by one tick in the building
  void Print();       // prints aspects of the building
};

#endif
