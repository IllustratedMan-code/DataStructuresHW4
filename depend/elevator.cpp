#include "elevator.h"
#include <vector>

void elevator::call(int floorNumber) {}

void elevator::move() {
  if (floorsToVisit.size() > 0) {
    setDirection();
    if (direction) {
      CurrentFloor++;
    } else {
      CurrentFloor--;
    }
  }
}

void elevator::setButtons() {
  for (auto &p : People) {
    auto d = p.getDestination();
    Buttons[d - MinFloor].setbutton(1);
    floorsToVisit.push(d);
  }
}

bool elevator::getDirection() { return direction; }
