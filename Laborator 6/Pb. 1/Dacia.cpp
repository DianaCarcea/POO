#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdlib.h>
#include <iostream>

#include "Dacia.h"

Dacia::Dacia()
{
	this->marca = (char*)(malloc(strlen("Dacia") * sizeof(char)));
	strcpy(this->marca, "Dacia");
	this->Capacity = 52;
	this->Consumption = 20;
	this->AverageSpeed_Rain = 55;
	this->AverageSpeed_Sunny = 80;
	this->AverageSpeed_Snow = 45;

}

int Dacia::Capacity_Consumption()
{
	return this->Capacity * this->Consumption;
}