#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdlib.h>
#include <iostream>

#include "Toyota.h"

Toyota::Toyota()
{
	this->marca = (char*)(malloc(strlen("Toyota") * sizeof(char)));
	strcpy(this->marca, "Toyota");
	this->Capacity = 58;
	this->Consumption = 25;
	this->AverageSpeed_Rain = 65;
	this->AverageSpeed_Sunny = 95;
	this->AverageSpeed_Snow = 50;

}

int Toyota::Capacity_Consumption()
{
	return this->Capacity * this->Consumption;
}