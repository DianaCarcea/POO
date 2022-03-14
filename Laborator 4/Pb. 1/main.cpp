#include "Sort.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
	Sort c1(10, 10, 100);
	printf("n = %d\n", c1.GetElementsCount());
	c1.Print();


	int v[5] = { 4,2,3,9,5 };
	Sort c2(v, 5);
	printf("n = %d\n", c2.GetElementsCount());
	printf("Inainte de sortare:\n");
	c2.Print();
	printf("\n");
	printf("Dupa sortarea cu InsertSort:\n");
	c2.InsertSort(1);//crescator
	c2.Print();
	printf("\n");

	Sort c3(6, 6, 5, 4, 3, 2, 1);
	printf("n = %d\n", c3.GetElementsCount());
	printf("Inainte de sortare:\n");
	c3.Print();
	printf("\n");
	printf("Dupa sortarea cu QuickSort:\n");
	c3.InsertSort(1);//crescator
	c3.Print();
	printf("\n");

	char c[] = "5,21,9,3,2";
	Sort c4(c);
	printf("n = %d\n", c4.GetElementsCount());
	printf("Inainte de sortare:\n");
	c4.Print();
	printf("\n");
	printf("Dupa sortarea cu BubbleSort:\n");
	c4.BubbleSort(1);//crescator
	c4.Print();
	printf("\n");

	Sort c5;
	printf("n = %d\n", c5.GetElementsCount());
	c5.Print();

}