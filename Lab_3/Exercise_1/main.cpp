#include <iostream>
#include "Math.h"

Math A;

int main()
{
	std::cout << A.Add(5, 10) << std::endl;
	std::cout << A.Add(2, 3, 20) << std::endl;
	std::cout << A.Add(5.2, 10.7) << std::endl;
	std::cout << A.Add(2.3, 3.8, 20.1) << std::endl;
	std::cout << A.Mul(7, 8) << std::endl;
	std::cout << A.Mul(4, 6, 8) << std::endl;
	std::cout << A.Mul(7.4, 8.3) << std::endl;
	std::cout << A.Mul(4.1, 6.7, 8.6) << std::endl;
	std::cout << A.Add(5, 2, 7, 3, 16, 4) << std::endl;
	std::cout << A.Add("123", "456") << std::endl;
}