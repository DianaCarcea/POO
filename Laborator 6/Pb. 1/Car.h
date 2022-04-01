#pragma once
#include <stdio.h>

class Car {

	public:
		char* marca;
		int Capacity;
		int Consumption;
		int AverageSpeed_Rain;
		int AverageSpeed_Sunny;
		int AverageSpeed_Snow;

		virtual int Capacity_Consumption() = 0;
};