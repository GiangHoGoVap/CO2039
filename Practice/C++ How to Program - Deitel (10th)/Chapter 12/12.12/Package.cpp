#include <iostream>
#include <vector>
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
    Package(string _senderAddress, string _recipientAddress, double _weight, double _cost)
    {
        this->senderAddress = _senderAddress;
        this->recipientAddress = _recipientAddress;
        this->weight = _weight;
        this->cost = _cost;
    }
    Package(string _name, string _address, string _city, string _state, string _ZIP, string _senderAddress, string _recipientAddress, double _weight, double _cost)
    {
        if (_weight < 0 || _cost < 0)
        {
            cout << "Invalid weight/cost." << endl;
        }
        else
        {
            this->name = _name;
            this->address = _address;
            this->city = _city;
            this->state = _state;
            this->ZIP = _ZIP;
            this->senderAddress = _senderAddress;
            this->recipientAddress = _recipientAddress;
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
    string getSender()
    {
        return this->senderAddress;
    }
    void setRecipient(string _recipientAddress)
    {
        this->recipientAddress = _recipientAddress;
    }
    string getRecipient()
    {
        return this->recipientAddress;
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
    virtual double calculateCost()
    {
        return this->weight * this->cost;
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
    TwoDayPackage(string _senderAddress, string _recipientAddress, double _weight, double _cost, double _fee) : Package(_senderAddress, _recipientAddress, _weight, _cost)
    {
        this->fee = _fee;
    }
    void setFee(double _fee)
    {
        this->fee = _fee;
    }
    double calculateCost()
    {
        return Package::calculateCost() + this->fee;
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
    OvernightPackage(string _senderAddress, string _recipientAddress, double _weight, double _cost, double _additionalFeePerOunce) : Package(_senderAddress, _recipientAddress, _weight, _cost)
    {
        this->additionalFeePerOunce = _additionalFeePerOunce;
    }
    void setAdditionalFeePerOunce(double _additionalFeePerOunce)
    {
        this->additionalFeePerOunce = _additionalFeePerOunce;
    }
    double calculateCost()
    {
        return Package::calculateCost() + this->additionalFeePerOunce;
    }
};

int main()
{
    Package *obj1 = new Package("Nguyen Minh Tam", "27/8 Nguyen Binh Khiem", "TPHCM", "TPHCM", "07001", "27/8 Nguyen Binh Khiem", "1A Pham Ngu Lao", 90, 34.5);
    TwoDayPackage *obj2 = new TwoDayPackage("136 Nguyen Thuong Hien", "62 Nguyen Hien", 67, 30, 10);
    OvernightPackage *obj3 = new OvernightPackage("42 Nguyen Du", "99 Le Quang Dinh", 84.1, 43, 20);
    vector<Package *> v;
    v.push_back(obj1);
    v.push_back((Package *)obj2);
    v.push_back((Package *)obj3);
    double totalCost = 0;
    for (auto p : v)
    {
        cout << "Sender address: " << p->getSender() << endl;
        cout << "Recipient address: " << p->getRecipient() << endl;
        cout << "Cost: " << p->calculateCost() << endl;
        cout << "--------------------" << endl;
        totalCost += p->calculateCost();
    }
    cout << "Total cost: " << totalCost << endl;
    delete obj1;
    delete obj2;
    delete obj3;
    return 0;
}
