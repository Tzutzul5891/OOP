#include "Seat.h"

Seat::Seat() {
    fuelCapacity = 45.0;
    fuelConsumption = 12.0;
    speedSunny = 105.0;
    speedRain = 90.0;
    speedSnow = 85.0;
}

double Seat::calculateTime(double len, Weather w)
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

const char* Seat::getName()
{
    return "Seat";
}