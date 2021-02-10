#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "graph.h"


char *readLine(FILE *file) {

    if (file == NULL) {
        printf("Error: file pointer is null.");
        exit(1);
    }

    int maximumLineLength = 128;
    char *lineBuffer = (char *) malloc(sizeof(char) * maximumLineLength);

    if (lineBuffer == NULL) {
        printf("Error allocating memory for line buffer.");
        exit(1);
    }

    char ch = getc(file);
    int count = 0;

    while ((ch != '\n') && (ch != EOF)) {
        if (count == maximumLineLength) {
            maximumLineLength += 128;
            lineBuffer = realloc(lineBuffer, maximumLineLength);
            if (lineBuffer == NULL) {
                printf("Error reallocating space for line buffer.");
                exit(1);
            }
        }
        lineBuffer[count] = ch;
        count++;

        ch = getc(file);
    }

    realloc(lineBuffer, count + 1);
    lineBuffer[count] = '\0';
    return lineBuffer;
}


int *stringToRow(const char *string, int *length) {
    int count = 0, i = 0, *row, j = 0, k;
    char number[12];
    while (string[i] != '\0') {
        if (string[i] == '\t' || string[i] == ' ') {
            count++;
        }
        i++;
    }
    row = (int *) malloc((count + 1) * sizeof(int));

    for (i = 0; i <= count; i++) {
        k = 0;
        while (string[j] != '\t' && string[j] != ' ' && string[j] != '\0') {
            number[k] = string[j];
            k++;
            j++;
        }
        number[k] = '\0';
        row[i] = atoi(number);
        j++;
    }
    *length = count + 1;
    return row;
}

int **readMatrix(char *filename, int *size) {
    FILE *file = fopen(filename, "r+");
    int *row;
    int first_row_size, i = 0, current_row_size;
    char *string;
    if (!file) {
        printf("Error: can not open file %s", filename);
        exit(1);
    }
    string = readLine(file);
    row = stringToRow(string, &first_row_size);
    int **matrix = (int **) malloc(first_row_size * sizeof(int *));
    matrix[i] = row;
    *size = first_row_size;
    for (i = 1; i < first_row_size; i++) {
        string = readLine(file);
        row = stringToRow(string, &current_row_size);
        if (current_row_size != first_row_size) {
            printf("Error: matrix must be square");
            exit(1);
        }
        matrix[i] = row;
    }
    return matrix;
}

void printMatrix(int **matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%*d", 5, matrix[i][j]);
        }
        printf("\n");
    }
}

void freeMatrix(int **matrix, int size) {
    for (int i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void widthTraversal(int **matrix, int size, int start) {
    if (start < 0 || start >= size) {
        printf("Error: starting vertex must belong to graph\n");
        exit(1);
    }
    int *vertexes = (int *) (malloc(size * sizeof(int))),
            updated = 1;
    for (int i = 0; i < size; ++i) {
        vertexes[i] = 0;
    }
    vertexes[start] = 1;
    while (updated) {
        updated = 0;
        for (int i = 0; i < size; ++i) {
            if (vertexes[i] != 1) {
                continue;
            }
            for (int j = 0; j < size; ++j) {
                if (matrix[i][j] == 0 || vertexes[j] != 0) {
                    continue;
                }
                vertexes[j] = 1;
                printf("From %d to %d\n", i, j);
            }
            vertexes[i] = 2;
            updated = 1;
        }
    }
    for (int i = 0; i < size; ++i) {
        if (vertexes[i] == 0) {
            printf("route from node %d to node %d does not exist\n", start, i);
        }
    }
    free(vertexes);
}

void depthTraversal(int **matrix, int size, int start) {
    if (start < 0 || start >= size) {
        printf("Error: starting vertex must belong to graph\n");
        exit(1);
    }
    int *route = (int *) (malloc(size * sizeof(int))),
            *visited_vertexes = (int *) (malloc(size * sizeof(int))),
            current = 0, visited_count = 1, updated;
    for (int i = 0; i < size; ++i) {
        visited_vertexes[i] = 0;
    }
    visited_vertexes[start] = 1;
    route[current] = start;
    while (current >= 0 && visited_count < size) {
        updated = 0;
        for (int i = 0; i < size; ++i) {
            if (matrix[route[current]][i] != 0 && !visited_vertexes[i]) {
                printf("From %d to %d\n", route[current], i);
                current++;
                visited_count++;
                visited_vertexes[i] = 1;
                route[current] = i;
                updated = 1;
                break;
            }
        }
        if (!updated) {
            if (current) {
                printf("From %d to %d\n", route[current], route[current - 1]);
            }
            current--;
        }
    }
    for (int i = 0; i < size; ++i) {
        if (visited_vertexes[i] == 0) {
            printf("route from node %d to node %d does not exist\n", start, i);
        }
    }
    free(route);
    free(visited_vertexes);
}

void dijkstra(int **matrix, int size, int start) {
    if (start < 0 || start >= size) {
        printf("Error: starting vertex must belong to graph\n");
        exit(1);
    }
    int *route_prices = (int *) (malloc(size * sizeof(int))),
            *active_vertexes = (int *) (malloc(size * sizeof(int))),
            updated = 1;

    for (int i = 0; i < size; ++i) {
        route_prices[i] = -1;
        active_vertexes[i] = 0;
    }
    route_prices[start] = 0;
    active_vertexes[start] = 1;

    while (updated) {
        updated = 0;
        for (int i = 0; i < size; ++i) {
            if (!active_vertexes[i]) {
                continue;
            }
            for (int j = 0; j < size; ++j) {
                if (!matrix[i][j]) {
                    continue;
                }
                if (route_prices[j] < 0 || route_prices[j] > route_prices[i] + matrix[i][j]) {
                    route_prices[j] = route_prices[i] + matrix[i][j];
                    active_vertexes[j] = 1;
                    updated = 1;
                }
            }
            active_vertexes[i] = 0;
        }
    }
    free(active_vertexes);

    for (int i = 0; i < size; ++i) {
        if (i == start) {
            continue;
        }

        if (route_prices[i] < 0) {
            printf("route from node %d to node %d does not exist\n", start, i);
        } else {
            printf("route from node %d to node %d costs %d\n", start, i, route_prices[i]);
            printDijkstraRoute(matrix, size, i, route_prices);
        }

    }
    free(route_prices);
}

void printDijkstraRoute(int **matrix, int size, int to, const int *route_prices) {
    int *route = (int *) (malloc(size * sizeof(int))), length = 1;
    route[0] = to;
    while (route_prices[to] > 0) {
        for (int i = 0; i < size; ++i) {
            if (i == to) {
                continue;
            }
            if (route_prices[to] - route_prices[i] == matrix[to][i]) {
                to = i;
                route[length] = i;
                length++;
                break;
            }
        }
    }
    for (int i = length - 1; i >= 0; --i) {
        printf("%d ", route[i]);
    }
    printf("\n");
    free(route);
}