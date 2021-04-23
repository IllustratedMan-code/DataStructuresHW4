#include "../depend/building.h"
#include "../depend/elevator.h"
#include "../depend/floor.h"
#include <iostream>
#include <memory>

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
  B.addEvent("Ground", 2, 1);
  B.addEvent("Ground", 2, 5);
  B.Tick();
  B.Print();
  B.Tick();
  B.Print();
  B.Tick();
  B.Print();
  for (auto i = 0; i < 5; i++) {
    B.Tick();
    B.Print();
  }
}
