//
// Created by kopie on 01.02.2021.
//

#ifndef GEEKBRAINS_BRACKETS_H
#define GEEKBRAINS_BRACKETS_H

typedef struct List {
    char bracket;
    struct List *next;
} List;

void list_push(char value);

char list_pop();

int is_empty();

void brackets();

#endif //GEEKBRAINS_BRACKETS_H
