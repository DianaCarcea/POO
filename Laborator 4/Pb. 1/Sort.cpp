
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include "Sort.h"
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdarg.h>
#include <cstring>


Sort::Sort(int numar_element, int min_element, int max_element)
{
	time_t t;
	srand((unsigned)time(&t));
	elem = numar_element;
	vect = (int*)(malloc(numar_element * sizeof(int)));//alocare vector
	for (int i = 0;i < numar_element;i++)
		vect[i] = min_element + rand() % (min_element - max_element + 1);
	//for (int i = 0;i < numar_element;i++)
	//	printf("%d ", vect[i]);
}

Sort::Sort(int* vector, int numar_element)
{
	elem = numar_element;
	vect = (int*)(malloc(numar_element * sizeof(int)));//alocare vector
	for (int i = 0;i < numar_element;i++)
		vect[i] = vector[i];

	printf("\n");
}

Sort::Sort(int count, ...)
{
	va_list v1;
	va_start(v1, count);
	elem = count;
	vect = (int*)(malloc(count * sizeof(int)));
	for (int i = 0; i < count; i++)
		vect[i] = va_arg(v1, int);
	va_end(v1);

}

Sort::Sort(char* s)
{
	char* p;
	int k = 1;
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] == ',')
			k++;
	}
	elem = k;
	vect = (int*)(malloc(k * sizeof(int)));
	k = 0;
	p = strtok(s, ",");
	while (p)
	{
		int x = 0;
		for (int i = 0; i < strlen(p); i++)
		{
			x = x * 10 + (p[i] - 48);
		}
		vect[k++] = x;
		p = strtok(NULL, ",");
	}
}

Sort::Sort(): vect(new int[5] {3, 8, 9, 4, 5})
{
	elem = 5;

}

void Sort::Print()
{
	for (int i = 0; i < elem; i++)
		printf("%d ", vect[i]);
	printf("\n");
}

int  Sort::GetElementsCount()
{
	return elem;
}

int  Sort::GetElementFromIndex(int index)
{
	return vect[index];
}

void Sort::InsertSort(bool ascendent)
{
	int n = Sort::GetElementsCount(),i,j,piv;
	for (i = 1; i < n; i++)
	{
		piv = vect[i];
		j = i - 1;
		if (ascendent == 0)
		while (j >= 0 && vect[j] < piv)
		{
			vect[j + 1] = vect[j];
			j = j - 1;
		}

		if (ascendent == 1)
		while (j >= 0 && vect[j] > piv)
		{
			vect[j + 1] = vect[j];
			j = j - 1;
		}
		vect[j + 1] = piv;
	}
}

int piv(int v[], int st, int dr, bool ascendent)
{
	int poz = 0, aux;
	while (st < dr)
	{
		if (poz == 0)
		{
			if (ascendent == 1)
			{
				if (v[dr] >= v[st])
					dr--;
			}
			else
			{
				if (v[dr] <= v[st])
					dr--;
			}
		}
		else
		{
			if (ascendent == 1)
			{
				if (v[dr] >= v[st])
					st++;
			}
			else
			{
				if (v[dr] <= v[st])
					st++;
			}

		}
		if (ascendent == 1)
		{
			if (st < dr && v[dr] <= v[st])
			{
				aux = v[st];
				v[st] = v[dr];
				v[dr] = aux;
				poz = !poz;
			}
		}
		else if (st < dr && v[dr] >= v[st])
		{
			aux = v[st];
			v[st] = v[dr];
			v[dr] = aux;
			poz = !poz;
		}

	}
	return st;
}
void QSort(int v[], int st, int dr, bool ascendent)
{
	if (st < dr)
	{
		int pivot = piv(v, st, dr, ascendent);
		QSort(v, st, pivot - 1, ascendent);
		QSort(v, pivot + 1, dr, ascendent);
	}
}

void Sort::QuickSort(bool ascendent)
{
	int nr_elem = Sort::GetElementsCount();
	QSort(vect, 0, nr_elem - 1, ascendent);
}

void Sort::BubbleSort(bool ascendent)
{
	int ultim, n1, i;
	int n = Sort::GetElementsCount();
	ultim = n - 1;
	if (ascendent == 1)
		while (ultim > 0)
		{
			n1 = ultim;
			ultim = 0;
			for (i = 0;i <n1;i++)

					if (vect[i] > vect[i + 1])
					{
						int aux = vect[i];
						vect[i] = vect[i + 1];
						vect[i + 1] = aux;
						ultim = i;///ma opresc pe pozitia care mai trb de interschimbat
					}

		}
	else
		if (ascendent == 0)
		while (ultim > 0)
		{
			n1 = ultim;
			ultim = 0;
			for (i = 0;i < n1;i++)
					if (vect[i] > vect[i + 1])
					{
						int aux = vect[i];
						vect[i] = vect[i + 1];
						vect[i + 1] = aux;
						ultim = i;///ma opresc pe pozitia care mai trb de interschimbat
					}
		}
}
