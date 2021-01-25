/*
 * 2. Реализовать функцию возведения числа a в степень b:
 * a. без рекурсии;
 * b. рекурсивно;
 * c. *рекурсивно, используя свойство четности степени.
 */
#include "pow.h"

long powLoop(int a, int b) {
    long res = 1;
    for(int i = 0; i < b; i++){
        res *= a;
    }
    return res;
}

long quickPowLoop(int a, int b) {
    long res = 1;
    while (b != 0){
        if(b % 2){
            res *= a;
            b -= 1;
        } else {
            a *= a;
            b /= 2;
        }
    }
    return res;
}

long powRec(int a, int b) {
    return b ? a * powRec(a, b -1) : 1;
}

long quickPowRec(int a, int b) {
    return b ? (b % 2 ? a * quickPowRec(a , b -1) : quickPowRec(a*a, b/2)) : 1;
}