#include <stdio.h>
#include <limits.h>
#include "homework1/automorphic_numbers.h"
#include "homework1/random.h"
#include "homework1/max_number.h"
#include "homework1/average.h"
#include "homework2/executor_calc.h"
#include "homework2/pow.h"

void main() {
    int arr[] = {0, 1, 2, 3, 4, 5};
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 5; ++j) {
            printf("powLoop: %d^%d = %lu \n", arr[i], j, powLoop(arr[i], j));
            printf("quickPowLoop: %d^%d = %lu \n", arr[i], j, quickPowLoop(arr[i], j));
            printf("powRec: %d^%d = %lu \n", arr[i], j, powRec(arr[i], j));
            printf("quickPowRec: %d^%d = %lu \n", arr[i], j, quickPowRec(arr[i], j));
            printf("---------------------------\n");
        }
    }
//
//    printf("powLoop: %lu \n", powLoop(2, 13));
//    printf("%lu \n", quickPowLoop(2, 13));
//    printf("%lu \n", powRec(2, 13));
//    printf("%lu \n", quickPowRec(2, 13));

    //executor_calc_recursive();
    //executor_calc_array();
    //average();
    //find_max();
    //automorphic_numbers();
    //builtin_random();
    //my_random();
}
