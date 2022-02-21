#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()
{
	int suma=0,nr,i;
	FILE* fp;
	fopen_s(&fp, "in.txt", "r");
	if (fopen_s(&fp, "in.txt", "r") != 0)
	{
		printf("Eroare. Nu am putut deschide fisierul\n");
	}
	else 
	{
		printf("Am deschis fisierul cu success!\n");
		char myString[200];

		while (fgets(myString, 200, fp))
		{
			myString[strlen(myString) - 1] = '\0';
			int n = strlen(myString);
			nr = 0;
			printf("Am citit din fisier: %s\n", myString);

			for(i=0;i<n;i++)
				nr = nr * 10 + (int(myString[i]) - '0');
				
			suma = suma + nr;
		}
	}
	fclose(fp);
	printf ("Suma numerelor este: %d",suma);
}