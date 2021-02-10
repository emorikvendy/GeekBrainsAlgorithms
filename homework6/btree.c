#include <stdlib.h>
#include <stdio.h>
#include "btree.h"

unsigned char height(struct Node *node) {
    return node ? node->height : 0;
}

int balanceFactor(struct Node *node) {
    return height(node->right) - height(node->left);
}

void fixHeight(struct Node *node) {
    unsigned char height_left = height(node->left);
    unsigned char height_right = height(node->right);
    node->height = (height_left > height_right ? height_left : height_right) + 1;
}

struct Node *rotateRight(struct Node *node) {
    Node *left = node->left;
    node->left = left->right;
    left->right = node;
    fixHeight(node);
    fixHeight(left);
    return left;
}

struct Node *rotateLeft(struct Node *node) {
    Node *right = node->right;
    node->right = right->left;
    right->left = node;
    fixHeight(node);
    fixHeight(right);
    return right;
}

struct Node *balance(struct Node *node) {
    fixHeight(node);
    if (balanceFactor(node) == 2) {
        if (balanceFactor(node->right) < 0)
            node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    if (balanceFactor(node) == -2) {
        if (balanceFactor(node->left) > 0)
            node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    return node;
}

/**
 * вставка ключа key в дерево с корнем node
 * @param node
 * @param key
 * @return
 */
struct Node *insert(struct Node *node, int key) {
    if (!node) {
        node = (struct Node *) malloc(sizeof(struct Node));
        node->right = node->left = NULL;
        node->height = 1;
        node->key = key;
        return node;

    }
    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);
    return balance(node);
}

struct Node *findMin(struct Node *node) {
    return node->left ? findMin(node->left) : node;
}

struct Node *removeMin(struct Node *node) {
    if (node->left == NULL)
        return node->right;
    node->left = removeMin(node->left);
    return balance(node);
}

struct Node *removeByKey(Node *node, int k) {
    if (!node) return NULL;
    if (k < node->key) {
        node->left = removeByKey(node->left, k);
    } else if (k > node->key) {
        node->right = removeByKey(node->right, k);
    } else {
        Node *left = node->left;
        Node *right = node->right;
        free(node);
        if (!right) return left;
        struct Node *min = findMin(right);
        min->right = removeMin(right);
        min->left = left;
        return balance(min);
    }
    return balance(node);
}

struct Node *findByKey(Node *node, int k) {
    if (!node) return NULL;
    if (k < node->key) {
        return findByKey(node->left, k);
    } else if (k > node->key) {
        return findByKey(node->right, k);
    } else {
        return node;
    }
}

void printTree(Node *node, int type) {
    if (node) {
        switch (type) {
            case LEFT_ROOT_RIGHT:
                printTree(node->left, type);
                printf("%d ", node->key);
                printTree(node->right, type);
                break;
            case ROOT_LEFT_RIGHT:
                printf("%d ", node->key);
                printTree(node->left, type);
                printTree(node->right, type);
                break;
            case RIGHT_ROOT_LEFT:
                printTree(node->right, type);
                printf("%d ", node->key);
                printTree(node->left, type);
                break;
            case BRACKETS:
                printf("%d", node->key);
                if (node->left || node->right) {
                    printf("(");
                    if (node->left)
                        printTree(node->left, type);
                    else
                        printf("NULL");
                    printf(",");
                    if (node->right)
                        printTree(node->right, type);
                    else
                        printf("NULL");
                    printf(")");
                }
        }
    }
}

struct Node *fromFile(char *filename) {
    struct Node *node = NULL;
    FILE *file;
    int key;
    file = fopen(filename, "r+");
    if (!file) return node;
    while ((fscanf(file, "%d", &key) != EOF)) {
        node = insert(node, key);
    }
    fclose(file);
    return node;
}