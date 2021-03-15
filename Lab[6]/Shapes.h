
#include <math.h>
#include <string>

const float PI = 3.14159f;

class Shape {
public:
    virtual void Scale(float scaleFactor) = 0;
    virtual void Display() const = 0;
    virtual ~Shape() {}
};



class Shape2D : virtual public Shape {
public:
    virtual float Area() const = 0;
    void ShowArea() const;
    virtual std::string GetName2D() const = 0;
    bool operator>(const Shape2D& rhs) const;
    bool operator<(const Shape2D& rhs) const;
    bool operator==(const Shape2D& rhs) const;
    virtual ~Shape2D() {}
};

/* 2D Shape Declarations */
class Square : public Shape2D {
public:
    Square(float newSide = 0);
    virtual std::string GetName2D() const override;
    virtual void Scale(float scaleFactor) override;
    virtual void Display() const override;
    virtual float Area() const override;
    virtual ~Square() {}
private:
    float side;   
};

class Triangle : public Shape2D {
public:
    Triangle(float newBase = 0, float newHeight = 0);
    virtual std::string GetName2D() const override;
    virtual void Scale(float scaleFactor) override;
    virtual void Display() const override;
    virtual float Area() const override;
    virtual ~Triangle() {}
private:
    float base;
    float height;
};

class Circle : public Shape2D {
public:
    Circle(float newRadius = 0);
    virtual std::string GetName2D() const override;
    virtual void Scale(float scaleFactor) override;
    virtual void Display() const override;
    virtual float Area() const override;
    virtual ~Circle() {}
private:
    float radius;
};

/* #################################################################################### */

class Shape3D : virtual public Shape {
public:
    virtual float Volume() const = 0;
    void ShowVolume() const;
    virtual std::string GetName3D() const = 0;
    bool operator>(const Shape3D& rhs) const;
    bool operator<(const Shape3D& rhs) const;
    bool operator==(const Shape3D& rhs) const;
    virtual ~Shape3D() {}
};

/* 3D Shape Definitions */

class TriangularPyramid: public Shape3D, private Triangle {
public:
    TriangularPyramid(float pHeight = 0, float base = 0, float height = 0);
    virtual std::string GetName3D() const override;
    virtual void Scale(float scaleFactor) override;
    virtual void Display() const override;
    virtual float Volume() const override;
    virtual ~TriangularPyramid() {}
private:
    float height;
};

class Cylinder: public Shape3D, private Circle {
public:
    Cylinder(float cHeight = 0, float height = 0);
    virtual std::string GetName3D() const override;
    virtual void Scale(float scaleFactor) override;
    virtual void Display() const override;
    virtual float Volume() const override;
    virtual ~Cylinder() {}
private:
    float height;
};

class Sphere: public Shape3D, private Circle {
public:
    Sphere(float newRadius = 0);
    virtual std::string GetName3D() const override;
    virtual void Scale(float scaleFactor) override;
    virtual void Display() const override;
    virtual float Volume() const override;
    virtual ~Sphere() {}
private:
    float radius;
};



