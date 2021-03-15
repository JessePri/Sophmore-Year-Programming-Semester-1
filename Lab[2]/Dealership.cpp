#include "Dealership.h"
#include <iostream>
using std::endl;
using std::cout;
using std::vector;

void Dealership::AddShowroom(Showroom s) {
    if (showrooms.size() == maxCapacity) {
        cout << "Dealership is full, can't add another showroom!" << endl;
        return;
    } else {
        showrooms.push_back(s);
    }
}

float Dealership::GetAveragePrice() {
    float sumPrice = 0;
    unsigned int numVehicles = 0;
    for (Showroom s : showrooms) {
        vector<Vehicle> vehicles = s.GetVehicleList();
        for (Vehicle v : vehicles) {
            sumPrice += v.GetPrice();
            ++numVehicles;  
        }
    }
    if (numVehicles == 0) {
        return 0;
    }
    return sumPrice / numVehicles;
}

void Dealership::ShowInventory() {
    if (showrooms.empty()) {
        cout << name << " is empty!" << endl;
        cout << "Average car price: $" << GetAveragePrice();
        return; 
    }
    for (Showroom s : showrooms) {
        s.ShowInventory();
        cout << endl;
    }
    cout << "Average car price: $" << GetAveragePrice();
}