#ifndef __HW4Q2_CPP__
#define __HW4Q2_CPP__

#include "hw4q2.h"

template <class Item>
Queue<Item>::Queue() {
    capacity = DEF_CAP;
    used = 0;
    first = 0;
    last = 0;
    data = new Item[capacity];
}

template <class Item>
Queue<Item>::Queue(const Queue<Item>& source) {
    capacity = source.capacity;
    used = source.used;
    first = source.first;
    last = source.last;
    data = new Item[capacity];
    int indx = first;
    for (int i = 0; i < used; i = nextIndex(i)) {
        data[indx] = source.data[indx];
        indx = nextIndex(indx);
    }
}

template <class Item>
Queue<Item>::~Queue() {
    delete[] data;
    used = 0;
}

template <class Item>
void Queue<Item>::push(const Item& entry) {
    if (used == capacity) {
        return;
    }
    data[last] = entry;
    last = nextIndex(last);
    used++;
}

template <class Item>
void Queue<Item>::pop() {
    if (used < 1) {
        return;
    }
    first = nextIndex(first);
    used--;
}

template <class Item>
void Queue<Item>::operator=(const Queue<Item>& source) {
    this->used = source.used;
    this->capacity = source.capacity;
    this->first = source.first;
    this->last = source.last;
    int indx = first;
    for (int i = 0; i < used; i++) {
        data[indx] = source.data[indx];
        indx = nextIndex(indx);
    }
}

template <class Item>
size_t Queue<Item>::size() const {
    return used;
}

template <class Item>
bool Queue<Item>::empty() const {
    return (used == 0);
}

template <class Item>
Item Queue<Item>::front() const {
    if (used < 1) {
        return Item();
    }
    return data[first];
}

#endif
