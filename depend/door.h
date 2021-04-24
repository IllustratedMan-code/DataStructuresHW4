#ifndef door_H
#define door_H

class door {
protected:
  bool dooropen;

public:
  int getdoor(); // gets whether the door is open (true) or closed (false)
  void setdoor(bool dooropen); // sets door state
};

#endif
