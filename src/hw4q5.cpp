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

template <class Item>
size_t Queue2Stack<Item::size() const {
    return used;
}

template <class Item>
bool Queue2Stack<Item>::empty() const {
    return (used == 0);
}

template <class Item>
Item Queue2Stack<Item>::top() const {
    return s1.front();
}

#endif


