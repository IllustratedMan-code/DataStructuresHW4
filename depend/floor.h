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
  void setButtons(); // sets the buttons on the floor to call the elevator
  std::shared_ptr<elevator> e; // pointer to elevator
  std::vector<person>
  Unload(int NumberOfPeople); // Unloads people onto elevator
  friend class building;
  friend class scheduler;
  std::string name; // name of the floor

public:
  void Load(std::vector<person> P); // loads people into floor
  floor(std::string name, int height,
        std::shared_ptr<elevator> e); // constructor
  floor(const floor &F);              // copy constructor
  int getFloor();                     // gets the floor Number
  std::string getFloorName();         // gets the floor name
  std::vector<person>
  CheckElevator(); // checks whether the elevator is on the floor and returns
                   // the people getting off the elevator
};

#endif
