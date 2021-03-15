#pragma once

#include <iostream>
#include <exception>

// #include "leaker.h"

template <typename T>
class ABS {
public:
    // Constructors, Destructors, and operators
    ABS(): capacity(1), size(0) {
        array = new T[1];
    }
    ABS(int capacity_): capacity(capacity_), size(0) {
        array = new T[capacity_];
    }
    ABS(const ABS& d) {
        capacity = d.capacity;
        size = d.size;
        array = new T[capacity];
        for (unsigned int i = 0; i < capacity; ++i) {
            array[i] = d.array[i];
        }
    }
    ABS &operator=(const ABS& d) {
        if (this == &d) {
            return *this;
        }
        capacity = d.capacity;
        size = d.size;
        delete[] array;
        array = new T[capacity];
        for (unsigned int i = 0; i < capacity; ++i) {
            array[i] = d.array[i];
        }
        return *this;
    }
    ~ABS() {
        delete[] array;
    }

    // Other Public Member Functions
    void push(T data) {
        if (size == capacity) {
            grow();
        }
        array[size++] = data;
    }
    T pop() {
        if (size == 0) {
            throw std::runtime_error("You done goofed.");
        }
        T toReturn = array[size - 1];
        array [--size] = 0;
        if ((static_cast<double>(size) / static_cast<double>(capacity)) < (1.0 / SCALE_FACTOR)) {
            shrink();
        }
        return toReturn;
    }
    T peek() {
        if (size == 0) {
            throw std::runtime_error("You done goofed.");
        }
        return array[size - 1];
    }
    unsigned int getSize() {
        return size;
    }
    unsigned int getMaxCapacity() {
        return capacity;
    }
    T* getData() {
        return array;
    }
private:
    float SCALE_FACTOR = 2.0f;
    unsigned int capacity;
    unsigned int size;
    T* array;

    // Helper Functions
    void grow() {
        T* newArray = new T[static_cast<int>(capacity * SCALE_FACTOR)];
        for (unsigned int i = 0; i < capacity; ++i) {
            newArray[i] = array[i];
        }
        capacity = static_cast<int>(capacity * SCALE_FACTOR);
        delete[] array;
        array = newArray;
    }
    void shrink() {
        unsigned int newSize = static_cast<double>(capacity) / SCALE_FACTOR;
        T* newArray = new T[newSize];
        capacity = newSize;
        for (unsigned int i = 0; i < newSize; ++i) {
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
    }
};