#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdlib.h>
#include <iostream>

#include "Ford.h"

Ford::Ford()
{
	this->marca = (char*)(malloc(strlen("Ford") * sizeof(char)));
	strcpy(this->marca, "Ford");
	this->Capacity = 55;
	this->Consumption = 15;
	this->AverageSpeed_Rain = 60;
	this->AverageSpeed_Sunny = 83;
	this->AverageSpeed_Snow = 48;

}

int Ford::Capacity_Consumption()
{
	return this->Capacity * this->Consumption;
}