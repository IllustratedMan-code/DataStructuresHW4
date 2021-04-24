#include "../depend/building.h"
#include "../depend/elevator.h"
#include "../depend/floor.h"
#include <iostream>
#include <memory>
#include <ostream>
#include <string>

void Repl(building &B);
void PrintCommands();

int main() {
  building B;
  std::shared_ptr<elevator> L(new elevator(0, 5, 5));
  floor G("Ground", 0, L);
  floor one("one", 1, L);
  floor two("two", 2, L);
  floor three("three", 3, L);
  floor four("four", 4, L);

  B.addFloor(G);
  B.addFloor(one);
  B.addFloor(two);
  B.addFloor(three);
  B.addFloor(four);

  Repl(B);
}

void Repl(building &B) {
  B.Print();
  PrintCommands();
  std::string command;
  while (true) {
    std::cout << "Enter a command: ";
    std::getline(std::cin, command);
    if (command.compare("Add Event") == 0) {
      std::cout
          << "Enter what floor you would like to add the event to by name: ";
      std::string floor;
      std::getline(std::cin, floor);
      std::string NumberOfPeople;
      std::cout << "Enter The number of people at the event: ";
      std::getline(std::cin, NumberOfPeople);
      std::string time;
      std::cout << "Enter the time you would like the event to happen: ";
      std::getline(std::cin, time);
      B.addEvent(floor, stoi(NumberOfPeople), stoi(time));
      std::cout << "The Event was added to the schedule" << std::endl;
    } else if (command.compare("Tick") == 0) {
      B.Tick();
      B.Print();
    } else if (command.compare("Exit") == 0) {
      return;
    } else {
      PrintCommands();
    }
  }
}

void PrintCommands() {
  std::cout << std::endl;
  std::cout << "Add Event" << std::endl << "Tick" << std::endl;
  std::cout << "Exit" << std::endl << std::endl;
  ;
}
