#include <iostream>
#include "NumberList.h"

using namespace std;

int main()
{
	NumberList vect;
	vect.Init();
	vect.Add(5);
	vect.Add(1);
	vect.Add(8);
	vect.Add(2);
	if (vect.Add(5) == 0)
	{
		cout << "Nu se poate adauga";
	}
	vect.Sort();
	vect.Print();
	return 0;
}