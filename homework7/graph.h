//
// Created by kopie on 07.02.2021.
//

#ifndef GEEKBRAINS_GRAPH_H
#define GEEKBRAINS_GRAPH_H

char *readLine(FILE *file);

int *stringToRow(const char *string, int *length);

int **readMatrix(char *filename, int *size);

void printMatrix(int **matrix, int size);

void freeMatrix(int **matrix, int size);


void widthTraversal(int **matrix, int size, int start);

void depthTraversal(int **matrix, int size, int start);

void dijkstra(int **matrix, int size, int start);

void printDijkstraRoute(int **matrix, int size, int to, const int *route_prices);

#endif //GEEKBRAINS_GRAPH_H
