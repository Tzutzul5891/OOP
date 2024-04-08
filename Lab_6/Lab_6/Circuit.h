#pragma once
#include "Car.h"

class Circuit {
private:
	Car** cars;
	double circuitLength;
	Weather weather;
	int numCars = 0;
	double time = 0;

public:
	Circuit();
	void timeConverter(double);
	void SetLength(double);
	void SetWeather(Weather);
	void AddCar(Car*);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
};