#ifndef priorityQueue_H
#define priorityQueue_H

#include <bits/c++config.h>
#include <deque>
#include <iostream>
#include <iterator>

template <class T> class priorityQueue {
  std::deque<T> items;

public:
  void push(T item) { // adds an item to the queue
    for (int i = 0; i < items.size(); i++) {
      if (item <= items[i]) {
        items.insert(items.begin() + i, item);
        return;
      }
    }
    items.push_back(item);
  }
  T popBack() { // pops the back and returns it
    auto item = items.back();
    items.pop_back();
    return item;
  }
  T popFront() { // pops the front and returns it
    auto item = items.front();
    items.pop_front();
    return (item);
  }
  T Front() { return (items.front()); }    // returns the front
  T Back() { return (items.back()); }      // returns the back
  auto begin() { return (items.begin()); } // needed for iteration loops
  auto end() { return (items.end()); }     // needed for iteration loops
  auto size() { return (items.size()); }   // needed for iteration loops
};

#endif
