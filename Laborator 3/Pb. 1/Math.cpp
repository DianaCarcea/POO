#include <iostream>
#include "Math.h"
#include <stdarg.h>
#include <stdio.h>
using namespace std;


int Math::Add(int a, int b)
{
	return a + b;
}

int Math::Add(int a, int b, int c)
{
	return a + b + c;
}

int Math::Add(double a, double b)
{
	return a + b;
}

int Math::Add(double a, double b, double c)
{
	return a + b + c;
}

int Math::Mul(int a, int b)
{
	return a * b;
}

int Math::Mul(int a, int b, int c)
{
	return a * b * c;
}

int Math::Mul(double a, double b)
{
	return a * b;
}

int Math::Mul(double a, double b, double c)
{
	return a * b * c;
}

int Math::Add(int count, ...)
{
	va_list ap;
	int j;
	double sum = 0;

	va_start(ap, count);
	for (j = 0; j < count; j++) 
	{
		sum += va_arg(ap, int); 
	}
	va_end(ap);

	return sum;
}


char* Math::Add(const char* s1, const char* s2)
{
	if (s1 == nullptr || s2 == nullptr)
		return nullptr;

	char* sir;
	int sizeToRealloc;
	sizeToRealloc = strlen(s1) + strlen(s2) + 1;

	//realocare
	sir = (char*)malloc(sizeToRealloc);
	if (sir == nullptr)
	{
		
		memset(sir, 0, sizeToRealloc);
		if (sir != nullptr)
		{
			memcpy(sir, s1, strlen(s1));
			memcpy(sir+strlen(s1), s2, strlen(s2));
		}

	}
	else
	{
		sir = (char*)realloc(sir, sizeToRealloc);
		memset(sir, 0, sizeToRealloc);

		if (sir != nullptr)
		{
			memcpy(sir, s1, strlen(s1));
			memcpy(sir + strlen(s1), s2, strlen(s2));
		}
	}
	return sir;

	
}
