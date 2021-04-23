#ifndef floor_H
#define floor_H
#include "button.h"
#include "elevator.h"
#include "person.h"
#include <memory>
#include <queue>
#include <string>
#include <vector>

class floor {
  int floorNumber;
  std::queue<person> people; // people on floor first come first serve
  button UP;                 // up button outside elevator
  button DOWN;               // down button outside elevator
  void setButtons();
  bool elevatorOnFloor;
  std::shared_ptr<elevator> e; // pointer to elevator
  std::vector<person> Unload(int NumberOfPeople);
  friend class building;
  friend class scheduler;
  std::string name;

public:
  void Load(std::vector<person> P);
  floor(std::string name, int height, std::shared_ptr<elevator> e);
  floor(const floor &F);
  int getFloor();
  std::string getFloorName();
  void CheckElevator();
};

#endif
