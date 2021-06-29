#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>
using namespace std;

// Class Car - Car specification
class Car
{
private:
    string carName;
    int maxPower;
    int maxSpeed;
    float acceleration;

public:
    Car()
    {
        this->carName = "Unknown";
        this->maxPower = 0;
        this->maxSpeed = 0;
        this->acceleration = 0;
    }
    Car(string _carName, int _maxPower, int _maxSpeed, float _acceleration)
    {
        this->carName = _carName;
        this->maxPower = _maxPower;
        this->maxSpeed = _maxSpeed;
        this->acceleration = _acceleration;
    }
    string getCarName()
    {
        return this->carName;
    }
    void display()
    {
        cout << "CAR NAME:" << setw(43) << this->carName << endl;
        cout << "MAX. POWER:" << setw(31) << this->maxPower << " kW at 8.500 rpm" << endl;
        cout << "TOP SPEED:" << setw(30) << ">" << this->maxSpeed << " km/h" << endl;
        cout << "ACCELERATION 0-100 KM/H (MPH 0-62):" << setw(7) << this->acceleration << " s" << endl;
    }
};

// Class CustomerInvoice - Car rental customer invoice
class CustomerInvoice
{
private:
    int invoiceNumber;
    string name, carModel, licensePlate;
    int numOfDays;
    int price;

public:
    CustomerInvoice(string _name, string _carModel, int _numOfDays)
    {
        this->name = _name;
        this->carModel = _carModel;
        this->numOfDays = _numOfDays;
    }
    int getInvoiceNumber()
    {
        srand(time(NULL));
        this->invoiceNumber = rand();
        return this->invoiceNumber;
    }
    string getName()
    {
        return this->name;
    }
    string getCarModel()
    {
        return this->carModel;
    }
    int getNumOfDays()
    {
        return this->numOfDays;
    }
    string getLicensePlate()
    {
        srand(time(NULL));
        int num1 = rand() % (99 - 10 + 1) + 10;
        int num2 = rand() % (999 - 100 + 1) + 10;
        int num3 = rand() % (99 - 10 + 1) + 10;
        char character = 'A' + rand() % 26;
        string str;
        stringstream ss;
        ss << character;
        str = ss.str();
        this->licensePlate = to_string(num1) + str + "-" + to_string(num2) + "." + to_string(num3);
        return this->licensePlate;
    }
    int getPrice()
    {
        int res;
        if (this->carModel == "AVENTADOR SVJ")
            res = 10000;
        else if (this->carModel == "HURACAN EVO")
            res = 9000;
        else if (this->carModel == "812 GTS")
            res = 9500;
        else if (this->carModel == "SF90 SPIDER")
            res = 8500;
        else if (this->carModel == "MODEL S")
            res = 7000;
        else if (this->carModel == "MODEL 3")
            res = 6500;
        return res * this->numOfDays;
    }
    void displayInvoice()
    {
        cout << "Car Rental - Customer Invoice" << endl;
        cout << "////////////////////////////////////////////" << endl;
        cout << "Invoice No. :---------------| " << getInvoiceNumber() << endl;
        cout << "Customer Name :-------------| " << getName() << endl;
        cout << "Car Model :-----------------| " << getCarModel() << endl;
        cout << "License plate :-------------| " << getLicensePlate() << endl;
        cout << "Number of days :------------| " << getNumOfDays() << endl;
        cout << "-------------------------------------------" << endl;
        cout << "Total rental amount :-------| " << getPrice() << endl;
    }
};

void showSelection()
{
    cout << "Please select a car brand" << endl;
    cout << "1. Lamborghini" << endl;
    cout << "2. Ferrari" << endl;
    cout << "3. Tesla" << endl;
}

void LamborghiniModel()
{
    cout << "All Lamborghini models available" << endl;
    cout << "1. AVENTADOR SVJ - $10000/day" << endl;
    cout << "2. HURACAN EVO - $9000/day" << endl;
}

void FerrariModel()
{
    cout << "All Ferrari models available" << endl;
    cout << "1. 812 GTS - $9500/day" << endl;
    cout << "2. SF90 SPIDER - $8500/day" << endl;
}

void TeslaModel()
{
    cout << "All Tesla models available" << endl;
    cout << "1. MODEL S - $7000/day" << endl;
    cout << "2. MODEL 3 - $6500/day" << endl;
}

int main()
{
    string name;
    int choice, choiceModel, days;
    // -----------Name-----------
    cout << "Enter your name: ";
    cin >> name;
    showSelection();
    cin >> choice;
    // -----------Car Rental System-----------
    Car *obj;
    switch (choice)
    {
    case 1:
        cout << "You have chosen Lamborghini brand" << endl;
        LamborghiniModel();
        cin >> choiceModel;
        switch (choiceModel)
        {
        case 1:
            obj = new Car("AVENTADOR SVJ", 566, 350, 2.8);
            break;
        case 2:
            obj = new Car("HURACAN EVO", 470, 325, 2.9);
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
        break;
    case 2:
        cout << "You have chosen Ferrari brand" << endl;
        FerrariModel();
        cin >> choiceModel;
        switch (choiceModel)
        {
        case 1:
            obj = new Car("812 GTS", 588, 340, 3.0);
            break;
        case 2:
            obj = new Car("SF90 SPIDER", 574, 340, 2.5);
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
        break;
    case 3:
        cout << "You have chosen Tesla brand" << endl;
        TeslaModel();
        cin >> choiceModel;
        switch (choiceModel)
        {
        case 1:
            obj = new Car("MODEL S", 761, 322, 2);
            break;
        case 2:
            obj = new Car("MODEL 3", 250, 261, 3.2);
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
        break;
    default:
        cout << "Invalid choice!" << endl;
        break;
    }
    obj->display();
    // -----------Days Renting-----------
    cout << "Number of days for renting: ";
    cin >> days;
    CustomerInvoice cusIn(name, obj->getCarName(), days);
    cusIn.displayInvoice();
    delete obj;
}