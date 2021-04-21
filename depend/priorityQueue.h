#ifndef priorityQueue_H
#define priorityQueue_H

#include <bits/c++config.h>
#include <deque>
#include <iostream>
#include <iterator>

template <class T> class priorityQueue {
  std::deque<T> items;

public:
  void push(T item) {
    for (int i = 0; i < items.size(); i++) {
      if (item <= items[i]) {
        items.insert(items.begin() + i, item);
        return;
      }
    }
    items.push_back(item);
  }
  T popBack() {
    auto item = items.back();
    items.pop_back();
    return item;
  }
  T popFront() {
    auto item = items.front();
    items.pop_front();
    return (item);
  }
  T Front() { return (items.front()); }
  T Back() { return (items.back()); }
  auto begin() { return (items.begin()); }
  auto end() { return (items.end()); }
  auto size() { return (items.size()); }
};

#endif
