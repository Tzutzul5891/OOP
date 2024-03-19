#include <iostream>
#include "Students.h"
#include "Global.h"

using namespace std;

int main()
{
	Students student, restantier;
	char nume1[256], nume2[256];

	strcpy(nume1, "Stefan");
	strcpy(nume2, "Paul");

	student.SetName(nume1);
	student.SetMathGrade(7.2f);
	student.SetEngGrade(8.0f);
	student.SetHistGrade(10.0f);

	restantier.SetName(nume2);
	restantier.SetMathGrade(7.0f);
	restantier.SetEngGrade(9.3f);
	restantier.SetHistGrade(5.4f);

	cout << "Student: " << student.GetName() << "\n";
	cout << "Nota Mate: " << student.GetMathGrade() << "\n";
	cout << "Nota Engleza: " << student.GetEngGrade() << "\n";
	cout << "Nota Istorie: " << student.GetHistGrade() << "\n";
	cout << "Media notelor: " << student.Media() << "\n";

	cout << "Student: " << restantier.GetName() << "\n";
	cout << "Nota Mate: " << restantier.GetMathGrade() << "\n";
	cout << "Nota Engleza: " << restantier.GetEngGrade() << "\n";
	cout << "Nota Istorie: " << restantier.GetHistGrade() << "\n";
	cout << "Media notelor: " << restantier.Media() << "\n";

	cout << "Comparatie dupa nume: " << CompName(&student, &restantier) << "\n";
	cout << "Comparatie dupa mate: " << CompMathGrade(&student, &restantier) << "\n";
	cout << "Comparatie dupa engleza: " << CompEngGrade(&student, &restantier) << "\n";
	cout << "Comparatie dupa istorie: " << CompHistGrade(&student, &restantier) << "\n";
	cout << "Comparatie dupa medie: " << CompMedie(&student, &restantier) << "\n";
	system("pause");
	return 0;
}