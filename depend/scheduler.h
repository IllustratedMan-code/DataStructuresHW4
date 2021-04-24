#ifndef scheduler_H
#define scheduler_H

#include "clock.h"
#include "floor.h"
#include <memory>
#include <string>
#include <vector>

class event;

class scheduler {
private:
  void createPeople(std::string FloorName,
                    int NumberOfPeople); // create person and floor placement

  std::vector<std::shared_ptr<floor>> floors; // pointers to floors
  std::vector<event> events; // events that the scheduler executes

public:
  void addFloor(std::shared_ptr<floor> F); // adds a floor to floors
  void addEvent(event E);                  // adds an event to events
  void processTime(int);                   // set scheduler's time
};

class event {            // class, assembly, etc
  std::string FloorName; // name of floor that event will occur on
  int NumberOfPeople;    // people at event
  int time;              // time event will occur
  friend class scheduler;

public:
  event(std::string FloorName, int NumberOfPeople, int time); // constructor
};

#endif

// The scheduler is a module that randomly creates persons who arrive at each
// floor at a given arrival time and with an intended destination floor.
