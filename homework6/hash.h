//
// Created by kopie on 02.02.2021.
//

#ifndef GEEKBRAINS_HASH_H
#define GEEKBRAINS_HASH_H

#define BLOCK_SIZE 30
#define RESULT_SIZE 10

#define INITIAL_VALUE "ABCDEFGHIJ"

void compression(char *block, char *base);
char *from_stdin();

#endif //GEEKBRAINS_HASH_H
