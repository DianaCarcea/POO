#include "Student.h"
#include <iostream>
#include <cstring>

void Student::SetName(char *s)
{
	strcpy_s(Name, s);
}

char* Student::GetName()
{
	return Name;
}

void Student::SetMath(float n)
{
	Math = n;	
}

float Student::GetMath()
{
	return Math;
}

void Student::SetEnglish(float n)
{
	English = n;
}

float Student::GetEnglish()
{
	return English;
}

void Student::SetHistory(float n)
{
	History = n;
}

float Student::GetHistory()
{
	return History;
}

float Student::GetAverage()
{
	Average = (Math + English + History) / 3;
	return Average;
}

