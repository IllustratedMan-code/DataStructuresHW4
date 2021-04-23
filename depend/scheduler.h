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
  void scheduleTime(const floor &); // schedule arrival to set floor
  void delayTime(const floor &);    // delay arrival to set floor
  void createPeople(std::string FloorName,
                    int NumberOfPeople); // create person and floor placement
  void handleArrivals(floor &, int);     // handle arrivals

  int currentClockTime;
  std::vector<std::shared_ptr<floor>> floors;
  std::vector<event> events;

public:
  void addFloor(std::shared_ptr<floor> F);
  void addEvent(event E);
  void processTime(int); // set scheduler's time
};

class event {
  std::string FloorName;
  int NumberOfPeople;
  int time;
  friend class scheduler;

public:
  event(std::string FloorName, int NumberOfPeople, int time);
};

#endif

// The scheduler is a module that randomly creates persons who arrive at each
// floor at a given arrival time and with an intended destination floor.
