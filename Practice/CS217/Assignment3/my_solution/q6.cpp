#include <iostream>
using namespace std;

class Address
{
private:
    int HouseNumber, street, ApartmentNumber, PostalCode;
    char *city, *state;

public:
    Address(int _HouseNumber, int _street, int _PostalCode, char *_city, char *_state)
    {
        this->HouseNumber = _HouseNumber;
        this->street = _street;
        this->ApartmentNumber = 0;
        this->PostalCode = _PostalCode;
        this->city = _city;
        this->state = _state;
    }
    Address(int _HouseNumber, int _street, int _ApartmentNumber, int _PostalCode, char *_city, char *_state)
    {
        this->HouseNumber = _HouseNumber;
        this->street = _street;
        this->ApartmentNumber = _ApartmentNumber;
        this->PostalCode = _PostalCode;
        this->city = _city;
        this->state = _state;
    }
    ~Address()
    {
        delete city;
        delete state;
    }
    void print()
    {
        cout << this->HouseNumber << " " << this->street;
        if (this->ApartmentNumber != 0)
            cout << " (" << this->ApartmentNumber << ")";
        cout << endl;
        cout << this->city << " " << this->state << " " << this->PostalCode << endl;
    }
    bool compareTo(const Address &obj)
    {
        return (this->PostalCode < obj.PostalCode);
    }
};

int main()
{
    Address obj1(56, 123, 7740, "Ho Chi Minh City", "Ho Chi Minh");
    Address obj2(11, 456, 2, 7739, "Nha Trang", "Khanh Hoa");
    obj1.print();
    obj2.print();
    cout << obj1.compareTo(obj2);
    return 0;
}