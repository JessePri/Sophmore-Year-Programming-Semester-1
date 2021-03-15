#ifndef SHOWROOM
#define SHOWROOM
#include "Vehicle.h"
#include <string>
#include <vector>

class Showroom {
private:
    std::string name;
    std::vector<Vehicle> vehicles;
    unsigned int maxCapacity;
public:
    Showroom(std::string newName = "Unnamed Showroom", unsigned int newCapacity = 0):
        name(newName), maxCapacity(newCapacity) {}
    std::vector<Vehicle> GetVehicleList();
    void AddVehicle(Vehicle v);
    void ShowInventory();
    float GetInventoryValue();
};


#endif