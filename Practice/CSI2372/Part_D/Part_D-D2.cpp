#include <iostream>
#include <vector>
using namespace std;

/*Vect class*/
class Vect : public vector<int>{
	public:
		Vect(int n): vector<int>(n){}
		int& operator [](int);
		friend ostream& operator <<(ostream&, Vect&);
};

int& Vect::operator [](int i){
	if (i < 0 || i >= (*this).size()) i = 0;
	return (*this).at(i);
}

ostream& operator <<(ostream& output, Vect& v){
	output << "< ";
	vector<int>::iterator iter;
	for (iter = v.begin(); iter != v.end(); iter++){
		output << *iter << " ";
	}
	output << ">";
	return output;
}

int main(){
	Vect v(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(1);
	cout << v << endl;
	v.pop_back();
	cout << v << endl;
	return 0;
}
