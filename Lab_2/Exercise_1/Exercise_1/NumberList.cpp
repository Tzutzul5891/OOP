#include "NumberList.h"
#include <iostream>

using namespace std;


void NumberList::Init()
{
    this->count = 0;
}

bool NumberList::Add(int x)
{
    if (this->count >= 10)
    {
        return false;
    }

    this->numbers[this->count] = x;
    count++;
    return true;
}

void NumberList::Sort()
{
    int i;
    for (int i = 0; i < count; i++)
    {
        for (int j = i + 1; j < count; j++) {
            if (this->numbers[i] > this->numbers[j])
            {
                int temp = this->numbers[i];
                this->numbers[i] = this->numbers[j];
                this->numbers[j] = temp;
            }
        }
    }
}

void NumberList::Print()
{
    int i;
    for (i = 0; i <
        count; i++)
    {
        printf("%d", this->numbers[i]);
    }
}