#include "ShipDataList.h"

#include <iostream>

using std::ios_base;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::vector;

ShipDataList::ShipDataList(const char* fileName) {
    ifstream file(fileName, ios_base::binary);
    if (!file.is_open()) {
        cout << "There was an error opening the file..." << endl;
    }
    unsigned int shipCount;
    file.read((char*)shipCount, 4);
    for (unsigned int i = 0; i < shipCount; ++i) {
        ReadShip(file);
    }
}

void ShipDataList::ReadShip(ifstream& file) {
    shipDataList.emplace_back();
    ReadName(file, shipDataList.back());
    ReadClass(file, shipDataList.back());
    ReadLengthCapacitySpeed(file, shipDataList.back());
    ReadInventory(file, shipDataList.back());
}

void ShipDataList::ReadName(ifstream& file, ShipData& shipData) {
    unsigned int size;
    file.read((char*)size, 4);
    char* cstr = new char[size];
    file.read(cstr, size);
    shipData.name = cstr;
    delete[] cstr;
}

void ShipDataList::ReadClass(ifstream& file, ShipData& shipData) {
    unsigned int size;
    file.read((char*)size, 4);
    char* cstr = new char[size];
    file.read(cstr, size);
    shipData.shipClass = cstr;
    delete[] cstr;
}

void ShipDataList::ReadLengthCapacitySpeed(ifstream& file, ShipData& shipData) {
    file.read((char*)shipData.length, 2);
    file.read((char*)shipData.shieldCapacity, 4);
    file.read((char*)shipData.maxWarp, 4);
}

void ShipDataList::ReadInventory(ifstream& file, ShipData& shipData) {
    unsigned int count;
    file.read((char*)count, 4);
    for (unsigned int i = 0; i < count; ++i) {
        shipData.inventory.emplace_back();
        unsigned int nameSize;
        file.read((char*)nameSize, 4);
        char* cstr = new char[nameSize];
        file.read(cstr, nameSize);
        unsigned int powerLevel;
        float powerConsumption;
        file.read((char*)powerLevel, 4);
        file.read((char*)powerConsumption, 4);
        shipData.inventory.back().name = cstr;
        shipData.inventory.back().powerLevel = powerLevel;
        shipData.inventory.back().powerConsumption = powerConsumption;
        delete[] cstr;
    }
}

void ShipDataList::ShipData::Weapon::Print() {
    cout << name << ", " << powerLevel << ", " << powerConsumption << endl;
}

void ShipDataList::ShipData::Print() {
    cout << "Name: " << name << endl;
    cout << "Class: " << shipClass << endl;
    cout << "Length: " << length << endl;
    cout << "Shield capacity: " << shieldCapacity << endl;
    cout << "Maximum Warp: " << maxWarp << endl;
    cout << "Armaments:" << endl;
    if (inventory.size() == 0) {
        cout << "Unarmed" << endl;
    } else {
        for (Weapon weapon : inventory) {
            weapon.Print();
        }
        cout << "Total firepower: " << TotalPowerOfInventory() << endl;
    }
}

unsigned int ShipDataList::ShipData::MostPowerfulWeapon() {
    unsigned int size = inventory.size();
    if (size == 0) {
        return 0;
    }
    unsigned int maxPowerLevel = inventory[0].powerLevel;
    for (int i = 0; i < size; ++i) {
        unsigned int powerLevel = inventory[i].powerLevel;
        if (powerLevel > maxPowerlevel) {
            maxPowerLevel = powerLevel;
        }
    }
    return maxPowerLevel;
}

unsigned int ShipDatList::ShipData::TotalPowerOfInventory() {
    unsigned int size = inventory.size();
    unsigned int totalPower = 0;
    for (int i = 0; i < size; ++i) {
        totalPower += inventory[i].powerLevel;
    }
    return totalPower;
}

void ShipDataList::PrintAllShips() {
    for (ShipData shipData : shipDataList) {
        shipData.Print();
        cout << endl;
    }
}

void ShipDataList::PrintMostPowerfulWeaponShip() {
    ShipData mostPowerfulWeaponShip = shipDataList[0];
    unsigned int size = shipDataList.size();
    for (unsigned int i = 0; i < size; ++i) {
        unsigned int maxPowerLevel = mostPowerfulWeaponShip.MostPowerfulWeapon();
        unsigned int powerLevel = shipDataList[i].MostPowerfulWeapon();
        if (powerlevel > maxPowerLevel) {
            mostPowerfulWeaponShip = shipDataList[i];
        }
    }
    mostPowerfulWeaponShip.Print();
    cout << endl;
}

void ShipDataList::PrintMostPowerfulShip() {
    ShipData mostPowerfulShip = shipDataList[0];
    unsigned int size = shipDataList.size();
    for (unsigned int i = 0; i < size; ++i) {
        unsigned int maxPowerLevel = mostPowerfulShip.TotalPowerOfInventory();
        unsigned int powerLevel = shipDataList[i].TotalPowerOfInventory();
        if (powerlevel > maxPowerLevel) {
            mostPowerfulShip = shipDataList[i];
        }
    }
    mostPowerfulShip.Print();
    cout << endl;
}

void ShipDataList::PrintWeakestShip() {
    ShipData leastPowerfulShip = shipDataList[0];
    unsigned int size = shipDataList.size();
    for (unsigned int i = 0; i < size; ++i) {
        unsigned int minPowerLevel = leastPowerfulShip.TotalPowerOfInventory();
        unsigned int powerLevel = shipDataList[i].TotalPowerOfInventory();
        if (powerlevel < minPowerLevel) {
            leastPowerfulShip = shipDataList[i];
        }
    }
    leastPowerfulShip.Print();
    cout << endl;
}

void ShipDataList::PrintUnarmedShip() {
    for (ShipData shipData : shipDataList) {
        if (shipData.inventory.size() == 0) {
            shipData.Print();
            cout << endl;
        }
    }
}


