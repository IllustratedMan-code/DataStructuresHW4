#ifndef elevator_H
#define elevator_H
#include <vector>
#include "button.h"
#include "person.h"
#include <stack>
#include "priorityQueue.h"

class elevator{
    int Capacity; // number of people allowed on elevator
    std::vector<button> Buttons; //buttons to floors
    int MaxFloor; //highest floor reachable by elevator
    int MinFloor; //lowest floor reachable by elevator
    int CurrentFloor; //current floor
    void setButtons(); // sets buttons in elevator
    bool direction = false; //up or down
    void setDirection(); // sets direction of elevator
    priorityQueue<person> People(); // people in elevator
    public:
        void call(int floorNumber);
        void move(); //moves elevator to another floor
        std::vector<person> Exit(); // returns vector of people leaving elevator and removes them from the queue
        void addPerson(person P); // adds person to elevator
        bool getDirection(); //gets current direction of the elevator
};

#endif
