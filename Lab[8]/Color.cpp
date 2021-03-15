#include "Color.h"

using std::string;

Color::Color(string name, int value) {
    SetValue(value);
    SetName(name.c_str());
}

void Color::SetName(const char* name) {
    this->name = name;
}

void Color::SetValue(int value) {
    this->value = value;
    SetRGB();
    SetHex();
}

void Color::SetRGB() {
    red = (value >> 16) & 255;
    green = (value >> 8) & 255;
    blue = (value) & 255;
}

void Color::SetHex() {
    unsigned short r1 = red % 16;
    unsigned short r2 = red / 16;

    unsigned short g1 = green % 16;
    unsigned short g2 = green / 16;

    unsigned short b1 = blue % 16;
    unsigned short b2 = blue / 16;

    hex = "0x" + hexVec[r2] + hexVec[r1]
        + hexVec[g2] + hexVec[g1]
        + hexVec[b2] + hexVec[b1];
}

unsigned char Color::GetR() const {
    return red;
}

unsigned char Color::GetG() const {
    return green;
}

unsigned char Color::GetB() const {
    return blue;
}

string Color::GetHexValue() const {
    return hex;
}

string Color::GetName() const {
    return name;
}

