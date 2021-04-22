#include "floor.h"
#include "priorityQueue.h"
#include <memory>
#include <vector>

int floor::getFloor() { return (floorNumber); }

void floor::setButtons() {
  if (!people.empty()) {
    bool D = people.front().getDirection();
    if (D) {
      UP.setbutton(1);
      e->call(floorNumber);
    } else {
      DOWN.setbutton(0);
    }
  }
}

void floor::CheckElevator() {
  if (e->getCurrentFloor() == floorNumber && e->IsOpen()) {
    Load(e->Unload());
    e->Load(Unload(e->getRemainingCapacity()));
  }
}

void floor::Load(std::vector<person> P) {
  for (auto &p : P) {
    people.push(p);
  }
}

std::vector<person> floor::Unload(int NumberOfPeople) {
  std::vector<person> TempPeople;
  for (int i; i < NumberOfPeople; i++) {
    TempPeople.push_back(people.front());
    people.pop();
  }
  return TempPeople;
}
floor::floor(int height, std::shared_ptr<elevator> e) {
  floorNumber = height;
  this->e = e;
}
