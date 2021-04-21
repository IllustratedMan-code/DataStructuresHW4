#include "elevator.h"
#include "priorityQueue.h"
#include <vector>

void elevator::call(int floorNumber) { floorsToVisit.push(floorNumber); }

void elevator::move() {
  if (floorsToVisit.size() > 0) {
    setDirection();
    if (direction) {
      CurrentFloor++;
      if (floorsToVisit.Back() == CurrentFloor) {
        ElevatorDoor.setdoor(1);
      }
    } else {
      CurrentFloor--;
      if (floorsToVisit.Front() == CurrentFloor) {
        ElevatorDoor.setdoor(1);
      }
    }
  }
}

void elevator::setButtons() {
  for (auto &p : People) {
    auto d = p.getDestination();
    Buttons[d - MinFloor].setbutton(1);
    floorsToVisit.push(d);
  }
  deleteFloorRepeats();
}

void elevator::setDirection() {
  if (CurrentFloor < floorsToVisit.Front() &&
      CurrentFloor > floorsToVisit.Back()) {
    return;
  }
  if (CurrentFloor < floorsToVisit.Back()) {
    direction = true;
    return;
  }
  if (CurrentFloor > floorsToVisit.Front()) {
    direction = false;
    return;
  }
}

std::vector<person> elevator::Unload() {
  std::vector<person> UnloadedPeople;
  while (People.size() > 0)
    if (People.Back().getDestination() == CurrentFloor) {
      People.popBack();
    } else if (People.Front().getDestination() == CurrentFloor) {
      People.popFront();
    } else {
      break;
    }
  return UnloadedPeople;
}

bool elevator::IsOpen() { return ElevatorDoor.getdoor(); }
int elevator::getCurrentFloor() { return CurrentFloor; }
void elevator::deleteFloorRepeats() {
  priorityQueue<int> newPriorityQueue;
  auto V = floorsToVisit.Front();
  newPriorityQueue.push(V);
  for (auto &f : floorsToVisit) {
    if (V != f) {
      newPriorityQueue.push(V);
    }
    V = f;
  }
}
int elevator::getRemainingCapacity() { return Capacity - People.size(); }

void elevator::Load(std::vector<person> PeopleGettingOnElevator) {
  for (auto &p : PeopleGettingOnElevator) {
    People.push(p);
  }
}
