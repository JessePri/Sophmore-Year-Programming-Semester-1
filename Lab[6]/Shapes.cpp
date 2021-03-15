#include "Shapes.h"
#include <iostream>
using std::cout;
using std::endl;
using std::string;

void Shape2D::ShowArea() const {
    cout << "The area of the " << GetName2D() << " is : " << Area();
}

bool Shape2D::operator>(const Shape2D& rhs) const {
    return Area() > rhs.Area();
}

bool Shape2D::operator<(const Shape2D& rhs) const {
    return Area() < rhs.Area();
}

bool Shape2D::operator==(const Shape2D& rhs) const {
    return Area() == rhs.Area();
}



/* Square class */

Square::Square(float newSide) {
    side = newSide;
}

float Square::Area() const {
    return side * side;
}

string Square::GetName2D() const {
    return "Square";
}

void Square::Scale(float scaleFactor) {
    side *= scaleFactor;
}

void Square::Display() const {
    cout << "The area of the Square is : " << Area() << endl;
    cout << "Length of a side: " << side << endl;
}

/* Triangle class */

Triangle::Triangle(float newBase, float newHeight) {
    base = newBase;
    height = newHeight;
}

float Triangle::Area() const {
    return 0.5f * base * height;
}

string Triangle::GetName2D() const {
    return "Triangle";
}

void Triangle::Scale(float scaleFactor) {
    base *= scaleFactor;
    height *= scaleFactor;
}

void Triangle::Display() const {
    cout << "The area of the Triangle is : " << Area() << endl;
    cout << "Base: " << base << endl;
    cout << "Height: " << height << endl;
}

/* newRadius class */ 

Circle::Circle(float newRadiues) {
    radius = newRadiues;
}

float Circle::Area() const {
    return PI * radius * radius;
}

void Circle::Display() const {
    cout << "The area of the Circle is : " << Area() << endl;
    cout << "Radius: " << radius << endl;
}

void Circle::Scale(float scaleFactor) {
    radius *= scaleFactor;
}

string Circle::GetName2D() const {
    return "Circle";
}
/* This section defines class functions for 3D shapes... */

/* 3D shape class */

void Shape3D::ShowVolume() const {
    cout << "The volume of the " << GetName3D() << " is : " << Volume() << endl;
}

bool Shape3D::operator>(const Shape3D& rhs) const {
    return Volume() > rhs.Volume();
}

bool Shape3D::operator<(const Shape3D& rhs) const {
    return Volume() < rhs.Volume();
}

bool Shape3D::operator==(const Shape3D& rhs) const {
    return Volume() == rhs.Volume();
}

/* TriangularPyramid class */

TriangularPyramid::TriangularPyramid(float pHeight, float base, float tHeight): Triangle(base, tHeight) {
    height = pHeight;
}

string TriangularPyramid::GetName3D() const {
    return "TriangularPyramid";
}

void TriangularPyramid::Scale(float scaleFactor) {
    Triangle::Scale(scaleFactor);
    height *= scaleFactor;
}

void TriangularPyramid::Display() const {
    cout << "The volume of the TriangularPyramid is : " << Volume() << endl;
    cout << "The height is: " << height;
    Triangle::Display();
}

float TriangularPyramid::Volume() const {
    return Triangle::Area() * (1.0f/3.0f) * height;
}



/* Cylinder class */

Cylinder::Cylinder(float cHeight, float radius): Circle(radius) {
    height = cHeight;
}

string Cylinder::GetName3D() const {
    return "Cylinder";
}

void Cylinder::Scale(float scaleFactor) {
    height *= scaleFactor;
    Circle::Scale(scaleFactor);
}

void Cylinder::Display() const {
    cout << "The volume of the Cylinder is : " << Volume() << endl;
    cout << "The height is: " << height << endl;
    Circle::Display();
}

float Cylinder::Volume() const {
    return Circle::Area() * height;
}

/* Sphere class */

Sphere::Sphere(float newRadius): Circle(newRadius) {
    radius = newRadius;
}

string Sphere::GetName3D() const {
    return "Sphere";
}

void Sphere::Scale(float scaleFactor) {
    radius *= scaleFactor;
    Circle::Scale(scaleFactor);
}

void Sphere::Display() const {
    cout << "The volume of the Sphere is : " << Volume() << endl;
    Circle::Display();
}

float Sphere::Volume() const{
    return (4.0f/3.0f) * PI * radius * radius * radius;
}








