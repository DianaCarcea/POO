#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdlib.h>
#include <iostream>

#include "Mercedes.h"

Mercedes::Mercedes()
{
	this->marca = (char*)(malloc(strlen("Mercedes") * sizeof(char)));
	strcpy(this->marca, "Mercedes");
	this->Capacity = 80;
	this->Consumption = 15;
	this->AverageSpeed_Rain = 65;
	this->AverageSpeed_Sunny = 100;
	this->AverageSpeed_Snow = 58;

}

int Mercedes::Capacity_Consumption()
{
	return this->Capacity * this->Consumption;
}