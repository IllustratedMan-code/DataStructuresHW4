#ifndef person_H
#define person_H

class person {
private:
  int CurrentFloor, Destination;
  bool Direction;

public:
  int getCurrentFloor(); // The floor the person is on
  int getDestination();  // The floor the person wants to go to
  bool getDirection();
};

#endif
