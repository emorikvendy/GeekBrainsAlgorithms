#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

void compression(char *block, char *base) {
    char tmp = 0;
    for (char j = 0; j < RESULT_SIZE; ++j) {
        for (char i = 0; i < BLOCK_SIZE; i++) {
            tmp ^= block[(i + j)% BLOCK_SIZE] ^ (block[(i + j + 1)% BLOCK_SIZE] <<2) ^
                    (block[(i + j + 2)% BLOCK_SIZE] <<4) ^ base[(i+j) % RESULT_SIZE];
            base[(i+j) % RESULT_SIZE] = tmp;
        }
    }
}


char *from_stdin() {
    char *block = (char *) malloc(BLOCK_SIZE * sizeof(char)), c, *out = (char *) malloc(RESULT_SIZE * sizeof(char));
    strcpy(out, INITIAL_VALUE);
    int i = 0;
    printf("Enter the string: ");
    while ((c = getc(stdin)) != '\n') {
        block[i] = c;
        i++;
        if (i == BLOCK_SIZE) {
            compression(block, out);
            i = 0;
        }
    }
    if (i != 0) {
        for (; i < BLOCK_SIZE; i++) {
            block[i] = 0;
        }
        compression(block, out);
    }
    return out;
}