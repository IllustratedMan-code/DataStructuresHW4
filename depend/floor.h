#ifndef floor_H
#define floor_H
#include "button.h"
#include "elevator.h"
#include "person.h"
#include <vector>
#include <memory>

class floor{
    int height;
    std::vector<person> people; //people on floor
    button UP; // up button outside elevator
    button DOWN; // down button outside elevator

public:
    bool getstate();
    bool getDirection();
};



#endif
