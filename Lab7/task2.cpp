#include <iostream>
using namespace std;

struct Coordinate {
    float X;
    float Y;

    Coordinate() {}

    Coordinate(float x, float y) : X(x), Y(y) {}
};

class Shape {
    public:
    Coordinate position;
    string color;
    float borderThickness;

    Shape (Coordinate c, string color, float b) : position(c), color(color), borderThickness(b) {}

    Shape (Coordinate c, string color) : position(c), color(color), borderThickness(0) {}

    virtual void draw () {
        cout << "Drawing\n";
    }

    virtual float calculateArea () {
        cout << "Calculating Area\n";
        return 0;
    }

    virtual float calculatePerimeter () {
        cout << "Calculating Perimeter\n";
        return 0;
    }
};

class Circle : public Shape {
    public:
    float radius;
    Coordinate centerPos;

    Circle (Coordinate c, float b, string color, float r) : Shape(c,color,b), centerPos(c), radius(r) {}

    Circle (Coordinate c, string color, float r) : Shape(c,color), centerPos(c), radius(r) {}

    void draw () override {
        cout << "Drawing a circle\n";
    }

    float calculateArea () override {
        return (3.142 * radius * radius);
    }

    float calculatePerimeter () override {
        return (2 * 3.142 * radius);
    }
};

class Rectangle : public Shape {
    public:
    float width, height;
    Coordinate topLeftPos;

    Rectangle (Coordinate c, float b, string color, float w, float h) : Shape(c,color,b), topLeftPos(c), width(w), height(h) {}

    Rectangle (Coordinate c, string color, float w, float h) : Shape(c,color), topLeftPos(c), width(w), height(h) {}

    void draw () override {
        cout << "Drawing a rectangle\n";
    }

    float calculateArea () override {
        return (width * height);
    }

    float calculatePerimeter () override {
        return (2 * (width + height));
    }
};

class Triangle : public Shape {
    public:
    float base;
    float height;
    float side2;
    float side3;
    Coordinate leftBasePos;

    Triangle (Coordinate c, float b, string color, float base, float h, float s2, float s3) : Shape(c,color,b), leftBasePos(c), 
    base(base), height(h), side2(s2), side3(s3) {}

    Triangle (Coordinate c, string color, float base, float h, float s2, float s3) : Shape(c,color), leftBasePos(c), 
    base(base), height(h), side2(s2), side3(s3) {}

    void draw () override {
        cout << "Drawing a triangle\n";
    }

    float calculateArea () override {
        return (0.5 * base * height);
    }

    float calculatePerimeter () override {
        return (base + side2 + side3);
    }
};

int main () {
    Coordinate origin (0,0);

    Circle circle (origin, 2, "Blue", 13);
    circle.draw();
    cout << circle.calculateArea() << endl;

    Rectangle rect (origin, "red", 11, 12);
    cout << rect.calculatePerimeter() << endl;
}
