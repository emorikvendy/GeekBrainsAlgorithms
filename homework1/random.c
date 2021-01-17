/*
 * 13. * Написать функцию, генерирующую случайное число от 1 до 100.
 * с использованием стандартной функции rand()
 * без использования стандартной функции rand()
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "random.h"

void builtin_random() {
    int stime = get_stime();
    srand(stime);
    for (int i = 1; i < 101; i++) {
        printf("%d\t", rand() % 100);
        if(i%10 == 0) {
            printf("%s", "\n");
        }
    }
}

void my_random() {
    int stime = get_stime();
    int x = stime % 100, m = 100, a = (stime / 100) % 100, c = (stime / 10000) % 100;
    for (int i = 1; i < 101; i++) {
        x = (a * x + c) % 100;
        printf("%d\t",x);
        if(i%10 == 0) {
            printf("%s", "\n");
        }
    }
}

int get_stime(){
    long ltime;
    ltime = time(NULL);
    return (int) ltime / 2;
}