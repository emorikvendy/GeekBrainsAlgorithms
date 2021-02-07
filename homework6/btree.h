//
// Created by kopie on 06.02.2021.
//

#ifndef GEEKBRAINS_BTREE_H
#define GEEKBRAINS_BTREE_H

#define LEFT_ROOT_RIGHT 1
#define ROOT_LEFT_RIGHT 2
#define RIGHT_ROOT_LEFT 3
#define BRACKETS 4

typedef struct Node // структура для представления узлов дерева
{
    int key;
    unsigned char height;
    struct Node *left;
    struct Node *right;
} Node;

unsigned char height(struct Node *node);

int balanceFactor(struct Node *node);

void fixHeight(struct Node *node);

struct Node *rotateRight(struct Node *node);

struct Node *rotateLeft(struct Node *node);

struct Node *balance(struct Node *node);

struct Node *insert(struct Node *node, int key);

struct Node *findMin(struct Node *node);

struct Node *removeMin(struct Node *node);

struct Node *removeByKey(Node *node, int k);

void printTree(Node *node, int type);

struct Node *fromFile(char *filename);

#endif //GEEKBRAINS_BTREE_H
