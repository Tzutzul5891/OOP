#include "Circuit.h"
#include <iostream>

using namespace std;

Circuit::Circuit()
{
	weather = Weather::Sunny;
	circuitLength = 0;
	cars = new Car * [10];
}

void Circuit::timeConverter(double time)
{
	int timp = time, hours, minutes, seconds;
	hours = (int)(timp / 3600);
	minutes = (int)((timp / 60) % 60);
	seconds = (int)(timp % 60);
	cout << hours << " hours, " << minutes << " minutes, " << seconds << " seconds";
}

void Circuit::SetLength(double length)
{
	circuitLength = length;
}

void Circuit::SetWeather(Weather w)
{
	weather = w;
}

void Circuit::AddCar(Car* car)
{
	cars[numCars] = car;
	numCars++;
}

void Circuit::Race()
{
	int i;
	cout << "Circuit length: " << circuitLength << "km" << endl;
	for (i = 0; i < numCars; i++)
	{
		Car* car = cars[i];
		time = car->calculateTime(circuitLength, weather);
		if (time == -1.0)
			cout << car->getName() << " did not have enough fuel to finish" << endl;
		else
		{
			cout << car->getName() << " finished the race in " << time << " seconds" << " ( " << time / 60 << " minutes ) " << "( " << time / 3600 << " hours )" << endl;
			car->setFinishTime(time);
		}
	}
}

void Circuit::ShowFinalRanks()
{
	int i, j;
	Car** carstemp = new Car * [numCars];
	for (i = 0; i < numCars; i++)
		carstemp[i] = cars[i];
	for (i = 0; i < numCars; i++)
		for (j = i + 1; j < numCars; j++)
			if (carstemp[i]->getFinishTime() > carstemp[j]->getFinishTime())
				swap(carstemp[i], carstemp[j]);
	cout << "Final ranking:" << endl;
	for (int i = 0; i < numCars; i++) {
		if (carstemp[i]->getFinishTime() > 0)
		{
			cout << carstemp[i]->getName() << ": ";
			{
				timeConverter(carstemp[i]->getFinishTime());
				cout << endl;
			}
		}
	}
	cout << endl;
	delete[] carstemp;
}

void Circuit::ShowWhoDidNotFinish()
{
	int i;
	bool everyoneFinished = true;
	for (i = 0; i < numCars; i++)
	{
		if (cars[i]->getFinishTime() < 0)
		{
			everyoneFinished = false;
			break;
		}
	}
	if (everyoneFinished)
		cout << "Everyone finished the race!" << endl;
	else
	{
		cout << "The following cars did not finish the race:" << endl;
		for (i = 0; i < numCars; i++)
		{
			if (cars[i]->getFinishTime() < 0)
				cout << cars[i]->getName() << endl;
		}
	}
}