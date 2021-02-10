#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "rpn.h"


int is_operator(char symbol) {
    return symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol == '-';
}

int is_digit(char symbol) {
    return symbol >= '0' && symbol <= '9';
}

int precedence(char symbol) {
    if (symbol == '^') {
        return 3;
    } else if (symbol == '*' || symbol == '/') {
        return 2;
    } else if (symbol == '+' || symbol == '-') {
        return 1;
    } else {
        return 0;
    }
}

void push(Stack *stack, char item) {
    if (stack->top >= STACK_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    } else {
        stack->top = stack->top + 1;
        stack->items[stack->top] = item;
    }
}

char pop(Stack *stack) {
    char item;

    if (stack->top < 0) {
        printf("Stack Underflow\n");
        exit(1);
    } else {
        item = stack->items[stack->top];
        stack->top = stack->top - 1;
        return item;
    }
}

void InfixToPostfix(char infix_exp[], char postfix_exp[]) {
    int i, j;
    Stack operations = {
            (char *) (malloc(STACK_SIZE * sizeof(char))),
            0
    };
    char item, prev_item, prev_type = TYPE_BRACKET;
    char x;

    push(&operations, '(');
    strcat(infix_exp, ")");

    i = 0;
    j = 0;
    item = infix_exp[i];

    while (item != '\0') {
        if (is_digit(item)) {
            if (prev_type == TYPE_NUMBER && prev_item == ' ') {
                printf("Invalid infix Expression.\n");
            }
            if(j > 0 && prev_type != TYPE_NUMBER) {
                postfix_exp[j] = ' ';
                j++;
            }
            postfix_exp[j] = item;
            j++;
            prev_type = TYPE_NUMBER;
        } else if (item == '(') {
            push(&operations, item);
            prev_type = TYPE_BRACKET;
        } else if (is_operator(item) == 1) {
            if (prev_type != TYPE_NUMBER) {
                printf("Invalid infix Expression.\n");
                exit(1);
            }
            x = pop(&operations);
            while (is_operator(x) == 1 && precedence(x) >= precedence(item)) {
                postfix_exp[j] = ' ';
                j++;
                postfix_exp[j] = x;
                j++;
                x = pop(&operations);
            }
            push(&operations, x);

            push(&operations, item);
            prev_type = TYPE_OPERATION;
        } else if (item == ')') {
            if (prev_type != TYPE_NUMBER) {
                printf("Invalid infix Expression.\n");
                exit(1);
            }
            x = pop(&operations);
            while (x != '(') {
                postfix_exp[j] = ' ';
                j++;
                postfix_exp[j] = x;
                j++;
                x = pop(&operations);
            }
        } else if (item != ' ') {
            printf("Invalid infix Expression.\n");
            exit(1);
        }
        i++;
        prev_item = item;
        item = infix_exp[i];
    }
    if (operations.top > 0) {
        printf("Invalid infix Expression.\n");
        return;
    }


    postfix_exp[j] = '\0';

}

/* main function begins */
int rpn() {
    char infix[STACK_SIZE], postfix[STACK_SIZE];
    printf("Enter Infix expression : ");
    gets(infix);

    InfixToPostfix(infix, postfix);
    printf("Postfix Expression: ");
    puts(postfix);

    return 0;
}