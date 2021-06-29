#include <iostream>
#include <string> 
using namespace std; 

// Address class here 
class Address{
	public:
		int house_no, street;
		string city, country;
		string get_full_address(){
			return "H. No. " + to_string(this->house_no) + ", Street " + to_string(this->street) + ", " + this->city + " " + this->country;
		}
};
// Employee class here 
class Employee{
	private:
		string name;
		Address current_address;
		Address permanent_address;
	public:
		void set_current_address(int house_no, int street, string city, string country){
			this->current_address.house_no = house_no;
			this->current_address.street = street;
			this->current_address.city = city;
			this->current_address.country = country;			
		}
		void set_permanent_address(int house_no, int street, string city, string country){
			this->permanent_address.house_no = house_no;
			this->permanent_address.street = street;
			this->permanent_address.city = city;
			this->permanent_address.country = country;
		}
		void print_addresses(){
			cout << this->current_address.get_full_address() << endl;
			cout << this->permanent_address.get_full_address() << endl;
		}
};
// Wheel class here 
class Wheel{
	private:
		string state;
	public:
		void set_wheel_state(string s){
			this->state = s;
		}
		string get_wheel_state(){
			return this->state;
		}
};
// Car class here 
class Car{
	private:
		Wheel arr[4];
	public:
		void set_car_to_moving(){
			for (int i=0; i<4; i++){
				this->arr[i].set_wheel_state("Turning");
			}
		}
		void set_car_to_stopped(){
			for (int i=0; i<4; i++){
				this->arr[i].set_wheel_state("Stopped");
			}
		}
		void print_car_wheels_state(){
			cout << "Car state:" << endl;
			for (int i=0; i<4; i++){
				cout << "- Wheel " << i << " is " << this->arr[i].get_wheel_state() << endl;
			}
		}
};

int main() { 

    // Start of PART - 1  -----------------------
    Address a; 

    a.house_no = 4; 
    a.street = 25; 
    a.city = "Peshawar"; 
    a.country = "Pakistan";

    cout << a.get_full_address() << endl;

    // End of Part - 1    -----------------------




    // Start of PART - 2  -----------------------

    Employee e1; 

    e1.set_current_address(4, 25, "Peshawar", "Pakistan"); 
    e1.set_permanent_address(14, 9, "Lahore", "Pakistan"); 
    e1.print_addresses();  

    // End of Part - 2     -----------------------




    // Start of PART - 3   -----------------------

    Wheel w1; 

    w1.set_wheel_state("Turning"); 
    cout << w1.get_wheel_state() << endl; 

    // End of Part - 3     -----------------------




    // Start of PART - 4   -----------------------

    Car c; 
    
    c.set_car_to_moving(); 
    c.print_car_wheels_state(); 

    c.set_car_to_stopped(); 
    c.print_car_wheels_state();

    // End of Part - 4     -----------------------


    return 0; 
}
