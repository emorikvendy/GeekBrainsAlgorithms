#include <stdio.h>
#include <limits.h>
#include "homework1/automorphic_numbers.h"
#include "homework1/random.h"
#include "homework1/max_number.h"
#include "homework1/average.h"
#include "homework2/executor_calc.h"
#include "homework2/pow.h"
#include "homework3/sort.h"
#include "homework3/search.h"
#include "homework4/knight.h"

void main() {
    int size_y, size_x, move_number = 1;
    printf("Enter board vertical size: ");
    scanf("%d", &size_y);
    printf("Enter board horizontal size: ");
    scanf("%d", &size_x);
    printf("\r\n");
    int **board = init_board(size_y, size_x);
    print_board(board, size_y, size_x);
    printf("\r\n");
    if(move_knight(board, size_y, size_x, 0, 0, move_number)) {
        print_board(board, size_y, size_x);
        printf("\r\n");
    } else {
        printf("no routes available");
    }

    free_board(board, size_y);
//    int length = 10;
//    int *array = (int[]){9, 1, 7, 8, 2, 4, 3, 5, 6, 0};
//    print(array, length);
//    bubble(array, length);
//    print(array, length);
//    array = (int[]){9, 1, 7, 8, 2, 4, 3, 5, 6, 0};
//    print(array, length);
//    bubble2(array, length);
//    print(array, length);
//    array = (int[]){9, 1, 7, 8, 2, 4, 3, 5, 6, 0};
//    print(array, length);
//    shaker(array, length);
//    print(array, length);
//
//    printf("%d position is %d \n", 9, binary(array, length, 9));
//    printf("%d position is %d \n", 0, binary(array, length, 0));
//    printf("%d position is %d \n", 6, binary(array, length, 6));
//    printf("%d position is %d \n", 12, binary(array, length, 12));
//    printf("%d position is %d \n", -5, binary(array, length, -5));

//    int arr[] = {0, 1, 2, 3, 4, 5};
//    for (int i = 0; i < 6; ++i) {
//        for (int j = 0; j < 5; ++j) {
//            printf("powLoop: %d^%d = %lu \n", arr[i], j, powLoop(arr[i], j));
//            printf("quickPowLoop: %d^%d = %lu \n", arr[i], j, quickPowLoop(arr[i], j));
//            printf("powRec: %d^%d = %lu \n", arr[i], j, powRec(arr[i], j));
//            printf("quickPowRec: %d^%d = %lu \n", arr[i], j, quickPowRec(arr[i], j));
//            printf("---------------------------\n");
//        }
//    }

    //executor_calc_recursive();
    //executor_calc_array();
    //average();
    //find_max();
    //automorphic_numbers();
    //builtin_random();
    //my_random();
}
