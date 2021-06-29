#include <iostream>
#include <math.h>
using namespace std;

float pi = 3.141592653589793;

class Circle
{
    float radius;

public:
    Circle(float _radius = 0) : radius(_radius) {}
    float getArea()
    {
        return pi * pow(radius, 2);
    }
    float getCircumference()
    {
        return 2 * pi * radius;
    }
};

int main()
{
    float radius;
    cout << "Please specify the radius of your circle: ";
    cin >> radius;
    Circle obj(radius);
    cout << "Circle created." << endl;
    cout << "Area: " << obj.getArea() << endl;
    cout << "Circumference: " << obj.getCircumference() << endl;
    cout << "Good-bye!" << endl;
    return 0;
}