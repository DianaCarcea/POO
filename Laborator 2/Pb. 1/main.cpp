#include <iostream>
#include "NumberList.h"
using namespace std;

int main()
{
	NumberList l;
	l.Init();//count = 0

	//numbers[] = {3, 9, 6, 5, 2}
	l.Add(3);
	l.Add(9);
	l.Add(6);
	l.Add(5);
	l.Add(2);

	l.Sort();

	//numbers[] = {2, 3, 5, 6, 9}
	l.Print();
	
}