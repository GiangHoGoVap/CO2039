#include <iostream>
#include <vector>
using namespace std;

class Rectangle{
	protected:
		int width, height;
	public:
		Rectangle(){
			this->width = 0;
			this->height = 0;
		}
		Rectangle(int _width, int _height){
			this->width = _width;
			this->height = _height;
		}
		int getArea(){
			return width * height;
		}
};

int main(){
	int numRec;
	cout << "How many rectangles? ";
	cin >> numRec;
	if (numRec >= 1 && numRec <= 100){
		vector<int> v;
		for (int i=1; i<=numRec; i++){
			cout << "-----" << endl;
			int width, height;
			cout << "Input width and height for rectangle " << i << ":" << endl;
			cout << "Width: ";
			cin >> width;
			cout << "Height: ";
			cin >> height;
			Rectangle obj = Rectangle(width, height);
			int area = obj.getArea();
			v.push_back(area);
		}
		cout << "==========" << endl;
		bool firstTime = true;
		for (int i=0; i<v.size(); i++){
			if (!firstTime) cout << endl;
			cout << "The area of rectangle " << i+1 << ": " << v[i];
			firstTime = false;
		}
		cout << endl;
	}
	return 0;
}
