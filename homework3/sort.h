#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

void bubble(int array[], int length);

void bubble2(int array[], int length);

void shaker(int array[], int length);

void swap(int *first, int *second);

void print(int array[], int length);

void quickSort(int array[], int first, int last);

void heapify(int array[], int length, int current);

void heapSort(int array[], int length);

void insertionSort(int array[], int length);

void insertionSort2(int array[], int length);

void benchmark();

void basicBenchmark(void (*sort)(int *, int), char *sort_name, int *array, int length, int repeats);

#endif