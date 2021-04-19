#ifndef priorityQueue_H
#define priorityQueue_H

#include <iostream>
#include <deque>
#include <iterator>


template<class T>
class priorityQueue{
    std::deque<T> items;
    bool large;
    public:

        void push(T item){
            for(int i=0; i<items.size(); i++){
                if(large){
                    if(item <= items[i]){
                        items.insert(items.begin() + i, item);
                        return;
                    }
                }}
            items.push_back(item);
        }
        T popBack(){
            return(items.pop_back());
        }
        T popFront(){
            return(items.pop_front());
        }
        T Front(){
            return(items.front());
        }
        T Back(){
            return(items.back());
        }
        auto begin(){
            return(items.begin());
        }
        auto end(){
            return(items.end());
        }
};

#endif
