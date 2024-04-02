#include "Number.h"

std::string decimalToBase(int nr, int b) {
	string result = "";
	while (nr > 0) {
		int r = nr % b;
		result = to_string(r) + result;
		nr /= b;
	}
	return result;
}

Number::Number(const char* c, int baza) {
	this->s = c;
	this->b = baza;
}

Number::~Number(){}

void Number::Print() {
	cout << this->s << endl;
}

Number& Number::operator=(const Number& a) {
	this->s = a.s;
	this->b = a.b;
	return *this;
}

Number Number::operator+(const Number& a) const{
	int num1 = stoi(this->s, nullptr, this->b);
	int num2 = stoi(a.s, nullptr, a.b);
	int res = num1 + num2;
	string str;
	if (this->b > a.b) {
		str = decimalToBase(res, this->b);
		return Number(str.c_str(), this->b);
	}
	else {
		str = decimalToBase(res, a.b);
		return Number(str.c_str(), a.b);
	}
}

Number::Number(const int& a) {
	this->s = to_string(a);
	this->b = 10;
}

Number& Number::operator=(const int& a) {
	string res = decimalToBase(a, 2);
	this->s = res;
	this->b = 2;
	return *this;
}

Number& Number::operator--() {
	this->s = this->s.substr(1);
	return *this;
}

Number Number::operator--(int a) {
	this->s = this->s.erase(this->s.size() - 1);
	return *this;
}

Number& Number::operator+=(const Number& a) {
	int num1 = stoi(this->s, nullptr, this->b);
	int num2 = stoi(a.s, nullptr, a.b);
	int res = num1 + num2;
	string str;
	if (this->b > a.b)
	{
		str = decimalToBase(res, this->b);
		this->s = str;
		return *this;
	}
	else
	{
		str = decimalToBase(res, a.b);
		this->s = str;
		this->b = a.b;
		return *this;
	}
}

bool Number::operator>(const Number& a) const {
	if (stoi(this->s, nullptr, this->b) > stoi(a.s, nullptr, a.b))
		return true;
	else
		return false;
}

Number& Number::operator=(const char* a) {
	this->s = a;
	this->b = 10;
	return *this;
}

Number Number::operator-(const Number& a) const{
	int num1 = stoi(this->s, nullptr, this->b);
	int num2 = stoi(a.s, nullptr, a.b);
	int res = num1 - num2;
	string str;
	if (this->b > a.b) {
		str = decimalToBase(res, this->b);
		return Number(str.c_str(), this->b);
	}
	else {
		str = decimalToBase(res, a.b);
		return Number(str.c_str(), a.b);
	}
}

Number::Number(const Number& a) {
	this->s = a.s;
	this->b = a.b;
}

int Number::GetBase() {
	return this->b;
}

int Number::GetDigitsCount() {
	return this->s.length();
}

char Number::operator[](int i) const {
	return s[i];
}

void Number::SwitchBase(int b) {
	int num = stoi(this->s, nullptr, this->b);
	string str;
	while (num > 0) {
		int r = num % b;
		char cif;
		if (r < 10)
			cif = (char)(r + '0');
		else
			cif = (char)(r - 10 + 'A');
		str = cif + str;
		num /= b;
	}

	this->s = str;
	this->b = b;
}