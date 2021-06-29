#include <iostream>
using namespace std;

class Rectangle
{
private:
    float length, width;

public:
    void setLength(float _length)
    {
        this->length = _length;
    }
    void setWidth(float _width)
    {
        this->width = _width;
    }
    float perimeter()
    {
        return 2 * (this->length + this->width);
    }
    float area()
    {
        return this->length * this->width;
    }
    void show()
    {
        cout << "Length: " << this->length << endl;
        cout << "Width: " << this->width << endl;
    }
    int sameArea(Rectangle &obj)
    {
        if (this->area() == obj.area())
            return 1;
        return 0;
    }
};

int main()
{
    Rectangle obj1;
    obj1.setLength(4.5);
    obj1.setWidth(5);
    cout << obj1.perimeter() << " " << obj1.area() << endl;
    Rectangle obj2;
    obj2.setLength(2.5);
    obj2.setWidth(3);
    cout << obj2.perimeter() << " " << obj2.area() << endl;
    cout << obj1.sameArea(obj2) << endl;
    return 0;
}