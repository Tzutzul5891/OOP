#include <iostream>
#include "Canvas.h"
using namespace std;
int main()
{
    Canvas c(100, 100);
    c.DrawRect(20, 80, 70, 20, '*');
    c.DrawCircle(15, 10, 5, '*');
    c.FillRect(20, 80, 70, 20, '=');
    c.FillCircle(15, 10, 5, '=');
    c.SetPoint(90, 10, 'x');
    c.DrawLine(10, 90, 17, 95, '%');
    c.Print();
    c.Clear();
    return 0;
}