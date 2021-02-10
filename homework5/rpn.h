//
// Created by kopie on 31.01.2021.
//

#ifndef GEEKBRAINS_RPN_H
#define GEEKBRAINS_RPN_H

#define STACK_SIZE 1000

#define TYPE_NUMBER 1
#define TYPE_OPERATION 2
#define TYPE_BRACKET 3

typedef struct {
    char *items;
    int top;
} Stack;


int rpn();

void InfixToPostfix(char infix_exp[], char postfix_exp[]);

char pop(Stack *stack);

void push(Stack *stack, char item);

int precedence(char symbol);

int is_digit(char symbol);

int is_operator(char symbol);

#endif //GEEKBRAINS_RPN_H
