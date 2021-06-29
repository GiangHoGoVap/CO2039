#include <iostream>
#include <limits>
using namespace std;

class FlightInfo
{
private:
    int FlightNumber;
    char *Destination;
    float Distance;
    float Fuel;
    void calFuel()
    {
        if (this->Distance <= 1000)
            this->Fuel = 500;
        else if (this->Distance > 1000 && this->Distance <= 2000)
            this->Fuel = 1100;
        else
            this->Fuel = 2200;
    }

public:
    FlightInfo()
    {
        this->Destination = new char[256];
    }
    ~FlightInfo()
    {
        delete this->Destination;
    }
    void feedInfo()
    {
        cout << "Input flight number:" << endl;
        cin >> this->FlightNumber;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Input destination:" << endl;
        cin.getline(this->Destination, 256);
        cout << "Input distance:" << endl;
        cin >> this->Distance;
        calFuel();
    }
    void showInfo()
    {
        cout << "Flight number: " << this->FlightNumber << endl;
        cout << "Destination: " << this->Destination << endl;
        cout << "Distance: " << this->Distance << endl;
        cout << "Fuel: " << this->Fuel << endl;
    }
    float getFuel()
    {
        return this->Fuel;
    }
};

int main()
{
    FlightInfo obj;
    obj.feedInfo();
    obj.showInfo();
    cout << "Get fuel: " << obj.getFuel() << endl;
    return 0;
}