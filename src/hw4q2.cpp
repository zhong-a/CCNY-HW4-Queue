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
    for (int i = first; i < last; i = nextIndex(i)) {
        data[i] = source.data[i];
    }
}

template <class Item>
Queue<Item>::~Queue() {
    delete[] data;
}

