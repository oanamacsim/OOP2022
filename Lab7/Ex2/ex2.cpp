#include <iostream>
#include "myVector.h"
using namespace std;

int main()
{
	vector<int>v;

	for (int i = 1; i <= 256; i++)
		v.push(i);

	v.printAll();

	for (int i = 1; i <= 128; i++)
		v.pop();

	v.printAll();
	v.remove(5);
	v.printAll();
	v.insert(123, 2);
	v.printAll();

	return 0;
}