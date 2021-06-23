#include <iostream>
using namespace std;

/*Structure of a list items*/
struct Element{
	Element* next; //pointer to the next element
	void* content; //pointer to any object
};

/*List class*/
class List{
	Element* beg; //pointer to the first element
	Element* cur; //pointer to the current element
	public:
		List(){
			this->beg = NULL;
			this->cur = beg;
		}
		~List(){
			Element* temp;
			cur = beg;
			while (cur != NULL){
				temp = cur->next;
				delete cur;
				cur = temp;
			}
		}
		void add(void*); //add an element at the beginning of the list
		void* first(); //position on first element
		void* next(); //position on next element
		int finish();
};

void List::add(void* newContent){
	Element* newEle = new Element;
	newEle->content = newContent;
	newEle->next = this->beg;
	this->beg = newEle;
}

void* List::first(){
	cur = beg;
	if (cur != NULL) return cur->content;
	else return NULL;
}

void* List::next(){
	if (cur != NULL){
		cur = cur->next;
		if (cur != NULL) return cur->content;
	}
	else return NULL;
}

int List::finish(){
	return (cur == NULL);
}

/*Point class*/
class Point{
	int x, y;
	public:
		Point(int abs = 0, int ord = 0){
			x = abs;
			y = ord;
		}
		void display(){
			cout << "Coordinates: " << x << " " << y << "\n";
		}
};

class List_points : public List, public Point{
	public:
		List_points(){}
		void display();
};

void List_points::display(){
	Point* ptr = (Point*)first();
	while (finish() != 1){
		ptr->display();
		ptr = (Point*)next();
	}
}

int main(){
	Point* a = new Point(1, 2);
	Point* b = new Point(2, 3);
	Point* c = new Point(4, 5);
	List_points l;
	l.add(a);
	l.add(b);
	l.add(c);
	l.display();
	cout << l.first() << endl;
	cout << l.next() << endl;
	cout << l.finish() << endl;
	return 0;
}
