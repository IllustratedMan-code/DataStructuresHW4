#include "button.h"
#include "door.h"
#include <iostream>

// Door class
int door::getdoor() { return (dooropen); };
void door::setdoor(bool c) { dooropen = c; };

// Button class
int button::getbutton() { return (pressedbutton); };
void button::setbutton(bool a) { pressedbutton = a; };
