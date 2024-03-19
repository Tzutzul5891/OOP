#include "Global.h"
#include <iostream>
#include <cstring>

using namespace std;

int CompName(Students* a, Students* b)
{
	char* name1 = a->GetName();
	char* name2 = b->GetName();
	if (strcmp(name1, name2) == 0)
		return 0;
	else if (strcmp(name1, name2) > 0)
		return 1;
	else
		return -1;
}

int CompMathGrade(Students* a, Students* b)
{
	float nota1 = a->GetMathGrade();
	float nota2 = b->GetMathGrade();
	if (nota1 == nota2)
		return 0;
	else if (nota1 > nota2)
		return 1;
	else
		return -1;
}

int CompEngGrade (Students* a, Students* b)
{
	float nota1 = a->GetEngGrade();
	float nota2 = b->GetEngGrade();
	if (nota1 == nota2)
		return 0;
	else if (nota1 > nota2)
		return 1;
	else
		return -1;
}

int CompHistGrade (Students* a, Students* b)
{
	float nota1 = a->GetHistGrade();
	float nota2 = b->GetHistGrade();
	if (nota1 == nota2)
		return 0;
	else if (nota1 > nota2)
		return 1;
	else
		return -1;
}

int CompMedie(Students* a, Students* b)
{
	float media1 = a->Media();
	float media2 = b->Media();
	if (media1 == media2)
		return 0;
	else if (media1 > media2)
		return 1;
	else
		return -1;
}