#include <iostream>
#include <cstring>
#include <vector>
#include <limits>
using namespace std;

class People
{
protected:
	char name[40];
	int ID;

public:
	People() {}
	People(string _name, int _ID)
	{
		strcpy(this->name, _name.c_str());
		this->ID = _ID;
	}
};

class Tickets
{
	char flightName[40];
	int value;

public:
	Tickets() {}
	Tickets(string _flightName, int _value)
	{
		strcpy(this->flightName, _flightName.c_str());
		this->value = _value;
	}
	int getValue()
	{
		return this->value;
	}
	string getFlightName()
	{
		return string(flightName);
	}
};

class Customers : public People
{
	int quantity;
	Tickets *tickets;
	int cnt;

public:
	Customers()
	{
		this->quantity = 10;
	}
	Customers(string _name, int _ID, int _quantity)
	{
		strcpy(this->name, _name.c_str());
		this->ID = _ID;
		this->quantity = _quantity;
		this->tickets = new Tickets[quantity];
		this->cnt = 0;
	}
	~Customers()
	{
		delete[] tickets;
	}
	void add(string flightName, int value)
	{
		if (cnt == 10)
			return;
		Tickets newTicket(flightName, value);
		tickets[this->cnt] = newTicket;
		this->cnt++;
	}
	string getFlightName(int idx)
	{
		return tickets[idx].getFlightName();
	}
	int getID()
	{
		return ID;
	}
	int getQuantity()
	{
		return this->quantity;
	}
	int getValue(int idx)
	{
		return tickets[idx].getValue();
	}
	string getName()
	{
		return string(name);
	}
};

class CustomerManagement
{
	int size;
	int capacity;
	Customers *storage;

public:
	CustomerManagement()
	{
		this->size = 0;
		this->capacity = 10;
		this->storage = new Customers[capacity];
	}
	CustomerManagement(int _capacity)
	{
		this->size = 0;
		this->capacity = _capacity;
		this->storage = new Customers[capacity];
	}
	~CustomerManagement()
	{
		delete[] storage;
	}
	void setCapacity(int newCapacity)
	{
		Customers *newStorage = new Customers[newCapacity];
		for (int i = 0; i < this->size; i++)
		{
			newStorage[i] = storage[i];
		}
		this->capacity = newCapacity;
		delete[] storage;
		storage = newStorage;
	}
	void add(string _name, int _ID, int _quantity)
	{
		Customers newCustomer(_name, _ID, _quantity);
		add(newCustomer);
	}
	void add(Customers newCustomer)
	{
		if (this->size == this->capacity)
		{
			int last = this->capacity + 1;
			setCapacity(last);
		}
		storage[this->size] = newCustomer;
		this->size++;
	}
	int sum(int _ID)
	{
		int index = -1;
		for (int i = 0; i < this->size; i++)
		{
			if (storage[i].getID() == _ID)
			{
				index = i;
			}
		}
		if (index == -1)
		{
			return -1;
		}
		int sum = 0;
		for (int i = 0; i < storage[index].getQuantity(); i++)
		{
			sum += storage[index].getValue(i);
		}
		return sum;
	}
	void findCustomers(string _flightName)
	{
		vector<string> v;
		for (int i = 0; i < this->size; i++)
		{
			for (int j = 0; j < storage[i].getQuantity(); j++)
			{
				if (storage[i].getFlightName(j) == _flightName)
				{
					v.push_back(storage[i].getName());
					break;
				}
			}
		}
		bool firstTime = true;
		for (int i = 0; i < v.size(); i++)
		{
			if (!firstTime)
				cout << endl;
			cout << v[i];
			firstTime = false;
		}
	}
};

void showSelection()
{
	cout << "-------Welcome-------" << endl;
	cout << "1. Sum of value" << endl;
	cout << "2. Find all customers with flight name" << endl;
}

int main()
{
	CustomerManagement *obj = new CustomerManagement;
	int n;
	cout << "Enter number of Customers?" << endl;
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	string name;
	int ID, numTickets;
	for (int i = 0; i < n; i++)
	{
		cout << "Input details for Customer " << i + 1 << ":" << endl;
		cout << "Name? ";
		getline(cin, name);
		cout << "ID? ";
		cin >> ID;
		cout << "How many tickets? ";
		cin >> numTickets;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		Customers newCus(name, ID, numTickets);
		string flightName;
		int value;
		for (int j = 0; j < numTickets; j++)
		{
			cout << "Input flightName for ticket " << j + 1 << "? ";
			getline(cin, flightName);
			cout << "Input value for ticket " << j + 1 << "? ";
			cin >> value;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			newCus.add(flightName, value);
		}
		obj->add(newCus);
	}
	cout << "=====" << endl;
	int option;
	showSelection();
	cout << "Select option: ";
	cin >> option;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	int cusID;
	string _flightName;
	while (option != 3)
	{
		switch (option)
		{
		case 1:
			cout << "Which customer? ";
			cin >> cusID;
			cout << "Sum value of the customer: ";
			cout << obj->sum(cusID) << endl;
			break;
		case 2:
			cout << "Which flight? " << endl;
			getline(cin, _flightName);
			cout << "The flight has customers:" << endl;
			obj->findCustomers(_flightName);
			cout << endl;
			break;
		default:
			cout << "Invalid selection" << endl;
		}
		showSelection();
		cin >> option;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	delete obj;
	return 0;
}
