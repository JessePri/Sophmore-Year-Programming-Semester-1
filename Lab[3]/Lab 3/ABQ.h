#pragma once
#include <iostream>
#include <exception>
template<typename T>
class ABQ {
public:
    // Constructors, Destructors, and operators
    ABQ(): capacity(1), front(0), back(0) {
        array = new T[capacity];
    }
    ABQ(int capacity_): capacity(capacity_), front(0), back(0) {
        array = new T[capacity];
    }
    ABQ(const ABQ& d) {
        capacity = d.capacity;
        front = d.front;
        back = d.back;
        array = new T[capacity];
        for (unsigned int i = 0; i < capacity; ++i) {
            array [i] = d.array [i];
        }
    }
    ABQ &operator=(const ABQ& d){
        if (this == &d) {
            return *this;
        }
        capacity = d.capacity;
        front = d.front;
        back = d.back;
        array = new T[capacity];
        for (unsigned int i = 0; i < capacity; ++i) {
            array [i] = d.array [i];
        }
    }
    ~ABQ() {
        delete[] array;
    }
    // Other Public Member Functions
    void enqueue(T data) {
        // std::cout << "enqueue(T data) HIT" << std::endl;
        if (back == capacity) {
            grow();
        }
        array[back++] = data;
    }
    T dequeue() {
        // std::cout << "DEQUEUE HIT" << std::endl;
        if (back == front) {
            throw std::runtime_error("Yikes boss");
        }
        T toReturn = array[front++];
        double capacityRatio = (static_cast<double>(back) - static_cast<double>(front))/static_cast<double>(capacity);
        if (capacityRatio < (1.0 / SCALE_FACTOR)) {
            shrink();
        }
        return toReturn;
    }
    T peek() {
        if (back == front) {
            throw std::runtime_error("Yikes boss");
        }
        return array[front];
    }
    unsigned int getSize() {
        return back - front;
    }
    unsigned int getMaxCapacity() {
        return capacity;
    }
    T* getData() {
        return array;
    }
    unsigned int getFront() {
        return front;
    }
    unsigned int getBack() {
        return back;
    }

private:
    unsigned int capacity;
    float SCALE_FACTOR = 2.0f;
    unsigned int front;
    unsigned int back; // This is refering to the actual term at the back
    T* array;
    void grow() {
        // std::cout << "grow() HIT" << std::endl;
        capacity = capacity * SCALE_FACTOR;
        T* newArray = new T[capacity];
        int newArrayIndex = 0;
        for (unsigned int i = front; i <= back; ++i) {
            newArray[newArrayIndex++] = array[i];
        }
        int tempFront = front;
        front = 0;
        back = back - tempFront;
        delete[] array;
        array = newArray;
    }
    void shrink() {
        // std::cout << "SHRINK HIT" << std::endl;
        int newSize = static_cast<double>(capacity) / SCALE_FACTOR;
        capacity = newSize;
        T* newArray = new T[newSize];
        int newArrayIndex = 0;
        for (unsigned int i = front; i < back; ++i) {
            newArray[newArrayIndex++] = array[i];
        }
        unsigned int tempFront = front;
        front = 0;
        back = back - tempFront;
        delete[] array;
        array = newArray;
    }
};

