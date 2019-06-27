#ifndef __HW4Q5_CPP__
#define __HW4Q5_CPP__

#include "hw4q5.h"

template <class Item>
Queue2Stack<Item>::Queue2Stack() {
    q1 = Queue<Item>();
    q2 = Queue<Item>();
    used = 0;
}

template <class Item>
void Queue2Stack<Item>::push(const Item& entry) {
    // q1 keeps track of data, q2 just to help simulate stack functions
    q2.push(entry);
    while (!q1.empty()) {
        q2.push(q1.front());
        q1.pop();
    }
    while (!q2.empty()) {
        q1.push(q2.front());
        q2.pop();
    }
    used++;
}

template <class Item>
void Queue2Stack<Item>::pop() {
    if (used < 1) {
        return;
    }
    s1.pop();
    used --;
}

#endif


