#ifndef floor_H
#define floor_H
#include "button.h"
#include "elevator.h"
#include "person.h"
#include <vector>
#include <memory>
#include <queue>

class floor{
    int floorNumber;
    std::queue<person> people; //people on floor first come first serve
    button UP; // up button outside elevator
    button DOWN; // down button outside elevator
    void setButtons();
    bool elevatorOnFloor;
    std::shared_ptr<elevator> e; //pointer to elevator
    public:
        floor(int height, std::shared_ptr<elevator> e);
        void addPerson(person P);
        int getFloor();
        bool hasElevator();
};



#endif
