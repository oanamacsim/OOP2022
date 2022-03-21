#include "Number.h"
#include <string.h>
#include <iostream>

using namespace std;

Number::Number(const char* value, int base)
{
	int length = strlen(value);
	this->base = base;
	this->number = new char[length + 1];
	strcpy(this->number, value);
	number[length] = '\0';
}

Number::Number(int toChange)
{
	int length = (int)log10(toChange) + 1;
	this->base = 10;
	this->number = new char[length + 1];
	_itoa(toChange, number, 10);
}

Number::Number(const char* toChange)
{
    int lenght = strlen(toChange);
    this->base = 10;
    this->number = new char[lenght + 1];
    strcpy(number, toChange);
}

Number::~Number(){
}

char GetCorespondingChar(int digit)
{
    if (digit <= 9)
        return '0' + digit;
    else
        return 'A' + digit - 10;
}

int GetCorespondingInt(char digit)
{
    if (digit >= '0' && digit <= '9')
        return digit - '0';
    else
        return 10 + digit - 'A';
}

int GetNumOfDigits(int n)
{
    int count = 0;
    if (n == 0)
        count = 1;
    while (n)
    {
        n /= 10;
        count++;
    }
    return count;
}

void Number::SwitchBase(int newBase)
{
    int k = 1, lenght = strlen(number), nr = 0;
    //transforming into b10
    for (int i = lenght - 1; i >= 0; i--)
    {
        nr = nr + GetCorespondingInt(number[i]) * k;
        k *= base;
    }
    //we need to reallocate memory for the number
    delete[] number;
    number = new char[50];
    k = 0;
    while (nr)//transforming into newBase from b10
    {
        number[k++] = GetCorespondingChar(nr % newBase);
        nr /= newBase;
    }
    number[k] = '\0';
    int i = 0;
    k--;
    while (i < k) {
        swap(number[i], number[k]);
        k--;
    }

    base = newBase;
}

void Number::Print()
{
   cout << number << '\n';
}

int Number::GetDigitsCount()
{
    return strlen(number);
}

int Number::GetBase()
{
    return base;
}


Number operator+(Number toAdd1, Number toAdd2) {
    //choosing the biggest number as the base
    int newBase = max(toAdd1.base, toAdd2.base); 
    int b1 = toAdd1.base;
    int b2 = toAdd2.base;
    toAdd1.SwitchBase(10);
    toAdd2.SwitchBase(10);

    int val1 = atoi(toAdd1.number);
    int val2 = atoi(toAdd2.number);
    int sum = val1 + val2;

    Number res("", newBase);
    delete[] res.number;
    res.number = new char[(int)log10(sum) + 2];
    _itoa(sum, res.number, 10);
    res.base = 10;
    res.SwitchBase(newBase);
    toAdd1.SwitchBase(b1);
    toAdd2.SwitchBase(b2);
    return res;
}


Number operator-(Number toAdd1, Number toAdd2) {

    int newBase = max(toAdd1.base, toAdd2.base);
    int b1 = toAdd1.base;
    int b2 = toAdd2.base;
    toAdd1.SwitchBase(10);
    toAdd2.SwitchBase(10);

    int val1 = atoi(toAdd1.number);
    int val2 = atoi(toAdd2.number);
    int diff = val1 + val2;
    Number res("", newBase);
    delete[] res.number;
    res.number = new char[(int)log10(diff) + 2];
    _itoa(diff, res.number, 10);
    res.base = 10;
    res.SwitchBase(newBase);
    toAdd1.SwitchBase(b1);
    toAdd2.SwitchBase(b2);
    return res;
}


Number& Number::operator=(Number toChange)
{
    this->number = toChange.number;
    this->base = toChange.base;
    return (*this);
}



bool Number::operator > (Number toCompare) {
    int b1 = this->base;
    int b2 = toCompare.base;
    int a, b;

    Number n1(number, this->base);
    Number n2 = toCompare;
    n1.SwitchBase(10);
    n2.SwitchBase(10);
    a = atoi(n1.number);
    b = atoi(n2.number);
    n1.SwitchBase(b1);
    n2.SwitchBase(b2);
    return a > b;
}

bool Number::operator>=(Number toCompare)
{
    int b1 = this->base;
    int b2 = toCompare.base;
    int a, b;

    Number n1(number, this->base);
    Number n2 = toCompare;
    n1.SwitchBase(10);
    n2.SwitchBase(10);
    a = atoi(n1.number);
    b = atoi(n2.number);
    n1.SwitchBase(b1);
    n2.SwitchBase(b2);
    return a >= b;
}

bool Number::operator<(Number toCompare)
{
    int b1 = this->base;
    int b2 = toCompare.base;
    int a, b;

    Number n1(number, this->base);
    Number n2 = toCompare;
    n1.SwitchBase(10);
    n2.SwitchBase(10);
    a = atoi(n1.number);
    b = atoi(n2.number);
    n1.SwitchBase(b1);
    n2.SwitchBase(b2);
    return a < b;
}

bool Number::operator<=(Number toCompare)
{
    int b1 = this->base;
    int b2 = toCompare.base;
    int a, b;

    Number n1(number, this->base);
    Number n2 = toCompare;
    n1.SwitchBase(10);
    n2.SwitchBase(10);
    a = atoi(n1.number);
    b = atoi(n2.number);
    n1.SwitchBase(b1);
    n2.SwitchBase(b2);
    return a <= b;

}

bool Number::operator==(Number toCompare)
{
    int b1 = this->base;
    int b2 = toCompare.base;
    int a, b;

    Number n1(number, this->base);
    Number n2 = toCompare;
    n1.SwitchBase(10);
    n2.SwitchBase(10);
    a = atoi(n1.number);
    b = atoi(n2.number);
    n1.SwitchBase(b1);
    n2.SwitchBase(b2);
    return a == b;

}

Number& Number::operator+=(Number toAdd) {
    int saveBase = base;

    SwitchBase(10);
    toAdd.SwitchBase(10);
    int val1 = atoi(number);
    int val2 = atoi(toAdd.number);
    _itoa(val1 + val2, number, 10);
    SwitchBase(saveBase);
    return (*this);
}

Number& Number::operator-=(Number toAdd) {
    int saveBase = base;

    SwitchBase(10);
    toAdd.SwitchBase(10);
    int val1 = atoi(number);
    int val2 = atoi(toAdd.number);
    _itoa(val1 - val2, number, 10);
    SwitchBase(saveBase);
    return (*this);
}


Number& Number::operator--() {
    int length = strlen(number);

    for (int i = length - 1; i > 0; i--)
        number[i] = number[i - 1];
    return (*this);
}

Number& Number::operator--(int) {
    this->number++;
    return (*this);
}

char Number::operator[](int index) {
    return number[index];
}

Number& Number::operator-()
{
    int n = atoi(number);
    int base = this->base;
    int maxDigit, maxNum = 0, digits = 0, num = n;

    // Calculate number of digits in the given number 
    while (n != 0)
    {
        digits++;
        n = n / 10;
    }

    // Largest digit in the number system with base b 
    maxDigit = base - 1;

    // Largest number in the number system with base b 
    while (digits--)
    {
        maxNum = maxNum * 10 + maxDigit;
    }

    // return Complement 
    int complement = maxNum - num;
    _itoa(complement, number, 10);
    return (*this);
}