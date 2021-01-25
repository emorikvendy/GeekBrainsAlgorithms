#include <stdio.h>
#include "sort.h"

void bubble(int *array, int length) {
    int last_change = length - 1, tmp;
    while (last_change > 0) {
        tmp = 0;
        for (int j = 0; j < last_change; ++j) {
            if (array[j] > array[j + 1]) {
                swap(array + j, array + j + 1);
                tmp = j;
            }
        }
        last_change = tmp;
    }
}

void bubble2(int *array, int length) {
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < length - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                swap(array + j, array + j + 1);
            }
        }
    }
}

void shaker(int array[], int length) {
    int left = 0, right = length - 1, tmp;
    while (left < right) {
        tmp = 0;
        for (int i = left; i < right; i++) {
            if (array[i] > array[i + 1]) {
                swap(array + i, array + i + 1);
                tmp = i;
            }
        }
        right = tmp;
        for (int i = right; i > left; --i) {
            if (array[i] < array[i - 1]) {
                swap(array + i, array + i - 1);
                tmp = i;
            }
        }
        left = tmp;
    }
}

void swap(int *first, int *second) {
    *first ^= *second;
    *second ^= *first;
    *first ^= *second;
}

void print(int array[], int length) {
    for (int i = 0; i < length; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
}