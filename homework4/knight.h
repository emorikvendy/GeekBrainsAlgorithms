#ifndef KNIGHT_H_INCLUDED
#define KNIGHT_H_INCLUDED

int count_moves(int size_y, int size_x, int y, int x);

int **init_board(int size_y, int size_x);

void free_board(int **board, int size_y);

void print_board(int **board, int size_y, int size_x);

void make_move(int **board, int size_y, int size_x, int y, int x);

void rollback_move(int **board, int size_y, int size_x, int y, int x);

typedef struct {
    int x;
    int y;
    int weight;
} Move;


void sort_moves(Move *moves, int first, int last);

void get_available_moves(int **board, int size_y, int size_x, int y, int x, Move *moves);

int move_knight(int **board, int size_y, int size_x, int y, int x, int move_number);

void start();

#endif