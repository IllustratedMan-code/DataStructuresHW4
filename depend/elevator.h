#ifndef elevator_H
#define elevator_H
#include "button.h"
#include "person.h"
#include "priorityQueue.h"
#include <stack>
#include <vector>

class elevator {
  int Capacity;                 // number of people allowed on elevator
  std::vector<button> Buttons;  // buttons to floors
  int MaxFloor;                 // highest floor reachable by elevator
  int MinFloor;                 // lowest floor reachable by elevator
  int CurrentFloor;             // current floor
  void setButtons();            // sets buttons in elevator
  bool direction = false;       // up or down
  void setDirection();          // sets direction of elevator
  priorityQueue<person> People; // people in elevator
  priorityQueue<int> floorsToVisit;

public:
  void call(int floorNumber);
  void move();                  // moves elevator to another floor
  std::vector<person> Unload(); // returns vector of people leaving elevator and
                                // removes them from the queue
  void
  load(std::vector<person> PeopleGettingOnElevator); // adds person to elevator
};

#endif
