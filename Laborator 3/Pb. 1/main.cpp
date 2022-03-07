#include <iostream>
#include <cstring>
#include "Math.h"
using namespace std;

int main()
{

	Math m;
	cout <<"Sum(int, int) = "<< m.Add(2, 3) << endl;
	cout << "Sum(int, int, int) = " << m.Add(2, 3, 4) << endl;//(int, int, int);
	cout << "Add(double, double) = " << m.Add(2.2, 3.4) << endl;
	cout << "Add(double, double, double) = " << m.Add(2.2, 3.4, 4.3) << endl;
	cout << "Mul(int, int) = " << m.Mul(2, 3) << endl;
	cout << "Mul(int, int, int) = " << m.Mul(2, 3, 5) << endl;
	cout << "Mul(double, double) = " << m.Mul(2.2, 3.1) << endl;
	cout << "Mul(double, double, double) = " << m.Mul(2.2, 3.1, 5.3) << endl;
	cout << "Add(int count, ...) = " << m.Add(4, 1, 2, 3, 4)<<endl;
	cout << "Concatenare siruri: "<<m.Add((char*)"Ana", (char*)"Maria");

}