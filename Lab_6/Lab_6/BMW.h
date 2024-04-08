#include "Car.h"

class BMW : public Car {
private:
    double fuelCapacity = 40.0;
    double fuelConsumption = 8.0;
    double speedSunny = 70.0;
    double speedRain = 40.0;
    double speedSnow = 30.0;
public:
    BMW();
    virtual const char* getName();
    virtual double calculateTime(double, Weather);
};