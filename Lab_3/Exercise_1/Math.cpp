#include "Math.h"
#include <math.h>

int Math::Add(int a, int b) {
	return a + b;
}

int Math::Add(int a, int b, int c) {
	return a + b + c;
}

int Math::Add(double a, double b) {
	return (int)(a + b);
}

int Math::Add(double a, double b, double c) {
	return (int)(a + b + c);
}

int Math::Mul(int a, int b) {
	return a * b;
}

int Math::Mul(int a, int b, int c) {
	return a * b * c;
}

int Math::Mul(double a, double b) {
	return (int)(a * b);
}

int Math::Mul(double a, double b, double c) {
	return (int)(a * b * c);
}

int Math::Add(int count, ...) {
	va_list a;
	va_start(a, count);
	int s = 0;
	for (int i = 1; i <= count; i++) {
		s = s + va_arg(a, int);
	}
	va_end(a);
	return s;
}

char* Math::Add(const char* a, const char* b)
{
	if (a == nullptr || b == nullptr)
		return nullptr;

	int lga = strlen(a);
	int lgb = strlen(b);
	int aux, v = 0, t = 0;
	const char* c;
	if (lga >  lgb)
	{
		aux = lga;
		lga = lgb;
		lgb = aux;
		c = a;
		a = b;
		b = c;
	}
	char* z = new char[lga + 2];
	memset(z, 0, lga + 2);
	for (int i = 1; i <= lga; i++)
	{

		if (i <= lgb)
			v = (a[lga - i] - '0') + (b[lgb - i] - '0') + t;
		else
			v = a[lga - i] - '0' + t;
		z[lga + 1 - i] = v % 10 + '0';
		t = v / 10;
	}
	z[0] = t + '0';
	if (z[0] == '0')
		memcpy(z, z + 1, lga + 1);
	return z;
}