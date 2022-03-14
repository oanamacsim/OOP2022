#include "Sort.h"
#include <stdio.h> 
#include <time.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <iostream>

using namespace std;

Sort::Sort(int nr_elemente, int min_element, int max_element) {
	
	lista = new int[nr_elemente];

	time_t t;
	srand((unsigned)time(&t));
	for (int i = 0; i < nr_elemente; i++) {
		lista[i] = min_element + rand() % (min_element - max_element + 1);
	}
}

Sort::Sort(int* vector, int nr_elemente) {
	
	lista = new int[nr_elemente];

	for (int i = 0; i < nr_elemente; i++) {
		lista[i] = vector[i];
	}
}

Sort::Sort(int count, ...) {
	
	lista = new int[count];

	va_list ap;
	va_start(ap, count);
	for (int i = 0; i < count; i++) {
		lista[i] = va_arg(ap, int);
	}
	va_end(ap);
}

Sort::Sort(char* input)
{
	int count = 0, length = strlen(input);
	for (int i = 0; i < length; i++)
		if (input[i] == ',')
			count++;
	count++;
	//the number of numbers in the input is equal with the number of commas + 1

	lista = new int[count];

	char* p = strtok(input, ",");
	for (int i = 0; i < count; i++)
	{

		lista[i] = atoi(p);
		p = strtok(NULL, ",");
	}

}

void Sort::Print()
{
	for (int i = 0; i < nr_elemente; i++)
		cout << lista[i] << ' ';
	cout << endl;
}

int Sort::GetElementsCount()
{
	return nr_elemente;
}

int Sort::GetElementFromIndex(int index)
{
	if (index < nr_elemente && index >= 0)
		return lista[index];
	return -1;
}

void Sort::BubbleSort(bool ascendent)
{
	if (ascendent)
	{
		bool sortat;
		do {
			sortat = true;
			for (int i = 0; i < nr_elemente - 1; i++)
				if (lista[i] > lista[i + 1])
				{
					swap(lista[i], lista[i + 1]);
					sortat = false;
				}
		} while (!sortat);
	}
	else
	{
		bool sorted;
		do {
			sorted = true;
			for (int i = 0; i < nr_elemente - 1; i++)
				if (lista[i] < lista[i + 1])
				{
					swap(lista[i], lista[i + 1]);
					sorted = false;
				}
		} while (!sorted);
	}
}

void Sort::InsertSort(bool ascendent) {

	int i, key, j;
	if (ascendent)
		for (i = 1; i < nr_elemente; i++)
		{
			key = lista[i];
			j = i - 1;

			/* Move elements of arr[0..i-1], that are
			greater than key, to one position ahead
			of their current position */
			while (j >= 0 && lista[j] > key)
			{
				lista[j + 1] = lista[j];
				j = j - 1;
			}
			lista[j + 1] = key;
		}
	else
		for (i = 1; i < nr_elemente; i++)
		{
			key = lista[i];
			j = i - 1;

			/* Move elements of arr[0..i-1], that are
			greater than key, to one position ahead
			of their current position */
			while (j >= 0 && lista[j] < key)
			{
				lista[j + 1] = lista[j];
				j = j - 1;
			}
			lista[j + 1] = key;
		}
}

int Sort::partition(bool ascendent, int low, int high)
{
	int pivot = lista[high]; // pivot 
	int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

	if (ascendent)
	{
		for (int j = low; j <= high - 1; j++)
		{
			// If current element is smaller than the pivot 
			if (lista[j] < pivot)
			{
				i++; // increment index of smaller element 
				std::swap(lista[i], lista[j]);
			}
		}
		std::swap(lista[i + 1], lista[high]);
	}
	else
	{
		for (int j = low; j <= high - 1; j++)
		{
			// If current element is smaller than the pivot 
			if (lista[j] > pivot)
			{
				i++; // increment index of smaller element 
				std::swap(lista[i], lista[j]);
			}
		}
		std::swap(lista[i + 1], lista[high]);
	}
	return (i + 1);
}

void Sort::QuickSortRecursive(bool ascendent, int low, int high)
{
	if (low < high)
	{
		int pi = partition(ascendent, low, high);
		QuickSortRecursive(ascendent, low, pi - 1);
		QuickSortRecursive(ascendent, pi + 1, high);
	}
}

void Sort::QuickSort(bool ascendent)
{
	QuickSortRecursive(ascendent, 0, nr_elemente - 1);
}