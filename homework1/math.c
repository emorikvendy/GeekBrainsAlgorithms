#include <stdio.h>
#include "math.h"

int countDigits(int n) {
    int res = 0;
    while (n) {
        n /= 10;
        res++;
    }
    return res;
}

long quickPow(int a, int b) {
    long n = 1;
    while (b) {
        if (b % 2) {
            b--;
            n *= a;
        } else {
            a *= a;
            b /= 2;
        }
    }
    return n;
}
