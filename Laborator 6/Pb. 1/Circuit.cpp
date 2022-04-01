#include <cstring>
#include <stdlib.h>
#include <iostream>

#include "Circuit.h"
#include "Weather.h"
#include "Car.h"

using namespace std;

void Circuit::SetLength(int value)
{
	this->lungime_traseu = value;
}

void Circuit::SetWeather(Weather vreme)
{
	this->vreme=vreme;
}

Circuit::Circuit()
{
	this->max_index = 100;
	this->crt_index = 0;
	this->vectorDate = (Car**)(malloc(this->max_index * sizeof(Car*)));
}

bool Circuit::AddCar(Car* myCar)
{
	if (this->crt_index < this->max_index)
	{
		this->vectorDate[this->crt_index++] = myCar;
		return true;
	}
	return false;
}

void Circuit::Race()
{
	int i,j,k;
	Car* aux;

	for (i = 0; i < this->crt_index; i++)
	{
		//Termin cursa daca: capacitate * consum >= lungime traseu
		if (vectorDate[i]->Capacity_Consumption() >= this->lungime_traseu)
		{
			if (this->vreme == 0)	//Pe ploaie
			{
				for (j = 0; j < this->crt_index - 1; j++)
					for (k = j + 1; k < this->crt_index; k++)
					{
						//Ordonez masinile in funtie de timpul lor de sosire la FINISH
						if (vectorDate[j]->AverageSpeed_Rain < vectorDate[k]->AverageSpeed_Rain)
						{
							aux = vectorDate[j];
							vectorDate[j] = vectorDate[k];
							vectorDate[k] = aux;
						}
					}
			}

			if (this->vreme == 1)	//Pe soare
			{
				for (j = 0; j < this->crt_index - 1; j++)
					for (k = j + 1; k < this->crt_index; k++)
					{
						//Ordonez masinile in funtie de timpul lor de sosire la FINISH
						if (vectorDate[j]->AverageSpeed_Sunny < vectorDate[k]->AverageSpeed_Sunny)
						{
							aux = vectorDate[j];
							vectorDate[j] = vectorDate[k];
							vectorDate[k] = aux;
						}
					}
			}

			if (this->vreme == 2)	//Pe ninsoare
			{
				for (j = 0; j < this->crt_index - 1; j++)
					for (k = j + 1; k < this->crt_index; k++)
					{
						//Ordonez masinile in funtie de timpul lor de sosire la FINISH
						if (vectorDate[j]->AverageSpeed_Snow < vectorDate[k]->AverageSpeed_Snow)
						{
							aux = vectorDate[j];
							vectorDate[j] = vectorDate[k];
							vectorDate[k] = aux;
						}
					}
			}

		}
		else
		{
			//Nu ajung la final
			vectorDate[i]->Capacity= -1;
		}
	}
}


void Circuit::ShowFinalRanks()
{
	int i;
	for (i = 0; i < this->crt_index; i++)
	{
		if (vectorDate[i]->Capacity != -1)
			if (this->vreme == 0)
				printf("Masina: %s a terminat cursa in %d de minute!\n", vectorDate[i]->marca, lungime_traseu * 60 / vectorDate[i]->AverageSpeed_Rain);
			else if (this->vreme == 1)
				printf("Masina: %s a terminat cursa in %d de minute!\n", vectorDate[i]->marca, lungime_traseu * 60 / vectorDate[i]->AverageSpeed_Sunny);
			else if (this->vreme == 2)
				printf("Masina: %s a terminat cursa in %d de minute!\n", vectorDate[i]->marca, lungime_traseu * 60 / vectorDate[i]->AverageSpeed_Snow);
		
	}
}


void Circuit::ShowWhoDidNotFinis()
{
	int i;
	for (i = 0; i < this->crt_index; i++)
	{
		if (vectorDate[i]->Capacity == -1)
			printf("Masina: %s nu a terminat cursa!\n", vectorDate[i]->marca);
	}
}