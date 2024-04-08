#include "Fiat.h"

Fiat::Fiat() {
    fuelCapacity = 40.0;
    fuelConsumption = 11.0;
    speedSunny = 100.0;
    speedRain = 90.0;
    speedSnow = 80.0;
}

double Fiat::calculateTime(double len, Weather w)
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

const char* Fiat::getName()
{
    return "Fiat";
}