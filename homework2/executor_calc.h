#ifndef EXECUTOR_CALC_H_INCLUDED
#define EXECUTOR_CALC_H_INCLUDED

void executor_calc_recursive();

void executor_calc_array();

int check_bit(unsigned long long value, int position);

typedef struct Sequence {
    char moves[sizeof(unsigned long long) * CHAR_BIT];
    short len;
} Sequence;

int sequences_are_equal(Sequence first, Sequence second);

void print_sequences(Sequence *sequences, int count);

void print_sequence(Sequence sequence);

 Sequence* calc_step(Sequence sequences[], Sequence *current, int* count, int *current_length, int from, int to);

#endif