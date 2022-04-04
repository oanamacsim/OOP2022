#pragma once

class Exemplu
{
	int x;
public:
	Exemplu();
	int getX();
};



Exemplu::Exemplu()
{
	x = 10;
}

int Exemplu::getX()
{
	return x;
}