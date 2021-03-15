#ifndef VEHICLE
#define VEHICLE

#include <string>

class Vehicle {

private:
   std::string make;
   std::string model;
   unsigned int year;
   float price;
   unsigned int miles;

public:
   Vehicle(std::string _make = "COP3503", std::string _model = "Rust Bucket" , int _year = 1900, float _price = 0, int _miles = 0);
   void Display();
   std::string GetYearMakeModel();
   float GetPrice();

};

#endif