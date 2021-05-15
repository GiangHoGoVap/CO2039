#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class University;

class Student{
	private:
		string name;
		double score;
	public:
		Student(){
			this->name = "Unknown";
			this->score = 0;
		}
		Student(string _name, double _score){
			this->name = _name;
			this->score = _score;
		}
		~Student(){}
		string getName(){
			return this->name;
		}
		double getScore(){
			return this->score;
		}
		friend class StudentManagement;
};

class University{
	private:
		string university_name;
		Student* storage;
		int size;
		int capacity;
	public:
		University(){
			this->university_name = "Unknown";
			this->size = 0;
			this->capacity = 10;
			this->storage = new Student[capacity];
		}
		University(string name, int _capacity){
			this->university_name = name;
			this->size = 0;
			this->capacity = _capacity;
			this->storage = new Student[capacity];
		}
		~University(){
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
			if (this->size == this->capacity){
				int last = this->capacity + 1;
				setCapacity(last);
			}
			storage[this->size] = newStudent;
			this->size++;
		}
		void add(string _name, double _score){
			Student newStudent(_name, _score);
			add(newStudent);
		}
		void print(){
			bool firstTime = true;
			cout << this->university_name << endl;
			for (int i=0; i<this->size; i++){
				if (!firstTime) cout << endl;
				cout << storage[i].getName() << " " << storage[i].getScore();
				firstTime = false;
			}
		}
		void printBest(){
			double highestScore = 0;
			vector<Student> v;
			bool firstTime = true;
			cout << this->university_name << endl;
			for (int i=0; i<this->size; i++){
				if (storage[i].getScore() > highestScore){
					highestScore = storage[i].getScore();
				}
			}
			for (int i=0; i<this->size; i++){
				if (storage[i].getScore() == highestScore){
					v.push_back(storage[i]);
				}
			}
			for (int i=0; i<v.size(); i++){
				if (!firstTime) cout << endl;
				cout << v[i].getName() << " " << v[i].getScore();
				firstTime = false;
			}
		}
		void remove(string _name){
			for (int i=0; i<this->size; i++){
				if (_name == storage[i].getName()){
					for (int j=i+1; j<this->size; j++){
						swap(storage[j], storage[j-1]);
					}
					Student* temp = new Student[this->size - 1];
					for (int j=0; j<this->size-1; j++){
						temp[j] = storage[j];
					}
					delete[] storage;
					this->size--;
					storage = temp;
					delete[] temp;
				}
			}
		}
};

void showSelection(){
	cout << "-------Welcome-------" << endl;
	cout << "1. Add student" << endl;
	cout << "2. Remove student" << endl;
	cout << "3. Display list of all students" << endl;
	cout << "4. Display list of best students" << endl;
	cout << "5. Exit" << endl;
}

int main(){
	University* obj = new University("Dai hoc Bach Khoa TPHCM", 10);
	int choice;
	string name;
	double score;
	showSelection();
	cin >> choice;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	while (choice != 5){
		switch(choice){
			case 1:
				cout << "Input student's name:" << endl;
				getline(cin, name);
				cout << "Input student's score:" << endl;
				cin >> score;
				obj->add(name, score);
				break;
			case 2:
				cout << "Input student's name to remove:" << endl;
				getline(cin, name);
				obj->remove(name);
				break;
			case 3:
				cout << "List of all students;" << endl;
				obj->print();
				cout << endl;
				break;
			case 4:
				cout << "List of best students:" << endl;
				obj->printBest();
				cout << endl;
				break;
			default:
				cout << "Invalid selection" << endl;
		}
		showSelection();
		cin >> choice;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	delete obj;
	return 0;
}
