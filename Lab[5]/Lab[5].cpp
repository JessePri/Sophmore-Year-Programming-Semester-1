
#include <vector>
#include <string>
#include <fstream>

class ShipDataList
{
public:
    ShipDataList() = delete;
    ShipDataList(const char *fileName);
    ShipDataList(std::vector<const char *> fileNames);

    // Printer Functions
    void PrintAllShips();
    void PrintMostPowerfulWeaponShip();
    void PrintMostPowerfulShip();
    void PrintWeakestShip();
    void PrintUnarmedShip();
private:
    struct ShipData
    {
        struct Weapon
        {
            Weapon() : name(""), powerLevel(0), powerConsumption(0) {}
            std::string name;
            unsigned int powerLevel;
            float powerConsumption;

            void Print();
        };

        ShipData() : name(""), shipClass(""), length(0), shieldCapacity(0), maxWarp(0), inventory{} {}
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
    void ReadShip(std::ifstream &stream);

    // Helpers For the ReadShip Function
    /* Reads the name of the ship */
    void ReadName(std::ifstream &stream, ShipData &shipData);
    /* Reads the class of the ship */
    void ReadClass(std::ifstream &stream, ShipData &shipData);
    /* Reads the length of the ship */
    void ReadLengthCapacitySpeed(std::ifstream &stream, ShipData &shipData);
    /* Reads the inventory of the ship */
    void ReadInventory(std::ifstream &stream, ShipData &shipData);


};

#include <iostream>

using std::cout;
using std::endl;
using std::ifstream;
using std::ios_base;
using std::string;
using std::vector;

ShipDataList::ShipDataList(const char *fileName)
{
    ifstream file(fileName, ios_base::binary);
    if (!file.is_open())
    {
        cout << "There was an error opening the file..." << endl;
    }
    unsigned int shipCount;
    file.read((char *)&shipCount, 4);
    for (unsigned int i = 0; i < shipCount; ++i)
    {
        ReadShip(file);
    }
}

ShipDataList::ShipDataList(std::vector<const char *> fileNames)
{
    for (const char *fileName : fileNames)
    {
        ifstream file(fileName, ios_base::binary);
        if (!file.is_open())
        {
            cout << "There was an error opening the file..." << endl;
        }
        unsigned int shipCount;
        file.read((char *)&shipCount, 4);
        for (unsigned int i = 0; i < shipCount; ++i)
        {
            ReadShip(file);
        }
    }
}

void ShipDataList::ReadShip(ifstream &file)
{
    shipDataList.emplace_back();
    ReadName(file, shipDataList.back());
    ReadClass(file, shipDataList.back());
    ReadLengthCapacitySpeed(file, shipDataList.back());
    ReadInventory(file, shipDataList.back());
}

void ShipDataList::ReadName(ifstream &file, ShipData &shipData)
{
    unsigned int size;
    file.read((char *)&size, 4);
    char *cstr = new char[size];
    file.read(cstr, size);
    shipData.name = cstr;
    delete[] cstr;
}

void ShipDataList::ReadClass(ifstream &file, ShipData &shipData)
{
    unsigned int size;
    file.read((char *)&size, 4);
    char *cstr = new char[size];
    file.read(cstr, size);
    shipData.shipClass = cstr;
    delete[] cstr;
}

void ShipDataList::ReadLengthCapacitySpeed(ifstream &file, ShipData &shipData)
{
    file.read((char *)&shipData.length, 2);
    file.read((char *)&shipData.shieldCapacity, 4);
    file.read((char *)&shipData.maxWarp, 4);
}

void ShipDataList::ReadInventory(ifstream &file, ShipData &shipData)
{
    unsigned int count;
    file.read((char *)&count, 4);
    for (unsigned int i = 0; i < count; ++i)
    {
        shipData.inventory.emplace_back();
        unsigned int nameSize;
        file.read((char *)&nameSize, 4);
        char *cstr = new char[nameSize];
        file.read(cstr, nameSize);
        unsigned int powerLevel;
        float powerConsumption;
        file.read((char *)&powerLevel, 4);
        file.read((char *)&powerConsumption, 4);
        shipData.inventory.back().name = cstr;
        shipData.inventory.back().powerLevel = powerLevel;
        shipData.inventory.back().powerConsumption = powerConsumption;
        delete[] cstr;
    }
}

void ShipDataList::ShipData::Weapon::Print()
{
    cout << name << ", " << powerLevel << ", " << powerConsumption << endl;
}

void ShipDataList::ShipData::Print()
{
    cout << "Name: " << name << endl;
    cout << "Class: " << shipClass << endl;
    cout << "Length: " << length << endl;
    cout << "Shield capacity: " << shieldCapacity << endl;
    cout << "Maximum Warp: " << maxWarp << endl;
    cout << "Armaments:" << endl;
    if (inventory.size() == 0)
    {
        cout << "Unarmed" << endl;
    }
    else
    {
        for (Weapon weapon : inventory)
        {
            weapon.Print();
        }
        cout << "Total firepower: " << TotalPowerOfInventory() << endl;
    }
}

unsigned int ShipDataList::ShipData::MostPowerfulWeapon()
{
    unsigned int size = inventory.size();
    if (size == 0)
    {
        return 0;
    }
    unsigned int maxPowerLevel = inventory[0].powerLevel;
    for (unsigned int i = 0; i < size; ++i)
    {
        unsigned int powerLevel = inventory[i].powerLevel;
        if (powerLevel > maxPowerLevel)
        {
            maxPowerLevel = powerLevel;
        }
    }
    return maxPowerLevel;
}

unsigned int ShipDataList::ShipData::TotalPowerOfInventory()
{
    unsigned int size = inventory.size();
    unsigned int totalPower = 0;
    for (unsigned int i = 0; i < size; ++i)
    {
        totalPower += inventory[i].powerLevel;
    }
    return totalPower;
}

void ShipDataList::PrintAllShips()
{
    for (ShipData shipData : shipDataList)
    {
        shipData.Print();
        cout << endl;
    }
}

void ShipDataList::PrintMostPowerfulWeaponShip()
{
    ShipData mostPowerfulWeaponShip = shipDataList[0];
    unsigned int size = shipDataList.size();
    for (unsigned int i = 0; i < size; ++i)
    {
        unsigned int maxPowerLevel = mostPowerfulWeaponShip.MostPowerfulWeapon();
        unsigned int powerLevel = shipDataList[i].MostPowerfulWeapon();
        if (powerLevel > maxPowerLevel)
        {
            mostPowerfulWeaponShip = shipDataList[i];
        }
    }
    mostPowerfulWeaponShip.Print();
    cout << endl;
}

void ShipDataList::PrintMostPowerfulShip()
{
    ShipData mostPowerfulShip = shipDataList[0];
    unsigned int size = shipDataList.size();
    for (unsigned int i = 0; i < size; ++i)
    {
        unsigned int maxPowerLevel = mostPowerfulShip.TotalPowerOfInventory();
        unsigned int powerLevel = shipDataList[i].TotalPowerOfInventory();
        if (powerLevel > maxPowerLevel)
        {
            mostPowerfulShip = shipDataList[i];
        }
    }
    mostPowerfulShip.Print();
    cout << endl;
}

void ShipDataList::PrintWeakestShip()
{
    ShipData leastPowerfulShip = shipDataList[0];
    unsigned int size = shipDataList.size();
    for (unsigned int i = 0; i < size; ++i)
    {
        if (shipDataList[i].inventory.size() == 0) {
            continue;
        }
        unsigned int minPowerLevel = leastPowerfulShip.TotalPowerOfInventory();
        unsigned int powerLevel = shipDataList[i].TotalPowerOfInventory();
        if (powerLevel < minPowerLevel)
        {
            leastPowerfulShip = shipDataList[i];
        }
    }
    leastPowerfulShip.Print();
    cout << endl;
}

void ShipDataList::PrintUnarmedShip()
{
    for (ShipData shipData : shipDataList)
    {
        if (shipData.inventory.size() == 0)
        {
            shipData.Print();
            cout << endl;
        }
    }
}


using namespace std;

int main()
{
    cout << "Which file(s) to open?\n";
    cout << "1. friendlyships.shp" << endl;
    cout << "2. enemyships.shp" << endl;
    cout << "3. Both files" << endl;
    int option;
    vector<const char *> fileNames;
    fileNames.emplace_back("friendlyships.shp");
    fileNames.emplace_back("enemyships.shp");
    cin >> option;
    ShipDataList *list;

    /* Load files here */
    if (option == 1)
    {
        list = new ShipDataList("friendlyships.shp");
    }
    else if (option == 2)
    {
        list = new ShipDataList("enemyships.shp");
    }
    else if (option == 3)
    {
        list = new ShipDataList(fileNames);
    }
    cout << "1. Print all ships" << endl;
    cout << "2. Starship with the strongest weapon" << endl;
    cout << "3. Strongest starship overall" << endl;
    cout << "4. Weakest ship (ignoring unarmed)" << endl;
    cout << "5. Unarmed ships" << endl;

    cin >> option;

    /* Work your magic here */
    if (option == 1) {
        list->PrintAllShips();
    } else if (option == 2) {
        list->PrintMostPowerfulWeaponShip();
    } else if (option == 3) {
        list->PrintMostPowerfulShip();
    } else if (option == 4) {
        list->PrintWeakestShip();
    } else if (option == 5) {
        list->PrintUnarmedShip();
    } 
    return 0;
}