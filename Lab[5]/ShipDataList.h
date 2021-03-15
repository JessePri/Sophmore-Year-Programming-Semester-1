#pragma once

#include <vector>
#include <string>
#include <fstream>

class ShipDataList {
public:
    ShipDataList() = delete;
    ShipDataList(const char* fileName);
private:
    struct ShipData {
        struct Weapon {
            Weapon(): name(""), powerLevel(0), powerConsumption(0) {}
            std::string name;
            unsigned int powerLevel;
            float powerConsumption;

            void Print();
        };

        ShipData(): name(""), shipClass(""), length(0), shieldCapacity(0), maxWarp(0), inventory{} {}
        // Helper Functions
        void Print();
        unsigned int MostPowerfulWeapon();
        unsigned int TotalPowerOfInventory();

        // Variables
        std::string name;
        std::string shipClass;
        unsigned short length;
        unsigned int shieldCapacity;
        float maxWarp;
        std::vector<Weapon> inventory;
    };

    // Variables
    std::vector<ShipData> shipDataList;

    // Helper Functions
    
    /* Handels reading the file to one ship */
    void ReadShip(std::ifstream& stream);


    // Helpers For the ReadShip Function
    /* Reads the name of the ship */
    void ReadName(std::ifstream& stream, ShipData& shipData);
    /* Reads the class of the ship */
    void ReadClass(std::ifstream& stream, ShipData& shipData);
    /* Reads the length of the ship */
    void ReadLengthCapacitySpeed(std::ifstream& stream, ShipData& shipData);
    /* Reads the inventory of the ship */
    void ReadInventory(std::ifstream& stream, ShipData& shipData);
    

    // Printer Functions
    void PrintAllShips();
    void PrintMostPowerfulWeaponShip();
    void PrintMostPowerfulShip();
    void PrintWeakestShip();
    void PrintUnarmedShip();
};

