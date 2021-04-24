#include "floor.h"
#include "priorityQueue.h"
#include <memory>
#include <string>
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

int floor::CheckElevator() {
  int s = 0;
  if (e->getCurrentFloor() == floorNumber && e->IsOpen()) {
    auto i = e->Unload();
    s = i.size();
    // Load(e->Unload());
    e->Load(Unload(e->getRemainingCapacity()));
  }
  setButtons();
  return (s);
}

void floor::Load(std::vector<person> P) {
  for (auto &p : P) {
    people.push(p);
  }
}

std::vector<person> floor::Unload(int NumberOfPeople) {
  std::vector<person> TempPeople;
  for (int i = 0; i < NumberOfPeople; i++) {
    if (people.size() <= 0) {
      return TempPeople;
    }
    TempPeople.push_back(people.front());
    people.pop();
  }
  return TempPeople;
}
floor::floor(std::string name, int height, std::shared_ptr<elevator> e) {
  floorNumber = height;
  this->e = e;
  this->name = name;
}

floor::floor(const floor &F) {
  this->e = F.e;
  this->floorNumber = F.floorNumber;
  this->name = F.name;
}
std::string floor::getFloorName() { return name; }
