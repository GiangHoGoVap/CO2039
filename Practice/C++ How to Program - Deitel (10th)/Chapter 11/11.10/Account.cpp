#include <iostream>
using namespace std;

class Account
{
protected:
    double balance;

public:
    Account()
    {
        this->balance = 0;
    }
    Account(double _balance)
    {
        if (_balance < 0)
        {
            this->balance = 0;
            cout << "Balance was invalid." << endl;
        }
        else
            this->balance = _balance;
    }
    void credit(double amount)
    {
        this->balance += amount;
    }
    bool debit(double amount)
    {
        if (amount > this->balance)
        {
            cout << "Debit amount exceeded account balance." << endl;
            return false;
        }

        this->balance -= amount;
        return true;
    }
    double getBalance()
    {
        return this->balance;
    }
};

class SavingsAccount : public Account
{
protected:
    double interestRate;

public:
    SavingsAccount()
    {
        this->balance = 0;
        this->interestRate = 0;
    }
    SavingsAccount(double _balance, double _interestRate)
    {
        this->balance = _balance;
        this->interestRate = _interestRate;
    }
    double calculateInterest()
    {
        return this->balance * ((this->interestRate) / 100);
    }
};

class CheckingAccount : public Account
{
protected:
    double fee;

public:
    CheckingAccount()
    {
        this->balance = 0;
        this->fee = 0;
    }
    CheckingAccount(double _balance, double _fee)
    {
        this->balance = _balance;
        this->fee = _fee;
    }
    void credit(double amount)
    {
        Account ::credit(amount);
        this->balance -= fee;
    }
    void debit(double amount)
    {
        bool flag = Account ::debit(amount);
        if (flag)
        {
            this->balance -= fee;
        }
    }
};

int main()
{
    SavingsAccount obj1(50.0, 3);
    double interest = obj1.calculateInterest();
    obj1.credit(interest);
    cout << obj1.getBalance() << endl;

    Account obj2(45.0);
    obj2.credit(15);
    cout << obj2.debit(70) << endl;
    cout << obj2.getBalance() << endl;

    CheckingAccount obj3(60.0, 5);
    obj3.credit(15);
    obj3.debit(30);
    cout << obj3.getBalance() << endl;
    return 0;
}