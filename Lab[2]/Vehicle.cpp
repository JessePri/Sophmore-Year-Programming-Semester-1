#include "Vehicle.h"
#include <iostream>
using std::cout;
using std::string;
using std::endl;
using std::to_string;

Vehicle::Vehicle(string _make, string _model, int _year, float _price, int _miles):
    make(_make), model(_model), year(_year), price(_price), miles(_miles) {}

string Vehicle::GetYearMakeModel() {
    string toReturn = to_string(year) + " " + make + " " + model;
    return toReturn;
}

void Vehicle::Display() { 
    cout << GetYearMakeModel() << " $" << price << " " << miles << endl;
}

float Vehicle::GetPrice() {
    return price;
}