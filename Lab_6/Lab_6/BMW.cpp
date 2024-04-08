#include "BMW.h"

BMW::BMW() {
    fuelCapacity = 50.0;
    fuelConsumption = 15.0;
    speedSunny = 120.0;
    speedRain = 100.0;
    speedSnow = 90.0;
}

double BMW::calculateTime(double len, Weather w)
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

const char* BMW::getName()
{
    return "BMW";
}