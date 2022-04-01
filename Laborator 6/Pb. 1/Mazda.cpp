#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdlib.h>
#include <iostream>

#include "Mazda.h"

Mazda::Mazda()
{
	this->marca = (char*)(malloc(strlen("Mazda") * sizeof(char)));
	strcpy(this->marca, "Mazda");
	this->Capacity = 35;
	this->Consumption = 20;
	this->AverageSpeed_Rain = 40;
	this->AverageSpeed_Sunny = 98;
	this->AverageSpeed_Snow = 30;
}

int Mazda::Capacity_Consumption()
{
	return this->Capacity * this->Consumption;
}