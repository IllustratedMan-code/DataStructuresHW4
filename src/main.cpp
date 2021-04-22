#include "../depend/building.h"
#include "../depend/elevator.h"
#include "../depend/floor.h"
#include <iostream>
#include <memory>

int main() {
  building B;
  std::shared_ptr<elevator> L(new elevator(0, 5));
  floor G(0, L);
  floor one(1, L);
  floor two(2, L);

  B.addFloor(G);
  B.addFloor(one);
  B.addFloor(two);
  B.Tick();
  B.Print();
  std::cout << "Hello world";
}
