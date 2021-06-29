#include <iostream>
#include <iomanip>
using namespace std;

class Employee2
{
private:
    char *name;
    float HourlyWage, WorkedHours, ExtraHours;

public:
    Employee2()
    {
        this->name = new char[256];
    }
    ~Employee2()
    {
        delete name;
    }
    float wageCalculator()
    {
        float payment = 0;
        cout << "Please enter employee's name than press Enter: ";
        cin.getline(name, 256);
        cout << "Please enter hourly wage than press Enter: ";
        cin >> this->HourlyWage;
        cout << "Please enter hours worked than press Enter: ";
        cin >> this->WorkedHours;
        cout << " Paycheck for employee " << this->name << endl;
        cout << endl;
        cout << " Hours worked: " << setprecision(1) << fixed << this->WorkedHours << endl;
        cout << " Hours wage: " << setprecision(1) << fixed << this->HourlyWage << endl;
        cout << endl;
        payment += (this->WorkedHours * this->HourlyWage);
        if (this->WorkedHours > 40)
        {
            this->ExtraHours = this->WorkedHours - 40;
            cout << " Overtime hours: " << setprecision(1) << fixed << this->ExtraHours << endl;
            cout << " Overtime hourly wage: " << setprecision(1) << fixed << (1.5 * this->HourlyWage) << endl;
            payment += (1.5 * this->HourlyWage * this->ExtraHours);
        }
        return payment;
    }
};

int main()
{
    Employee2 obj;
    float payment = obj.wageCalculator();
    cout << " Total payment: " << setprecision(1) << fixed << payment << endl;
    return 0;
}