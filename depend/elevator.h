#ifndef elevator_H
#define elevator_H
#include "button.h"
#include "door.h"
#include "person.h"
#include "priorityQueue.h"
#include <stack>
#include <vector>

class elevator {
  int Capacity;                // number of people allowed on elevator
  std::vector<button> Buttons; // buttons to floors
  int MaxFloor;                // highest floor reachable by elevator
  int MinFloor;                // lowest floor reachable by elevator
  int CurrentFloor;            // current floor
  void setButtons();           // sets buttons in elevator
  bool direction = false;      // up(t) or down(f)
  void setDirection(); // sets direction of elevator based on floors to visit
  priorityQueue<person> People; // people in elevator
  priorityQueue<int>
      floorsToVisit; // floors in queue that the elevator will visit next
  void deleteFloorRepeats(); // deletes repeated entries in floors to visit
  door ElevatorDoor; // the elevator door (used by the floor class to know when
                     // to unload)
  friend class scheduler;

public:
  elevator(int MaxFloor, int MinFloor, int Capacity);
  std::vector<person> Unload(); // returns vector of people leaving
                                // elevator and removes them from the queue
  void call(int floorNumber);
  void move();                // moves elevator to another floor
  bool IsOpen();              // returns the state of the elevator door
  int getCurrentFloor();      // returns the floor the elevator is currently on
  int getRemainingCapacity(); // returns the remaining number of people allowed
                              // on the elevator
  void
  Load(std::vector<person> PeopleGettingOnElevator); // adds people to elevator
};

#endif
