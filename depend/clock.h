#ifndef clock_H
#define clock_H

class clock {
private:
  int time; // clock's time
public:
  clock();             // constructor
  void tick();         // increment clock by one second
  int getTime() const; // returns clock's current time
};

#endif
