#include "Volvo.h"

Volvo::Volvo() {
    fuelCapacity = 50.0;
    fuelConsumption = 14.0;
    speedSunny = 110.0;
    speedRain = 95.0;
    speedSnow = 85.0;
}

double Volvo::calculateTime(double len, Weather w)
{
    double speed;
    if (w == Weather::Rain)
        speed = speedRain;
    else if (w == Weather::Sunny)
        speed = speedSunny;
    else
        speed = speedSnow;
    double time = len / speed * 60 * 60;
    double fuelConsumed = fuelConsumption * len / 100;
    if (fuelConsumed > fuelCapacity)
        return -1.0;
    return time;
}

const char* Volvo::getName()
{
    return "Volvo";
}