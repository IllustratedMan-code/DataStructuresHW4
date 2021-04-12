#ifndef elevator_H
#define elevator_H
#include <vector>
#include "button.h"
#include "person.h"
class elevator{
    std::vector<button> Buttons; //buttons to floors
    int MaxFloor; //highest floor reachable by elevator
    int MinFloor; //lowest floor reachable by elevator
    int CurrentFloor; //current floor
    std::vector<person> People; // people in elevator
    void setButtons(); // sets buttons in elevator
    bool direction; //up or down
    void setDirection(); // sets direction of elevator
    public:
        void move(); //moves elevator to another floor
        std::vector<person> PeopleLeaving(); // returns vector of people leaving elevator
        void addPerson(person P); // adds person to elevator
        bool getDirection(); //gets current direction of the elevator
};

#endif
