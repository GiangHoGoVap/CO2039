#include <iostream>
#include <iomanip>
using namespace std;

class Car
{
    float fuelEfficiency;
    float fuelAmount;

public:
    Car(float _fuelEfficiency = 0, float _fuelAmount = 0) : fuelEfficiency(_fuelEfficiency), fuelAmount(_fuelAmount) {}
    void drive(float distance)
    {
        this->fuelAmount -= (distance / fuelEfficiency);
    }
    float getFuelLevel()
    {
        return this->fuelAmount;
    }
    void tank(float amount)
    {
        this->fuelAmount += amount;
    }
};

int main()
{
    Car myBeemer(29);
    cout << myBeemer.getFuelLevel() << endl;
    myBeemer.tank(20);
    cout << myBeemer.getFuelLevel() << endl;
    myBeemer.drive(100);
    cout << myBeemer.getFuelLevel() << endl;
    return 0;
}