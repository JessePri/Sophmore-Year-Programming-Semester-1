// Lab 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ABS.h"
#include  "ABQ.h"

using std::cout;
using std::endl;

template<typename T>
void print(ABS<T> stack);
template<typename T>
void print(ABQ<T> queue);
int main() {
    // ABS<int> stack;
    // for (unsigned int i = 1; i <= 10; ++i) {
    //     stack.push(i);
    // }
    // print(stack);
    // for (unsigned int i = 0; i < 9; ++i) {
    //     cout << stack.pop() << endl;
    // }
    // print(stack);
    ABQ<int> queue;
    print(queue);
    for (unsigned int i = 0; i < 10; ++i) {
        queue.enqueue(i);
        print(queue);
    }
    
    cout << "------------------------------------" << endl;
    for (unsigned int i = 0; i < 9; ++i) {
        cout << queue.dequeue() << endl;
        cout << "Capacity: " << queue.getMaxCapacity() << endl;
        print(queue);
    }
    
}

template<typename T>
void print(ABS<T> stack) {
    T* array = stack.getData();
    unsigned int size = stack.getSize();
    for (unsigned int i = 0; i < size; ++i) {
        cout << array[i] << ", ";
    }
    cout << endl;
}
template<typename T>
void print(ABQ<T> queue) {
    T* array = queue.getData();
    unsigned int back = queue.getBack();
    for (unsigned int i = queue.getFront(); i < back; ++i) {
        cout << array [i] << ", ";
    }
    cout << endl;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
