#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "brackets.h"

List *top;

void list_push(char value) {
    List *tmp;
    tmp = malloc(sizeof(List));
    tmp->bracket = value;
    tmp->next = top;
    top = tmp;
}

char list_pop() {
    List *tmp;
    char n;
    tmp = top;
    n = tmp->bracket;
    top = top->next;
    free(tmp);
    return n;
}

int is_empty() {
    return top == NULL;
}

void brackets() {
    char expression[255], symbol;
    int i = 0;
    top = NULL;
    printf("Enter expression : ");
    gets(expression);
    symbol = expression[i];
    while (symbol != '\0'){
        if(symbol == '(' || symbol == '{' || symbol == '['){
            list_push(symbol);
        } else {
            if((symbol == ')' && list_pop() != '(') || (symbol == ']' && list_pop() != '[') || (symbol == '}' && list_pop() != '{')){
                printf("Expresion is invalid\n");
                exit(1);
            }
        }
        i++;
        symbol = expression[i];
    }
    if(!is_empty()){
        printf("Expresion is invalid\n");
    } else {
        printf("Expresion is valid\n");
    }
}