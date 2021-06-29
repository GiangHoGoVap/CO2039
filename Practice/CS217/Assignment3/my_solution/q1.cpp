#include <iostream>
#include <iomanip>
using namespace std;

class Employee
{
    char *name;
    double salary;

public:
    Employee()
    {
        this->name = NULL;
        this->salary = 0;
    }
    Employee(char *_name, double _salary)
    {
        this->name = _name;
        this->salary = _salary;
    }
    char *getName()
    {
        return this->name;
    }
    double getSalary()
    {
        return this->salary;
    }
};

void TestEmployee(Employee obj)
{
    cout << "New employee has been created." << endl;
    cout << "Name of employee: " << obj.getName() << endl;
    cout << "Salary: " << setprecision(1) << fixed << obj.getSalary() << endl;
    cout << "Thank you for testing structure Employee." << endl;
}

int main()
{
    char *name = new char[256];
    double salary;
    cout << "Creating a new employee." << endl;
    cout << "Please type the name:" << endl;
    cin.getline(name, 256);
    cout << "Please specify the salary: ";
    cin >> salary;
    Employee obj(name, salary);
    TestEmployee(obj);
    delete name;
    return 0;
}