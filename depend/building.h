#ifndef building_H
#define building_H
#include "floor.h"
#include "elevator.h"
#include <vector>
#include "scheduler.h"

class building{
    std::vector<floor> floors;
    scheduler S;
    public:
        void addFloor(floor);


};

#endif
