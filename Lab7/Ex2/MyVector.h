#pragma once
#include "Exemplu.h"
using namespace std;

template <class T>
class vector
{
public:
	void push(T x)
	{
		if (!haveMemory())
			doubleMemory();
		arr[size++] = x;
	}

	void pop()
	{
		size--;
		if (size < memoryAlocated / 2) //we need to realocateMemory
			divideBy2Memory();
	}

	void remove(int poz)
	{
		T* newArr = new T[size];
		copy(arr, arr + poz, newArr);
		copy(arr + poz + 1, arr + size, newArr + poz);
		delete[] arr;
		arr = newArr;
		size--;
		if (size < memoryAlocated / 2) //we need to realocateMemory
			divideBy2Memory();
	}

	void insert(T toAdd, int poz)
	{
		if (!haveMemory())
			doubleMemory();
		T* newArr = new T[size + 1];
		copy(arr, arr + poz, newArr);
		copy(arr + poz, arr + size, newArr + poz + 1);
		delete[] arr;
		arr = newArr;
		arr[poz] = toAdd;
		size++;
	}

	vector()
	{
		arr = new T[1];
		size = 0;
		memoryAlocated = 1;
	}

	void printAll()
	{
		cout << '\n';
		cout << "Memorie alocata: " << memoryAlocated << '\n';
		cout << "Numar elemente vector: " << size << '\n';
		cout << "Elemente vector: ";
		for (int i = 0; i < size; i++)
			cout << arr[i] << ' ';
		cout << '\n';
	}
	
private:
	T* arr;
	int size;
	int memoryAlocated;

	bool haveMemory()
	{
		return(memoryAlocated > size);
	}

	void doubleMemory()
	{

		T* newArr = new T[memoryAlocated * 2];
		copy(arr, arr + memoryAlocated, newArr);
		delete[] arr;
		arr = newArr;
		memoryAlocated *= 2;
	}

	void divideBy2Memory()
	{
		T* newArr = new T[memoryAlocated / 2];
		copy(arr, arr + memoryAlocated / 2, newArr);
		delete[] arr;
		arr = newArr;
		memoryAlocated /= 2;
	}
};
