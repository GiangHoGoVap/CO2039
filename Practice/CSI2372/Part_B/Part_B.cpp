#include <iostream>
#include <climits>
using namespace std;

class Bit_array{
	int nbits; //current number of array bits
	int ncar; //number of required characters
	char* adb; //address of the location containing the bits
	public:
		Bit_array(int = 16);
		Bit_array(Bit_array&);
		~Bit_array();
		Bit_array& operator =(Bit_array&); //assignment operator
		int operator [](int); //bit value
		void operator +=(int); //activation of a bit
		void operator -=(int); //deactivation of a bit
		friend ostream& operator <<(ostream&, Bit_array&);
		void operator ++(); //setting to 1
		void operator --(); //setting to 0
		void operator ~(); //complement to 1
};

Bit_array::Bit_array(int nb){
	this->nbits = nb;
	this->ncar = this->nbits/CHAR_BIT + 1;
	this->adb = new char[ncar];
	for (int i=0; i<ncar; i++){
		adb[i] = 0;
	}
}

Bit_array::Bit_array(Bit_array& obj){
	this->nbits = obj.nbits;
	this->ncar = obj.ncar;
	adb = new char[ncar];
	for (int i=0; i<ncar; i++){
		adb[i] = obj.adb[i];
	}
}

Bit_array::~Bit_array(){
	delete adb;
}

Bit_array& Bit_array::operator =(Bit_array& obj){
	if (this != &obj){
		this->nbits = obj.nbits;
		this->ncar = obj.ncar;
		delete adb;
		adb = new char[ncar];
		for (int i=0; i<ncar; i++){
			adb[i] = obj.adb[i];
		}
	}
	return *this;
}

int Bit_array::operator [](int i){
	int carpos = i/CHAR_BIT;
	int bitpos = i%CHAR_BIT;
	return (adb[carpos] >> CHAR_BIT - bitpos - 1) & 0x01;
}

void Bit_array::operator +=(int i){
	int carpos = i/CHAR_BIT;
	if (carpos < 0 || carpos >= ncar) return;
	int bitpos = i%CHAR_BIT;
	adb[carpos] |= (1 << (CHAR_BIT - bitpos - 1));
}

void Bit_array::operator -=(int i){
	int carpos = i/CHAR_BIT;
	if (carpos < 0 || carpos >= ncar) return;
	int bitpos = i%CHAR_BIT;
	adb[carpos] &= ~(1 << CHAR_BIT - bitpos - 1);
}

ostream& operator <<(ostream& output, Bit_array& obj){
	output << "<* ";
	for (int i=0; i<obj.nbits; i++){
		output << obj[i] << " ";
	}
	output << "*>";
	return output;
}

void Bit_array::operator ++(){
	for (int i=0; i<ncar; i++){
		adb[i] = 0xFFFF;
	}
}

void Bit_array::operator --(){
	for (int i=0; i<ncar; i++){
		adb[i] = 0;
	}
}

void Bit_array::operator ~(){
	for (int i=0; i<ncar; i++){
		adb[i] = ~adb[i];
	}
}

int main(){
	Bit_array t1(34);
	cout << "t1 = " << t1 << "\n";
	t1 += 3; t1 += 0; t1 += 8; t1 += 15; t1 += 33;
	cout << "t1 = " << t1 << "\n";
	--t1;
	cout << "t1 = " << t1 << "\n";
	++t1;
	cout << "t1 = " << t1 << "\n";
	t1 -= 0; t1 -= 3; t1 -= 8; t1 -= 15; t1 -= 33;
	cout << "t1 = " << t1 << "\n";
	cout << "t1 = " << t1 << "\n";
	Bit_array t2(11), t3(17);
	cout << "t2 = " << t2 << "\n";
	t2 = t3 = t1;
	cout << "t3 = " << t3 << "\n";
}
