#include <iostream>
#include <limits>
using namespace std;

class Package
{
protected:
    string name, address, city, state, ZIP, senderAddress, recipientAddress;
    double weight, cost;

public:
    Package()
    {
        this->weight = 0;
        this->cost = 0;
    }
    Package(double _weight, double _cost)
    {
        if (_weight < 0 || _cost < 0)
        {
            cout << "Invalid weight/cost." << endl;
        }
        else
        {
            this->weight = _weight;
            this->cost = _cost;
        }
    }
    void setName(string _name)
    {
        this->name = _name;
    }
    void setAddress(string _address)
    {
        this->address = _address;
    }
    void setCity(string _city)
    {
        this->city = _city;
    }
    void setState(string _state)
    {
        this->state = _state;
    }
    void setZIP(string _ZIP)
    {
        this->ZIP = _ZIP;
    }
    void setSender(string _senderAddress)
    {
        this->senderAddress = _senderAddress;
    }
    void setRecipient(string _recipientAddress)
    {
        this->recipientAddress = _recipientAddress;
    }
    void setWeight(double _weight)
    {
        if (_weight < 0)
        {
            cout << "Invalid weight !" << endl;
            return;
        }
        this->weight = _weight;
    }
    void setCost(double _cost)
    {
        if (_cost < 0)
        {
            cout << "Invalid cost !" << endl;
            return;
        }
        this->cost = _cost;
    }
    double calculateCost(double _weight, double _cost)
    {
        return _weight * _cost;
    }
};

class TwoDayPackage : public Package
{
protected:
    double fee;

public:
    TwoDayPackage()
    {
        this->fee = 0;
    }
    TwoDayPackage(double _fee)
    {
        this->fee = _fee;
    }
    void setFee(double _fee)
    {
        this->fee = _fee;
    }
    double calculateCost(double _weight, double _cost)
    {
        return Package::calculateCost(_weight, _cost) + this->fee;
    }
};

class OvernightPackage : public Package
{
protected:
    double additionalFeePerOunce;

public:
    OvernightPackage()
    {
        this->additionalFeePerOunce = 0;
    }
    OvernightPackage(double _additionalFeePerOunce)
    {
        this->additionalFeePerOunce = _additionalFeePerOunce;
    }
    void setAdditionalFeePerOunce(double _additionalFeePerOunce)
    {
        this->additionalFeePerOunce = _additionalFeePerOunce;
    }
    double calculateCost(double _weight, double _cost)
    {
        return Package::calculateCost(_weight, _cost) + this->additionalFeePerOunce;
    }
};

void showSelection()
{
    cout << "1. Calculate the base cost" << endl;
    cout << "2. Calculate the two day cost" << endl;
    cout << "3. Calculate the overnight cost" << endl;
}

int main()
{
    Package customer;
    TwoDayPackage twoday;
    OvernightPackage overnight;
    string customer_name, customer_address, customer_city, customer_state, customer_ZIP, sender_address, recipient_address;
    double weight, cost, flatFee, additionalCost;
    int choice;

    cout << "-------Welcome to Package-delivery services-------" << endl;
    cout << "-------Information of customer-------" << endl;
    cout << "Enter your name" << endl;
    getline(cin, customer_name);
    customer.setName(customer_name);
    cout << "Enter your address" << endl;
    getline(cin, customer_address);
    customer.setAddress(customer_address);
    cout << "Enter your city" << endl;
    getline(cin, customer_city);
    customer.setCity(customer_city);
    cout << "Enter your state" << endl;
    getline(cin, customer_state);
    customer.setState(customer_state);
    cout << "Enter ZIP code" << endl;
    getline(cin, customer_ZIP);
    customer.setZIP(customer_ZIP);
    cout << "Enter the package weight" << endl;
    cin >> weight;
    customer.setWeight(weight);
    cout << "Enter the cost" << endl;
    cin >> cost;
    customer.setCost(cost);

    showSelection();
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    switch (choice)
    {
    case 1:
        cout << "Base cost: " << customer.calculateCost(weight, cost) << endl;
        break;
    case 2:
        cout << "Enter the flat cost" << endl;
        cin >> flatFee;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        twoday.setFee(flatFee);
        cout << "Two day cost: " << twoday.calculateCost(weight, cost) << endl;
        break;
    case 3:
        cout << "Enter the additional cost" << endl;
        cin >> additionalCost;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        overnight.setAdditionalFeePerOunce(additionalCost);
        cout << "Over night cost: " << overnight.calculateCost(weight, cost) << endl;
        break;
    default:
        cout << "Invalid choice !" << endl;
    }

    cout << "Enter the sender address" << endl;
    getline(cin, sender_address);
    customer.setSender(sender_address);
    cout << "Enter the recipient address" << endl;
    getline(cin, recipient_address);
    customer.setRecipient(recipient_address);

    return 0;
}