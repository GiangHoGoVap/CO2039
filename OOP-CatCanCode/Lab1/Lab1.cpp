#include <iostream>
#include <limits>
using namespace std;

class Student;
class StudentManagement;

class Student{
	private:
		string name;
	public:
		Student(){
			name = "Unknown";
		}
		Student(string _name){
			this->name = _name;
		}
		string getName(){
			return name;
		}
		friend class StudentManagement;
};

class StudentManagement{
	private:
		Student* storage;
		int size;
		int capacity;
	public:
		StudentManagement(){
			capacity = 10;
			size = 0;
			storage = new Student[capacity];
		}
		StudentManagement(int _capacity){
			this->capacity = _capacity;
			size = 0;
			storage = new Student[capacity];
		}
		~StudentManagement(){
			delete[] storage;
		}
		void setCapacity(int newCapacity){
			Student* newStorage = new Student[newCapacity];
			for (int i=0; i<this->size; i++){
				newStorage[i] = storage[i];
			}
			this->capacity = newCapacity;
			delete[] storage;
			storage = newStorage;
		}
		void add(Student newStudent){
			if (this->size < this->capacity){
				storage[this->size] = newStudent;
			}
			else{
				int last = this->capacity + 1;
				setCapacity(last);
				storage[this->size] = newStudent;
			}
			this->size++;
		}
		void add(string _name){
			Student newStudent(_name);
			add(newStudent);
		}
		void remove(string _name){
			bool flag = false;
			for (int i=0; i<this->size; i++){
				if (_name == storage[i].getName()){
					flag = true;
					for (int j=i+1; j<this->size; j++){
						swap(storage[j], storage[j-1]);
					}
					Student* temp = new Student[this->size - 1];
					for (int j=0; j<this->size-1; j++){
						temp[j] = storage[j];
					}
					delete[] storage;
					this->size--;
					storage = new Student[this->capacity];
					for (int j=0; j<this->size; j++){
						storage[j] = temp[j];
					}
					i--;
					delete[] temp;
				}
			}
			if (!flag) cout << "Not found" << endl;
		}
		void print(){
			bool firstTime = true;
			for (int i=0; i<this->size; i++){
				if (!firstTime) cout << endl;
				cout << storage[i].getName();
				firstTime = false;
			}
		}
};

void showSelection(){
	cout << "-------------Welcome-------------" << endl;
	cout << "1. Add student" << endl;
	cout << "2. Remove student" << endl;
	cout << "3. Display list of all students" << endl;
	cout << "4. Exit" << endl;
}

int main(){
	StudentManagement* obj = new StudentManagement;
	int choice;
	string name;
	showSelection();
	cin >> choice;
	cin.ignore(numeric_limits<streamsize>::max(), '\n' );
	while (choice != 4){
		switch (choice){
			case 1: 
				cout << "Input student's name to add:" << endl;
				getline(cin, name);
				obj->add(name);
				break;
			case 2:
				cout << "Input student's name to remove:" << endl;
				getline(cin, name);
				obj->remove(name);
				break;
			case 3:
				cout << "List of all students:" << endl;
				obj->print();
				cout << endl;
				break;
			default:
				cout << "Invalid selection" << endl;
		}
		showSelection();
		cin >> choice;
		cin.ignore(numeric_limits<streamsize>::max(), '\n' );
	}
	delete obj;
	return 0;
}
