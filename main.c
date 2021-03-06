#include <stdio.h>
#include <stdlib.h>
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
#include "homework5/rpn.h"
#include "homework5/brackets.h"
#include "homework6/hash.h"
#include "homework6/btree.h"
#include "homework7/graph.h"

void main() {
//    struct Node *node;
//    char *filename = (char *) malloc(255 * sizeof(char));
//    int print_type;
//    printf("Enter path to data file\n");
//    scanf("%s", filename);
//    node = fromFile(filename);
//    printf("Enter the print type of the tree\n%d - left root right\n%d - root left right\n%d - right root left\n%d - brackets\n",
//           LEFT_ROOT_RIGHT, ROOT_LEFT_RIGHT, RIGHT_ROOT_LEFT, BRACKETS);
//    scanf("%d", &print_type);
//    printTree(node, print_type);
//    printf("\n");
//    free(filename);

//    char *out = from_stdin();
//    for (int i = 0; i < RESULT_SIZE; i++) {
//        printf("%d ", out[i]);
//    }
//    printf("\n");

//    brackets();
//    rpn();

//    start();

    int length = 10;
    int *array = (int[]) {9, 1, 7, 8, 2, 4, 3, 5, 6, 0};
    printf("bubble:\n");
    print(array, length);
    bubble(array, length);
    print(array, length);
    array = (int[]) {9, 1, 7, 8, 2, 4, 3, 5, 6, 0};
    printf("bubble2:\n");
    print(array, length);
    bubble2(array, length);
    print(array, length);
    array = (int[]) {9, 1, 7, 8, 2, 4, 3, 5, 6, 0};
    printf("shaker:\n");
    print(array, length);
    shaker(array, length);
    print(array, length);
    array = (int[]) {9, 1, 7, 8, 2, 4, 3, 5, 6, 0};
    printf("heapSort:\n");
    print(array, length);
    heapSort(array, length);
    print(array, length);
    array = (int[]) {9, 1, 7, 8, 2, 4, 3, 5, 6, 0};
    printf("quickSort:\n");
    print(array, length);
    quickSort(array, 0, length - 1);
    print(array, length);
    array = (int[]) {9, 1, 7, 8, 2, 4, 3, 5, 6, 0};
    printf("insertionSort:\n");
    print(array, length);
    insertionSort(array, length);
    print(array, length);
    array = (int[]) {9, 1, 7, 8, 2, 4, 3, 5, 6, 0};
    printf("insertionSort2:\n");
    print(array, length);
    insertionSort2(array, length);
    print(array, length);
    sortsBenchmark();
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
