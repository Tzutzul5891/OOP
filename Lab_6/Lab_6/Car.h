#include "Weather.h"
#pragma once

class Car {
	double fuelCapacity;
	double fuelConsumption;
	double speedSunny;
	double speedRain;
	double speedSnow;
	double finishTime;
public:
	virtual double calculateTime(double, Weather) = 0;
	virtual const char* getName() = 0;
	void setFinishTime(double time) {
		finishTime = time;
	}
	double getFinishTime() {
		return finishTime;
	}
};
