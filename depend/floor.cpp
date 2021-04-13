#include "floor.h"

void floor::addPerson(person P){
    people.push(P);
}

int floor::getFloor(){
    return(floorNumber);
}

void floor::setButtons(){
    if(!people.empty()){
        bool D = people.front().getDirection();
        if (D){
            UP.setbutton(1);
            e->call(floorNumber);
        } else{
            DOWN.setbutton(0);
        }
    }
}
