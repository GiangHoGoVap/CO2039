#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class StudentManagement{
	private:
		string* StudentName;
		double* StudentScore;
		int size;
		int capacity; 
	public:
		StudentManagement(){
			capacity = 10;
			size = 0;
			StudentName = new string[capacity];
			StudentScore = new double[capacity];
		}
		StudentManagement(int _capacity){
			this->capacity = _capacity;
			size = 0;
			StudentName = new string[capacity];
			StudentScore = new double[capacity];
		}
		~StudentManagement(){
			delete[] StudentName;
			delete[] StudentScore;
		}
		void setCapacity(int newCapacity){
			string* newStudentName = new string[newCapacity];
			double* newStudentScore = new double[newCapacity];
			for (int i=0; i<this->size; i++){
				newStudentName[i] = StudentName[i];
				newStudentScore[i] = StudentScore[i];
			}
			this->capacity = newCapacity;
			delete[] StudentName;
			delete[] StudentScore;
			StudentName = newStudentName;
			StudentScore = newStudentScore;
		}
		void add(string _name, double _score){
			if (this->size < this->capacity){
				StudentName[this->size] = _name;
				StudentScore[this->size] = _score;
			}
			else{
				int last = this->capacity + 1;
				setCapacity(last);
				StudentName[this->size] = _name;
				StudentScore[this->size] = _score;
			}
			this->size++;
		}
		void print(){
			bool firstTime = true;
			for (int i=0; i<this->size; i++){
				if (!firstTime) cout << endl;
				cout << StudentName[i] << " " << StudentScore[i];
				firstTime = false;
			}
		}
		void printBest(){
			double bestScore = 0;
			for (int i=0; i<this->size; i++){
				if (bestScore < StudentScore[i]){
					bestScore = StudentScore[i];
				}
			}
			vector<string> bestName;
			for (int i=0; i<this->size; i++){
				if (bestScore == StudentScore[i]){
					bestName.push_back(StudentName[i]);
				}
			}
			for (int i=0; i<bestName.size(); i++){
				cout << bestName[i] << " " << bestScore << endl;
			}
		}
};

void showSelection(){
	cout << "----------Welcome----------" << endl;
	cout << "1. Add new student and his/her score" << endl;
	cout << "2. Display list of all students and their scores" << endl;
	cout << "3. Display the best students and their scores" << endl;
}

int main(){
	StudentManagement* obj = new StudentManagement;
	int choice;
	string name;
	double score;
	showSelection();
	cin >> choice;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	while (choice != 4){
		switch(choice){
			case 1:
				cout << "Input student's name:" << endl;
				getline(cin, name);
				cout << "Input his/her score:" << endl;
				cin >> score;
				obj->add(name, score);
				break;
			case 2:
				cout << "Display list of all students and their scores" << endl;
				obj->print();
				cout << endl;
				break;
			case 3: 
				cout << "Display the best students and their scores" << endl;
				obj->printBest();
				cout << endl;
				break;
		}
		showSelection();
		cin >> choice;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	delete obj;
	return 0;
}
