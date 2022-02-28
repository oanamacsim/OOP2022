#include "NumberList.h"
#include <iostream>

using namespace std;

void NumberList::Init()
{
	count = 0;
}

bool NumberList::Add(int x)
{
	if (count >= 10)
		return false; 
	numbers[count] = x;
	count++;
	return true;
}

void NumberList::Sort()
{
	bool isSorted;
	do
	{
		isSorted = true;
		for(int i = 0; i < count; i++)
			if (numbers[i] > numbers[i + 1])
			{
				int aux = numbers[i];
				numbers[i] = numbers[i + 1];
				numbers[i + 1] = aux;
				isSorted = false;
			}
	} while (!isSorted);
}

void NumberList::Print()
{
	for (int i = 0; i < count; i++)
		cout << numbers[i] << " ";
}