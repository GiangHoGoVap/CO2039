#include <iostream>
using namespace std;

class Account
{
private:
    float balance;

public:
    Account()
    {
        this->balance = 0;
    }
    Account(float _balance)
    {
        this->balance = _balance;
    }
    void deposit(float amount)
    {
        this->balance += amount;
    }
    bool withdraw(float amount)
    {
        if (this->balance < amount)
        {
            this->balance -= 5;
            return false;
        }
        else
        {
            this->balance -= amount;
            return true;
        }
    }
    float inquire()
    {
        return this->balance;
    }
};

int main()
{
    Account obj1(200);
    cout << obj1.withdraw(60) << endl;
    cout << obj1.inquire() << endl;
    Account obj2;
    obj2.deposit(300);
    cout << obj2.withdraw(301) << endl;
    cout << obj2.inquire() << endl;
    return 0;
}