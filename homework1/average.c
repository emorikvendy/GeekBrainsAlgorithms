/*
 * 11. С клавиатуры вводятся числа, пока не будет введен 0. Подсчитать среднее арифметическое всех
 * положительных четных чисел, оканчивающихся на 8.
 */
#include <stdio.h>
#include "average.h"

void average() {
    int current, sum = 0, count = 0;
    printf("enter numbers, enter 0 to complete\n");
    while (1) {
        scanf("%d", &current);
        if (current == 0) {
            break;
        }
        if (current > 0 && current % 10 == 8) {
            sum += current;
            count++;
        }
    }
    if (count == 0) {
        printf("you have not entered any suitable numbers");
        return;
    }
    printf("average is %f", (double) sum / (double) count);
}