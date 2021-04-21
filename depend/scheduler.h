#ifndef scheduler_H
#define scheduler_H

class floor;   // forward declaration

class scheduler {
private:
   
   void scheduleTime( const floor & ); // schedule arrival to floor
   void delayTime( const floor & ); // delay arrival to floor
   void createNewPerson( floor & ); // create person and floor placement
   void handleArrivals( floor &, int ); // handle arrivals
   
   int currentClockTime;

public:
   scheduler( floor &, floor & );    
   ~scheduler();                 
   void processTime( int ); // set scheduler's time

};

#endif
