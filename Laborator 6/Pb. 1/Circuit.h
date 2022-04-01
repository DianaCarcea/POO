#pragma once
#include "Weather.h"
#include "Car.h"
class Circuit
{
	int lungime_traseu;
	int max_index,crt_index;
	Car** vectorDate;
	Weather vreme;

public:
	Circuit();
	bool AddCar(Car* pointerCar);
	void SetLength(int value);
	void SetWeather(Weather vreme);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinis();
};

