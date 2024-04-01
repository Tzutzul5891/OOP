#define _CRT_SECURE_NO_WARNINGS
#include "Sort.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <cstring>

using namespace std;

Sort::Sort(int nrElem, int maxim, int minim) {
	v = new int[nrElem];
	this->k = nrElem;
	for (int i = 0; i < nrElem; i++) {
		this->v[i] = (rand() % (maxim - minim) + 1) + minim;
	}
}

Sort::Sort() : v(new int[3] {1, 2, 3}) {
	this->k = 3;
}

Sort::Sort(int a[1000], int nr) {
	v = new int[nr];
	this->k = nr;
	for (int i = 0; i < nr; i++) {
		this->v[i] = a[i];
	}
}


Sort::Sort(char* s)
{
	v = new int[strlen(s)];
	this->k = 0;
	char* p;
	int nr, pow, i;
	p = strtok(s, ",");
	while (p)
	{
		this->k++;
		nr = 0;
		pow = 1;
		for (i = strlen(p) - 1; i >= 0; i--)
		{
			nr = nr + pow * (p[i] - '0');
			pow = pow * 10;
		}
		this->v[this->k - 1] = nr;
		p = strtok(NULL, ",");
	}
}

Sort::Sort(int nr...) {
	v = new int[nr];
	this->k = nr;
	va_list a;
	va_start(a, nr);
	for (int i = 0; i < nr; i++) {
		this->v[i] = va_arg(a, int);
	}
	va_end(a);
}

void  Sort::BubbleSort(bool ascendent)
{
	int i, j;
	bool ok;
	if (ascendent == true)
		for (i = 0; i < this->k - 1; i++)
		{
			ok = false;
			for (j = 0; j < this->k - i - 1; j++)
				if (this->v[j] > this->v[j + 1])
				{
					swap(this->v[j], this->v[j + 1]);
					ok = true;
				}
			if (ok == false)
				break;
		}
	else
		for (i = 0; i < this->k - 1; i++)
		{
			ok = false;
			for (j = 0; j < this->k - i - 1; j++)
				if (this->v[j] < this->v[j + 1])
				{
					swap(this->v[j], this->v[j + 1]);
					ok = true;
				}
			if (ok == false)
				break;
		}
}

void  Sort::InsertSort(bool ascendent)
{
	int i, elem, j;
	if (ascendent == true)
		for (i = 1; i < this->k; i++)
		{
			elem = this->v[i];
			j = i - 1;
			while (j >= 0 && this->v[j] > elem)
			{
				this->v[j + 1] = this->v[j];
				j--;
			}
			this->v[j + 1] = elem;
		}
	else
		for (i = 1; i < this->k; i++)
		{
			elem = this->v[i];
			j = i - 1;
			while (j >= 0 && this->v[j] < elem)
			{
				this->v[j + 1] = this->v[j];
				j--;
			}
			this->v[j + 1] = elem;
		}
}

void quickSort(int v[], int st, int dr)
{
	if (st < dr)
	{
		int m = (st + dr) / 2;
		int aux = v[st];
		v[st] = v[m];
		v[m] = aux;
		int i = st, j = dr, d = 0;
		while (i < j)
		{
			if (v[i] > v[j])
			{
				aux = v[i];
				v[i] = v[j];
				v[j] = aux;
				d = 1 - d;
			}
			i += d;
			j -= 1 - d;
		}
		quickSort(v, st, i - 1);
		quickSort(v, i + 1, dr);
	}
}

void  Sort::QuickSort(bool ascendent) {
	quickSort(v, 0, this->k - 1);
}

void  Sort::Print()
{
	int i;
	for (i = 0; i < this->k; i++)
		cout << this->v[i] << ' ';
	cout << endl;
}

int Sort::GetElementsCount()
{
	return this->k;
}

int Sort::GetElementFromIndex(int index)
{
	return this->v[index];
}

