#ifndef door_H
#define door_H

class door{
  protected:
    bool dooropen;

  public:
    int getdoor();   //sets whether the door 
    void setdoor(bool dooropen);
    void doorOpen(int floornumber, bool dooropen);
    
};

#endif
