#ifndef person_H
#define person_H

class person {
private:
  int CurrentFloor, Destination;
  bool Direction;
  int ElevatorTickCount = 0; // time spent in elevator
  int FloorTickCount = 0;    // time spent waiting for elevator

public:
  person(int CurrentFloor, int Destination);
  int getCurrentFloor(); // The original floor that the person was on
  int getDestination();  // The floor the person wants to go to
  bool getDirection();   // gets the direction the person wants to go
  void incrementElevatorTickCount(); // increments the amount of time the person
                                     // has spent on the elevator
  void incrementFloorTickCount();    // increments the amount of time the person
                                     // has spent on the original floor
  int getElevatorTickCount();
  int getFloorTickCount();
  operator int(); // needed for comparisons in priority queue
};

#endif
