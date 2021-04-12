#ifndef floor_H
#define floor_H
#include "button.h"
#include "elevator.h"
#include "person.h"
#include <vector>
#include <memory>

class floor{
    int floorNumber;
    std::vector<person> people; //people on floor
    button UP; // up button outside elevator
    button DOWN; // down button outside elevator
    void setButtons();
    bool elevatorOnFloor;
    public:
        floor(int height);
        void addPerson(person P);
        int getHeight();
        bool getState();
        bool getDirection();
};



#endif
