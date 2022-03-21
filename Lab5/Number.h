#pragma once
class Number
{
	// add data members
	char* number;
	int base;
public:

	Number(const char* value, int base); // where base is between 2 and 16
	Number(int);
	Number(const char*);
	~Number();

	friend Number operator+(Number toAdd1, Number toAdd2);
	friend Number operator-(Number toAdd1, Number toAdd2);
	Number& operator=(Number toChange);

	bool operator>(Number toCompare);
	bool operator>=(Number toCompare);
	bool operator<(Number toCompare);
	bool operator<=(Number toCompare);
	bool operator==(Number toCompare);

	Number& operator+=(Number toAdd);
	Number& operator-=(Number toAdd);
	Number& operator--();
	Number& operator--(int);
	Number& operator-();

	char operator[](int index);
	void SwitchBase(int newBase);

	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base
};