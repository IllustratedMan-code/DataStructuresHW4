#include "elevator.h"
#include "priorityQueue.h"
#include <iostream>
#include <vector>

void elevator::call(int floorNumber) { floorsToVisit.push(floorNumber); }

void elevator::move() {
  deleteFloorRepeats();
  if (floorsToVisit.size() > 0) {
    setDirection();
    if (direction) {
      if (CurrentFloor + 1 <= MaxFloor) {
        CurrentFloor++;
      }
    } else {
      if (CurrentFloor - 1 >= MinFloor) {
        CurrentFloor--;
      }
    }
    ElevatorDoor.setdoor(0);
    priorityQueue<int> TempFloors;
    while (floorsToVisit.size() > 0) {
      if (floorsToVisit.Front() == CurrentFloor) {
        ElevatorDoor.setdoor(1);
        floorsToVisit.popFront();
        std::cout << "Hey!";
      }
      if (floorsToVisit.size() == 0) {
        break;
      }
      TempFloors.push(floorsToVisit.popFront());
    }
    floorsToVisit = TempFloors;
  }
}

void elevator::setButtons() {
  for (auto &p : People) {
    auto d = p.getDestination();
    Buttons[d - MinFloor].setbutton(1);
    floorsToVisit.push(d);
  }
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
      UnloadedPeople.push_back(People.popBack());
    } else if (People.Front().getDestination() == CurrentFloor) {
      UnloadedPeople.push_back(People.popFront());
    } else {
      break;
    }
  return UnloadedPeople;
}

bool elevator::IsOpen() { return ElevatorDoor.getdoor(); }

int elevator::getCurrentFloor() { return CurrentFloor; }

void elevator::deleteFloorRepeats() {
  priorityQueue<int> newPriorityQueue;
  while (floorsToVisit.size() > 0) {
    auto V = floorsToVisit.popBack();
    if (newPriorityQueue.size() == 0 || V != newPriorityQueue.Back()) {
      newPriorityQueue.push(V);
    }
  }
  floorsToVisit = newPriorityQueue;
  for (auto &f : floorsToVisit) {
    std::cout << "f:: " << f << std::endl;
  }
}
int elevator::getRemainingCapacity() { return Capacity - People.size(); }

void elevator::Load(std::vector<person> PeopleGettingOnElevator) {
  for (auto &p : PeopleGettingOnElevator) {
    People.push(p);
  }
  setButtons();
}

elevator::elevator(int MinFloor, int MaxFloor, int Capacity) {
  this->MaxFloor = MaxFloor;
  this->MinFloor = MinFloor;
  this->Capacity = Capacity;
  CurrentFloor = MinFloor;
  for (int i = MinFloor; i < MaxFloor; i++) {
    button b;
    Buttons.push_back(b);
  }
}
