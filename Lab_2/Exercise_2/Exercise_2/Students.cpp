#include "Students.h"
#include <cstring>
#include <iostream>

using namespace std;

void Students::SetName(char* name)
{
	int i;
	for (i = 0; i < 256; i++)
	{
		this->Name[i] = name[i];
	}
}

char* Students::GetName()
{
	return Name;
}

void Students::SetMathGrade(float grade)
{
	this->MathGrade = grade;
}

float Students::GetMathGrade()
{
	return MathGrade;
}

void Students::SetEngGrade(float grade)
{
	this->EngGrade = grade;
}

float Students::GetEngGrade()
{
	return EngGrade;
}

void Students::SetHistGrade(float grade)
{
	this->HistGrade = grade;
}

float Students::GetHistGrade()
{
	return HistGrade;
}

float Students::Media()
{
	return (MathGrade + EngGrade + HistGrade) / 3;
}