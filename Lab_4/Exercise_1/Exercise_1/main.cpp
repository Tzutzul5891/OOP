#define _CRT_SECURE_NO_WARNINGS
#include "Sort.h"
#include<stdio.h>
#include<iostream>
#include<cstring>

using namespace std;

int main()
{
	int a[4] = { 5,11,33,68 };
	char s[] = "4, 2, 65, 5, 44";
	Sort Vector(a, 4);
	Vector.Print();
	Vector.QuickSort(true);
	Vector.Print();
}