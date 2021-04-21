#include <iostream>
#include "clock.h" 

using namespace std;

// constructor
clock::clock()             
   : time( 0 )  // set time to 0
{ 
   cout << "clock constructed" << endl; 

}

// destructor
clock::~clock()            
{ 
   cout << "clock destructed" << endl; 

}

void clock::tick()  // increment time by 1       
{ 
   time++; 

} //

int clock::getTime() const // current time
{ 
   return time; 

}
