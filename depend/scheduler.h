#ifndef scheduler_H
#define scheduler_H

class floor;
class scheduler {
private:
   
   void scheduleTime( const floor & ); // schedule arrival to set floor
   void delayTime( const floor & ); // delay arrival to set floor
   void createNewPerson( floor & ); // create person and floor placement
   void handleArrivals( floor &, int ); // handle arrivals
   
   int currentClockTime;

public:
   scheduler( floor &, floor & );    
   ~scheduler();                 
   void processTime( int ); // set scheduler's time

};

#endif


//The scheduler is a module that randomly creates persons who arrive at each floor at a given arrival time and with an intended destination floor.