#ifndef button_H
#define button_H


class button {
  protected:
  bool pressedbutton;   //button variable whether it is pressed or not
  public:
    int getbutton();    //pulls whether the button was press by a person
    void setbutton(bool pressedbutton);    //sets the button to the value true/false
    void buttonopen(int floornumber, bool pressedbutton);  //checks if the button was "pressed" and outputs what floor
};

#endif
