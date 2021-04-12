#include "door.h"
#include "button.h"
#include <iostream>




//Door class
void door::dooropen(int x, bool d){
  if(d == true){
    std::cout << "Door on floor" << x << "has opened."  << std::endl;
  }else{
    std::cout << "Door has not opened." << std::endl;
  }
};
int door::getdoor(){return(doorOpen);};
void door::setdoor(bool c){dooropen = c;};

//Button class
void button::buttonopen(int x, bool b){
  if(b == true){
    std::cout << "Button for floor" << x << "has been pressed."  <<std::endl;
  }else{
    std::cout << "Invalid floor has been pressed." << std::endl;
  }
};
int button::getbutton(){return(pressedbutton);};
void button::setbutton(bool a){pressedbutton = a;};
