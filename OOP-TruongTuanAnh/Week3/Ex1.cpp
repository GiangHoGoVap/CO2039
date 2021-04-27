#include <iostream>
#include <cstring>
#include <limits>
using namespace std;

class Grades{
	int mark;
	char nameOfCourse[40];
	public:
		Grades(){}
		Grades(string _nameOfCourse, int _mark){
			strcpy(this->nameOfCourse, _nameOfCourse.c_str());
			this->mark = _mark;
		}
		int getMark(){
			return mark;
		}
};

class Student{
	int studentID;
	char name[40];
	Grades* grades;
	int numOfGrades;
	public:
		Student(){}
		Student(string _name, int _studentID){
			strcpy(this->name, _name.c_str());
			this->studentID = _studentID;
			this->grades = new Grades[10];
			this->numOfGrades = 0;
		}
		~Student(){
			delete[] grades;
		}
		void add(string nameOfCourse, int mark){
			if (this->numOfGrades == 10) return;
			Grades newGrades(nameOfCourse, mark);
			grades[this->numOfGrades] = newGrades;
			this->numOfGrades++;
		}
		double average(){
			double sum = 0;
			for (int i=0; i<numOfGrades; i++){
				sum += grades[i].getMark();
			}
			return (double)(sum / numOfGrades);
		}
};

class StudentManagement{
	int size;
	int capacity;
	Student* storage;
	public:
		StudentManagement(){
			this->size = 0;
			this->capacity = 10;
			this->storage = new Student[capacity];
		}
		StudentManagement(int _capacity){
			this->size = 0;
			this->capacity = _capacity;
			this->storage = new Student[capacity];
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
		void add(string name, int studentID){
			Student newStudent(name, studentID);
			add(newStudent);
		}
		void add(Student newStudent){
			if (this->size == this->capacity){
				int last = this->capacity + 1;
				setCapacity(last);
			}
			storage[this->size] = newStudent;
			this->size++;
		}
		double averageScore(int choice){
			int index = choice - 1;
			return storage[index].average();
		}
};

int main(){
	StudentManagement* obj = new StudentManagement;
	int n;
	cout << "Enter number of Students? ";
	cin >> n;
	cout << "-----" << endl;
	int studentID, grades;
	string name;
	for (int i=0; i<n; i++){
		cout << "Input details for Student " << i+1 << ":" << endl;
		cout << "Student ID? ";
		cin >> studentID;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Name? ";
		getline(cin, name);
		Student newStudent(name, studentID);
		cout << "-----" << endl;
		cout << "How many Grades? ";
		cin >> grades; 
		cin.ignore(numeric_limits<streamsize>::max(), '\n');	
		string nameGrade;
		int mark;
		bool firstTime = true;
		for (int j=0; j<grades; j++){
			if (!firstTime) cout << "-----" << endl;
			cout << "Name of Grade " << j+1 << ": ";
			getline(cin, nameGrade);
			cout << "Mark of Grade " << j+1 << ": ";
			cin >> mark;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			newStudent.add(nameGrade, mark);
			firstTime = false;
		}	
		obj->add(newStudent);
	}
	cout << "=====" << endl;
	int choice;
	cout << "Which student average grade? ";
	cin >> choice;
	cout << "Average grade for student " << choice << ": ";
	cout << obj->averageScore(choice);
	delete obj;
	return 0;
}
