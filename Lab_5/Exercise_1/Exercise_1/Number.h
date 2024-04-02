#include <string>
#include <iostream>

using namespace std;

class Number
{
	string s;
	int b;
public:
	Number(const char* value, int base); // where base is between 2 and 16
	~Number();
	Number operator+(const Number&) const;
	Number operator-(const Number&) const;
	Number& operator=(const Number&);
	Number& operator=(const int&);
	Number& operator=(const char*);
	Number& operator+=(const Number&);
	char operator[](int) const;
	bool operator>(const Number&) const;
	Number& operator--();
	Number operator--(int);
	Number(const int&);
	Number(const Number& a);
	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base
};
