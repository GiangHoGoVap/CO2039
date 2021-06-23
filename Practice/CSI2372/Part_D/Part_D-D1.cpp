#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void fct(stack<int, vector<int>> pl){
	cout << "top of the stack received by fct: ";
	int n = pl.top();
	pl.pop();
	int p = pl.top();
	pl.pop();
	cout << n << " " << p << endl;
	pl.push(12);
}

int main(){
	stack<int, vector<int>> pile;
	cout << "empty: " << pile.empty() << endl;
	pile.push(1);
	pile.push(2);
	pile.push(3);
	pile.push(4);
	fct(pile);
	int n = pile.top();
	pile.pop();
	int p = pile.top();
	pile.pop();
	cout << "top of the stack when fct returns: " << n << " " << p << endl;
	stack<int, vector<int>> pileb;
	pileb = pile;
	return 0;
}
