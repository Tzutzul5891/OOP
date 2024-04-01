#pragma once
class Sort
{
    int* v;
    int k;
public:
    Sort(int nrElem, int min, int max);
    Sort(int v[1000], int nr);
    Sort(char* s);
    Sort(int nrP...);
    Sort();
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};