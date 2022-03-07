#include "Math.h"
#include <stdlib.h>
#include <cstdarg>
#include <string.h>

using namespace std;

int Math::Add(int x, int y){
	return x + y;
}

int Math::Add(int x, int y, int z) {
	return x + y + z;
}

int Math::Add(double x, double y) {
	return x + y;
}

int Math::Add(double x, double y, double z) {
	return x + y + z;
}

int Math::Mul(int x, int y) {
	return x * y;
}

int Math::Mul(int x, int y, int z) {
	return  x * y * z;
}

int Math::Mul(double x, double y) {
	return x * y;
}

int Math::Mul(double x, double y, double z) {
	return  x * y * z;
}

int Math::Add(int count, ...) {
	va_list numbers;
	va_start(numbers, count);
	int sum = 0;
	//adaug in suma fiecare element din lista nou creata numbers
	for (int i = 0; i <= count; i++) {
		sum += va_arg(numbers, int);
	}
	va_end(numbers);
	return sum;
}

char* Add(const char* string1, const char* string2) {
	int lengthString1 = strlen(string1);
	int lengthString2 = strlen(string2);
	int newStringLength = lengthString1 + lengthString2 + 1;
	char* newString = new char[newStringLength];

	if (string1 == NULL || string2 == NULL)
		return nullptr;

	//parcurg si copiez caracter cu caracter sirul nr. 1 in sirul nou creat
	for (int i = 0; i < lengthString1; i++) {
		newString[i] = string1[i];
	}

	//parcurg cu indexul i sirul nr. 2
	//sirul nou format incepe de la pozitia lengthString1 unde momentan avem '\0'
	//copiez caracter cu caracter sirul nr. 2 in sirul nou creat
	for (int i = 0, j = lengthString1; i < lengthString2 && j < newStringLength; i++, j++) {
		newString[j] = string2[i];
	}

	newString[newStringLength - 1] = '\0';

	return newString;
}