#include "RangeRover.h"

RangeRover::RangeRover() {
    fuelCapacity = 70.0;
    fuelConsumption = 18.0;
    speedSunny = 110.0;
    speedRain = 100.0;
    speedSnow = 95.0;
}

double RangeRover::calculateTime(double len, Weather w)
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

const char* RangeRover::getName()
{
    return "RangeRover";
}