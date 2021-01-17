/*
 * 14. * Автоморфные числа. Натуральное число называется автоморфным, если оно равно последним
 * цифрам своего квадрата. Например, 25 \ :sup: `2` = 625. Напишите программу, которая вводит
 * натуральное число N и выводит на экран все автоморфные числа, не превосходящие N
*/
#include <stdio.h>
#include "math.h"
#include "automorphic_numbers.h"

void automorphic_numbers() {
    int number, digits;
    long square, tenth_power;
    printf("Please enter an integer:");
    scanf("%d", &number);
    int printed = 1;
    for (int i = 0; i < number; ++i) {
        if (i == 0 || i == 1) {
            printf("%d\t", i);
            printed++;
            continue;
        }
        if (i % 10 != 5 && i % 10 !=6) {
            continue;
        }
        digits = countDigits(i);
        square = i * i;
        tenth_power = quickPow(10, digits);
        if ((square - i) % tenth_power == 0) {
            printf("%d", i);
            if (printed % 10 == 0) {
                printf("%s", "\n");
            } else {
                printf("%s", "\t");
            }
            printed++;
        }
    }
}