#pragma once
class Students
{
	char Name[256];
	float MathGrade;
	float EngGrade;
	float HistGrade;
public:
	void SetName (char* name);
	char* GetName ();
	void SetMathGrade (float grade);
	float GetMathGrade ();
	void SetEngGrade (float grade);
	float GetEngGrade ();
	void SetHistGrade (float grade);
	float GetHistGrade ();
	float Media ();
};