#include <stdio.h>
#include <stdlib.h>
#include "knight.h"

/**
 * Инициализируем доску, во все клетки прописываем кол-во доступных ходов
 * @param int size_y
 * @param int size_x
 * @return
 */
int **init_board(int size_y, int size_x) {
    int **board = (int **) malloc(size_y * sizeof(int *));
    for (int i = 0; i < size_y; i++) {
        board[i] = (int *) malloc(size_x * sizeof(int));
    }
    for (int i = 0; i < size_y; i++) {
        for (int j = 0; j < size_x; j++) {
            board[i][j] = count_moves(size_y, size_x, i, j);
        }
    }
    return board;
}

/**
 * Очистка памяти выделенной под доску
 * @param int[][] board
 * @param int size_y
 */
void free_board(int **board, int size_y) {
    for (int i = 0; i < size_y; i++) {
        free(board[i]);
    }
    free(board);
}

/**
 * Подсчет доступного кол-ва ходов для клетки с координатами (x, y) в самом начале
 * @param int size_y
 * @param int size_x
 * @param int y
 * @param int x
 * @return int
 */
int count_moves(int size_y, int size_x, int y, int x) {
    int count = 0;
    for (int i = -2; i < 3; i++) {
        if (i == 0) {
            continue;
        }
        for (int j = -2; j < 3; j++) {
            if (j == 0 || abs(i) + abs(j) != 3) {
                continue;
            }
            if (y + i >= 0 && y + i < size_y && x + j >= 0 && x + j < size_x) {
                count++;
            }
        }
    }
    return count;
}

/**
 * Распечатать текущее состояние доски
 * @param board
 * @param int size_y
 * @param int size_x
 */
void print_board(int **board, int size_y, int size_x) {
    for (int i = 0; i < size_y; i++) {
        for (int j = 0; j < size_x; j++) {
            printf("%*d", 5, board[i][j]);
        }
        printf("\n");
    }
}

void start() {
    int size_y, size_x, i;
    printf("Enter board vertical size: ");
    scanf("%d", &size_y);
    printf("Enter board horizontal size: ");
    scanf("%d", &size_x);
    printf("\r\n");
    int **board = init_board(size_y, size_x);

    for (i = 0; i < size_y; ++i) {
        for (int j = 0; j < size_x; ++i) {
            if (move_knight(board, size_y, size_x, i, j, 1)) {
                i = size_y;
                break;
            }
        }
    }
    if (i == size_y + 1) {
        print_board(board, size_y, size_x);
        printf("\r\n");
    } else {
        printf("no routes available\r\n");
    }
    free_board(board, size_y);
}

/**
 * Рекурсивный поиск маршрута, используем правило Варнсдорфа
 * @param int[][] board
 * @param int size_y
 * @param int size_x
 * @param int y
 * @param int x
 * @param int move_number
 * @return
 */
int move_knight(int **board, int size_y, int size_x, int y, int x, int move_number) {
    int moves_count = board[y][x];
    make_move(board, size_y, size_x, y, x);
    /**
     * если сделали необходимое кол-во ходов, то выходим из рекурсии
     */
    if (move_number == size_y * size_x) {
        //printf("step number %5d:\tx = %5d y %5d\r\n", move_number, x, y);
        board[y][x] = move_number;
        return 1;
    }
    /**
     * если нет доступных ходов из текущей клетки, а необходимое кол-во ходов еще не сделано, откатываемся назад
     */
    if (moves_count == 0) {
        rollback_move(board, size_y, size_x, y, x);
        return 0;
    }
    Move *moves = (Move *) (malloc(moves_count * sizeof(Move)));
    get_available_moves(board, size_y, size_x, y, x, moves);
    sort_moves(moves, 0, moves_count - 1);
    for (int i = 0; i < moves_count; i++) {
        if (move_knight(board, size_y, size_x, moves[i].y, moves[i].x, move_number + 1)) {
            //printf("step number %5d:\tx = %5d y %5d\r\n", move_number, x, y);
            board[y][x] = move_number;
            free(moves);
            return 1;
        }
    }
    free(moves);
    rollback_move(board, size_y, size_x, y, x);
    return 0;
}

/**
 * Ход на клетку с координатами (x, y),
 * чтобы обозначить ее занятость меняем ее вес на отрицательный
 * у всех соседей уменьшаем кол-во доступных ходов на 1
 * @param int[][] board
 * @param int size_y
 * @param int size_x
 * @param int y
 * @param int x
 */
void make_move(int **board, int size_y, int size_x, int y, int x) {
    for (int i = -2; i < 3; i++) {
        if (i == 0) {
            continue;
        }
        for (int j = -2; j < 3; j++) {
            if (j == 0 || abs(i) + abs(j) != 3) {
                continue;
            }
            if (y + i >= 0 && y + i < size_y && x + j >= 0 && x + j < size_x && board[y + i][x + j] > 0) {
                board[y + i][x + j]--;
            }
        }
    }
    board[y][x] = -board[y][x];
}

/**
 * Отмена хода на клетку с координатами (x, y), всем соседям добавляем по 1 доступному ходу
 * @param int[][] board
 * @param int size_y
 * @param int size_x
 * @param int y
 * @param int x
 */
void rollback_move(int **board, int size_y, int size_x, int y, int x) {
    for (int i = -2; i < 3; i++) {
        if (i == 0) {
            continue;
        }
        for (int j = -2; j < 3; j++) {
            if (j == 0 || abs(i) + abs(j) != 3) {
                continue;
            }
            if (y + i >= 0 && y + i < size_y && x + j >= 0 && x + j < size_x && board[y + i][x + j] > 0) {
                board[y + i][x + j]++;
            }
        }
    }
    board[y][x] = -board[y][x];
}

/**
 * Получаем все доступные ходы в массив
 * @param int** board
 * @param int size_y
 * @param int size_x
 * @param int y
 * @param int x
 * @param Move[] moves
 */
void get_available_moves(int **board, int size_y, int size_x, int y, int x, Move *moves) {
    int count = 0;

    for (int i = -2; i < 3; i++) {
        if (i == 0) {
            continue;
        }
        for (int j = -2; j < 3; j++) {
            if (j == 0 || abs(i) + abs(j) != 3) {
                continue;
            }
            if (y + i >= 0 && y + i < size_y && x + j >= 0 && x + j < size_x && board[y + i][x + j] >= 0) {
                Move move = {
                        x + j,
                        y + i,
                        board[y + i][x + j]
                };
                moves[count] = move;
                count++;
            }
        }
    }
}

/**
 * QuickSort для массива структур типа Move
 * @param Move[] moves
 * @param int first
 * @param int last
 */
void sort_moves(Move *moves, int first, int last) {
    if (first < last) {
        int left = first, right = last, middle = moves[(left + right) / 2].weight;
        do {
            while (moves[left].weight < middle) left++;
            while (moves[right].weight > middle) right--;
            if (left <= right) {
                Move tmp = moves[left];
                moves[left] = moves[right];
                moves[right] = tmp;
                left++;
                right--;
            }
        } while (left <= right);
        sort_moves(moves, first, right);
        sort_moves(moves, left, last);
    }
}
