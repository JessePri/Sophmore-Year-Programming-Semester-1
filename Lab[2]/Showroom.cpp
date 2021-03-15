#include "Showroom.h"
#include <iostream>
using std::cout;
using std::vector;
using std::string;
using std::endl;

vector<Vehicle> Showroom::GetVehicleList() {
    return vehicles;
}

void Showroom::AddVehicle(Vehicle v) {
    if (vehicles.size() == maxCapacity) {
        cout << "Showroom is full! Cannot add " << v.GetYearMakeModel() << endl;
    } else {
        vehicles.push_back(v);
    }
}

void Showroom::ShowInventory() {
    if (vehicles.empty()) {
        cout << name << " is empty!" << endl;
        return;
    }
    cout << "Vehicles in " << name << endl;
    for (Vehicle v : vehicles) {
        v.Display();
    }
}

float Showroom::GetInventoryValue() {
    float sum = 0;
    for (Vehicle v : vehicles) {
        sum += v.GetPrice();
    }
    return sum;
}