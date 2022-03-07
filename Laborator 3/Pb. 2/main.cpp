#include <iostream>
#include "Canvas.h"
using namespace std;
int main()
{
	Canvas p(20,20);
	printf(" Punctul p(1,2)\n");
	p.SetPoint(1, 2, 'p');
	printf(" Linia (...) ce uneste punctele A si B\n");
	p.DrawLine(3, 4, 9, 10, '.');
	p.Print();
	printf(" Cercul:\n");
	p.DrawCircle(10, 10, 5, '*');
	p.FillCircle(10, 10, 5, 'o');
	p.Print();
	p.Clear();
	printf(" Dreptunghiul:\n");
	p.DrawRect(1, 1, 19, 10, '*');
	p.FillRect(1, 1, 19, 10, 'o');
	p.Print();
	p.Clear();
	return 0;
}