#include "NumberList.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	NumberList myClass;
	myClass.Init();
	myClass.Add(5);
	myClass.Add(22);
	myClass.Add(11);
	myClass.Add(17);
	myClass.Add(70);
	myClass.Add(0);
	myClass.Add(9);
	myClass.Add(1);
	myClass.Add(33);
	myClass.Sort();
	myClass.Print();

	return 0;
}