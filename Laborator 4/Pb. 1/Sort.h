#pragma once
class Sort
{
    int* vect;
    int elem;

    public:

    Sort(int numar_element, int min_element, int max_element);
    Sort();
    Sort(int* v, int numar_elemente);
    Sort(int count,...);
    Sort(char* s);
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};