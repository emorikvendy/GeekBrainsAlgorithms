#include "search.h"

int binary(int array[], int length, int needle) {
    int left = 0, right = length - 1, i;
    while (left <= right) {
        i = (right + left) / 2;
        if (array[i] > needle) {
            right = i - 1;
        } else if (array[i] < needle) {
            left = i + 1;
        } else {
            return i;
        }
    }
    return -1;
}