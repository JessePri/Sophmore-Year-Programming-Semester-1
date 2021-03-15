#pragma once

#include <string>
#include <array>

class Color {
public:
    // Given an integer, convert it to RBG and Hex values
    Color() = default;
    Color(std::string name, int value);

    void SetValue(int value);
    void SetName(const char* name);

    // Accessors

    unsigned char GetR() const;
    unsigned char GetG() const;
    unsigned char GetB() const;
    std::string GetHexValue() const;
    std::string GetName() const;

private:
    // Data
    unsigned int value = 0;
    unsigned char red = 0;
    unsigned char green = 0;
    unsigned char blue = 0;
    std::string hex = "";
    std::string name = "";

    // Helpers

    void SetRGB();
    void SetHex();

    //
    // Helper Data

    std::array<std::string, 16> hexVec {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F"};


};