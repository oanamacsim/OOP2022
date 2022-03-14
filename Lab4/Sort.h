#pragma once


class Sort

{
private:
    int* lista = nullptr;
    int nr_elemente;
    void QuickSortRecursive(bool ascendent, int left, int right);
    int partition(bool ascendent, int low, int high);

    // add data members

public:

    // add constuctors

    void InsertSort(bool ascendent = false);

    void QuickSort(bool ascendent = false);

    void BubbleSort(bool ascendent = false);

    void Print();

    int  GetElementsCount();

    int  GetElementFromIndex(int index);

    //list that needs to be sorted out of random values within a specific interval (min , max)
    Sort(int nr_elemente, int min_element, int max_element); 

    //list that needs to be sorted from an existing vector
    Sort(int* vector, int nr_elemente);

    //list that needs to be sorted using variadic parameters
    Sort(int count, ...);

    //list that needs to be sorted from a string
    Sort(char* c);
};