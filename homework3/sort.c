#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include "sort.h"

int *counts = (int[]) {10, 100, 1000, 10000, 100000};
int counts_length = 5;

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

void quickSort(int array[], int first, int last) {
    if (first < last) {
        int left = first, right = last, middle = array[(left + right) / 2];
        do {
            while (array[left] < middle && left <= last) left++;
            while (array[right] > middle && right >= first) right--;
            if (left <= right) {
                if (left != right) {
                    swap(&array[left], &array[right]);
                }
                left++;
                right--;
            }
        } while (left <= right);
        quickSort(array, first, right);
        quickSort(array, left, last);
    }
}

void heapify(int array[], int length, int current) {
    int largest = current;
    int left = 2 * current + 1;
    int right = 2 * current + 2;
    if (left < length && array[left] > array[largest]) {
        largest = left;
    }
    if (right < length && array[right] > array[largest]) {
        largest = right;
    }
    if (largest != current) {
        swap(&array[current], &array[largest]);
        heapify(array, length, largest);
    }
}

void heapSort(int array[], int length) {
    for (int i = length / 2 - 1; i >= 0; i--) {
        heapify(array, length, i);
    }
    for (int i = length - 1; i >= 0; i--) {
        swap(&array[0], &array[i]);
        heapify(array, i, 0);
    }
}

void insertionSort(int array[], int length) {
    int tmp, j;
    for (int i = 1; i < length; ++i) {
        j = i;
        while (--j >= 0 && array[j] > array[i]);
        j++;
        switch (i - j) {
            case 1:
                swap(&array[j], &array[i]);
            case 0:
                break;
            default:
                tmp = array[i];
                memcpy(array + j + 1, array + j, (i - j) * sizeof(int));
                array[j] = tmp;
        }
    }
}

void insertionSort2(int array[], int length) {
    int j;
    for (int i = 1; i < length; ++i) {
        j = i;
        while (j > 0 && array[j - 1] > array[j]) {
            swap(&array[j], &array[j - 1]);
            j--;
        }
    }
}


void benchmark() {
    int **arrays = (int **) malloc(counts_length * sizeof(int *)),
            *for_sort;
    struct timeval stop, start;
    srand(time(NULL));
    for (int i = 0; i < counts_length; ++i) {
        arrays[i] = (int *) malloc(counts[i] * sizeof(int));
        for (int j = 0; j < counts[i]; ++j) {
            arrays[i][j] = rand() % counts[i];
        }
    }
    for (int i = 0; i < counts_length; ++i) {
        for_sort = (int *) malloc(counts[i] * sizeof(int));
        gettimeofday(&start, NULL);
        for (int j = 0; j < counts[counts_length - 1 - i]; ++j) {
            memcpy(for_sort, arrays[i], counts[i] * sizeof(int));
            quickSort(for_sort, 0, counts[i] - 1);
        }
        gettimeofday(&stop, NULL);
        printf("quickSort for %d elements %d times took %lu us\n", counts[i], counts[counts_length - 1 - i],
               (stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec);
        free(for_sort);
        basicBenchmark(heapSort, "heapSort", arrays[i], counts[i], counts[counts_length - 1 - i]);
        basicBenchmark(insertionSort, "insertionSort", arrays[i], counts[i], counts[counts_length - 1 - i]);
        basicBenchmark(insertionSort2, "insertionSort2", arrays[i], counts[i], counts[counts_length - 1 - i]);
        basicBenchmark(shaker, "shaker", arrays[i], counts[i], counts[counts_length - 1 - i]);
        basicBenchmark(bubble2, "bubble2", arrays[i], counts[i], counts[counts_length - 1 - i]);
        basicBenchmark(bubble, "bubble", arrays[i], counts[i], counts[counts_length - 1 - i]);
    }
    for (int i = 0; i < counts_length; ++i) {
        free(arrays[i]);
    }
    free(arrays);
}

void basicBenchmark(void (*sort)(int *, int), char *sort_name, int *array, int length, int repeats) {
    struct timeval stop, start;
    int *for_sort = (int *) malloc(length * sizeof(int));
    gettimeofday(&start, NULL);
    for (int j = 0; j < repeats; ++j) {
        memcpy(for_sort, array, length * sizeof(int));
        sort(for_sort, length);
    }
    gettimeofday(&stop, NULL);
    printf("%s for %d elements %d times took %lu us\n", sort_name, length, repeats,
           (stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec);
    free(for_sort);
}