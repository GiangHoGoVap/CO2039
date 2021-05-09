#include <iostream>
#include <vector>
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
    virtual void credit(double amount)
    {
        this->balance += amount;
    }
    virtual void debit(double amount)
    {
        if (amount > this->balance)
        {
            cout << "Debit amount exceeded account balance." << endl;
            return;
        }

        this->balance -= amount;
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
        this->balance += amount - fee;
    }
    void debit(double amount)
    {
        if (amount > this->balance)
        {
            cout << "Debit amount exceeded amount balance." << endl;
            return;
        }
        this->balance -= amount - fee;
    }
};

int main()
{
    double debit, credit;
    Account *obj1 = new Account(60);
    SavingsAccount *obj2 = new SavingsAccount(65, 3);
    CheckingAccount *obj3 = new CheckingAccount(45, 10);
    vector<Account *> v;
    v.push_back(obj1);
    v.push_back((Account *)obj2);
    v.push_back((Account *)obj3);
    for (auto p : v)
    {
        cout << "Enter the amount to debit:" << endl;
        cin >> debit;
        p->debit(debit);
        cout << "Enter the amount to credit:" << endl;
        cin >> credit;
        p->credit(credit);
        SavingsAccount *savingsAccountPtr = dynamic_cast<SavingsAccount *>(p);
        if (savingsAccountPtr)
        {
            p->credit(savingsAccountPtr->calculateInterest());
        }
        cout << "Account balance: " << p->getBalance() << endl;
        cout << "---------------" << endl;
    }
    delete obj1;
    delete obj2;
    delete obj3;
    return 0;
}
