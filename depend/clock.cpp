#include "clock.h"
#include <iostream>

using namespace std;

clock::clock() // constructor
    : time(0)  // set time to 0
{}

void clock::tick() // increment time by 1
{
  time++;
}

int clock::getTime() const // current time
{
  return time;
}
