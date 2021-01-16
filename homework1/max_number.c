/*
 * 12. Написать функцию нахождения максимального из трех чисел.
 */
#include <stdio.h>
#include <stdlib.h>

void find_max() {
    int count, i = 0, max;
    printf("Enter the number of numbers: ");
    scanf("%d", &count);
    int *numbers = (int *) malloc(count * sizeof(int));
    printf("Enter n numbers separated by a space: \n");
    while (i < count) {
        i += scanf("%d", &numbers[i++]);
    }

    max = numbers[0];
    for (i = 1; i < count; i++) {
        max = max > numbers[i] ? max : numbers[i];
    }
    printf("max number is %d\n", max);
    free(numbers);
}