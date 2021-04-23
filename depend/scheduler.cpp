#include "scheduler.h"
#include <iostream>
#include <string>
#inlcude "scheduler.h"
#include "elevator.h"
#include "person.h";
#include <stdlib.h>
#include <time.h>

using namespace std;

void scheduler::addFloor(std::shared_ptr<floor> F) { floors.push_back(F); }

void scheduler::addEvent(std::string FloorName, int NumberOfPeople, int time) {
  for (auto &f : floors) {
    if (f->getFloorName() == FloorName) {
    }
  }
}

void scheduler::processTime(int time) {
  for (auto &e : events) {
    if (e.time == time) {
      createPeople(e.FloorName, e.NumberOfPeople);
    }
  }
}

void scheduler::createPeople(std::string FloorName, int NumberOfPeople) {
  for (auto &f : floors) {
    if (f->getFloorName() == FloorName) {
      std::vector<person> newPeople;
      srand(time(NULL));
      for (int i = 0; i < NumberOfPeople; i++) {
        int Destination = rand() % f->e->MaxFloor + f->e->MinFloor;
        if (Destination == f->floorNumber) {
          Destination++;
        }
        person P(f->floorNumber, Destination);
        newPeople.push_back(P);
      }
      f->Load(newPeople);
    }
  }
}

void scheduler::addEvent(event E) { events.push_back(E); }

event::event(std::string FloorName, int NumberOfPeople, int time) {
  this->FloorName = FloorName;
  this->NumberOfPeople = NumberOfPeople;
  this->time = time;
}
