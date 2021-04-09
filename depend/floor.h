#ifndef floor_H
#define floor_H
#include "button.h"
#include "elevators"
#include "person"
#include <vector>
#include <memory>

class floor{
    int height;
    std::vector<person> people;
    bool UPorDown;
public:
    bool getstate();
    bool getDirection();
};



#endif
