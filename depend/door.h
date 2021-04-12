#ifndef door
#define door

class door{
  protected:
  bool dooropen;
    public:
    int getdoor();   //sets whether the door 
    void setdoor(bool dooropen);
    void dooropen(int floornumber, bool dooropen);
    
};

#endif