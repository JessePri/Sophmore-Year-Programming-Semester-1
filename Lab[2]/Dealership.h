#ifndef DEALERSHIP
#define DEALERSHIP
#include "Showroom.h"




class Dealership {
private:
    std::vector<Showroom> showrooms;
    std::string name;
    unsigned int maxCapacity;
public:
    Dealership(std::string newName = "Generic Dealership", unsigned int newMaxCapacity = 0):
        name(newName), maxCapacity(newMaxCapacity) {}
    void AddShowroom(Showroom s);
    float GetAveragePrice();
    void ShowInventory();
};


#endif 