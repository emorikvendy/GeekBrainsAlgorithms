/*
 * 3. Исполнитель Калькулятор преобразует целое число, записанное на экране. У исполнителя две команды, каждой команде присвоен номер:
 *  * Прибавь 1
 *  * Умножь на 2
 * Первая команда увеличивает число на экране на 1, вторая увеличивает это число в 2 раза. Сколько существует программ, которые число 3 преобразуют в число 20?
 * а) с использованием массива;
 * б) с использованием рекурсии.
 */

#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>

#include "executor_calc.h"

void executor_calc_recursive() {
    int first, second, count = 0, current_length = 1;
    Sequence *sequences = (Sequence *) malloc(current_length * sizeof(Sequence));
    Sequence sequence;
    printf("Enter first number: ");
    scanf("%d", &first);
    printf("Enter second number: ");
    scanf("%d", &second);
    if (first >= second) {
        printf("there are no paths");
        return;
    }
    sequence.len = 0;

    sequences = calc_step(sequences, &sequence, &count, &current_length, first, second);

    printf("found %d sequences\n", count);
    print_sequences(sequences, count);
    free(sequences);
}

Sequence *calc_step(struct Sequence sequences[], Sequence *current, int *count, int *current_length, int from, int to) {
    if (from + 1 < to) {
        Sequence new = *current;
        new.moves[new.len] = 1;
        new.len += 1;
        sequences = calc_step(sequences, &new, count, current_length, from + 1, to);
    } else if (from + 1 == to) {
        Sequence new = *current;
        new.moves[new.len] = 1;
        new.len += 1;
        if (*count > *current_length - 1) {
            *current_length *= 2;
            sequences = (Sequence *) realloc(sequences, *current_length * sizeof(Sequence));
        }
        sequences[*count] = new;
        *count += 1;
    }
    if (from * 2 < to) {
        Sequence new = *current;
        new.moves[new.len] = 0;
        new.len += 1;
        sequences = calc_step(sequences, &new, count, current_length, from * 2, to);
    } else if (from * 2 == to) {
        Sequence new = *current;
        new.moves[new.len] = 0;
        new.len += 1;
        if (*count > *current_length - 1) {
            *current_length *= 2;
            sequences = (Sequence *) realloc(sequences, *current_length * sizeof(Sequence));
        }
        sequences[*count] = new;
        *count += 1;
    }
    return sequences;
}


void executor_calc_array() {
    int first, second, len = sizeof(unsigned long long) * CHAR_BIT, count = 0, tmp, current_length = 1, exists = 0;
    unsigned long long max = 1, i;
    Sequence *sequences = (Sequence *) malloc(sizeof(Sequence));
    Sequence sequence;
    printf("Enter first number: ");
    scanf("%d", &first);
    printf("Enter second number: ");
    scanf("%d", &second);
    if (first >= second) {
        printf("there are no paths");
        return;
    }
    if (second - first > len) {
        printf("too much difference in numbers");
        return;
    }
    max = max << (second - first);
    for (i = 1; i <= max; i++) {
        sequence.len = 0;
        tmp = first;
        for (int j = 0; j < len; j++) {
            if (check_bit(i, j)) {
                tmp += 1;
                sequence.moves[j] = 1;
            } else {
                tmp <<= 1;
                sequence.moves[j] = 0;
            }
            sequence.len++;
            if (tmp == second) {
                exists = 0;
                for (int k = 0; k < count; k++) {
                    if (sequences_are_equal(sequence, sequences[k])) {
                        exists = 1;
                        break;
                    }
                }
                if (!exists) {
                    if (count > current_length - 1) {
                        current_length *= 2;
                        sequences = (Sequence *) realloc(sequences, current_length * sizeof(Sequence));
                    }
                    sequences[count] = sequence;
                    count++;
                }
                break;
            } else if (tmp > second) {
                break;
            }
        }
    }

    printf("found %d sequences\n", count);
    print_sequences(sequences, count);
    free(sequences);
}

int check_bit(unsigned long long value, int position) {
    int result;
    if ((value & (1 << position)) == 0) {
        result = 0;
    } else {
        result = 1;
    }
    return result;
}

void print_sequences(Sequence *sequences, int count) {
    for (int i = 0; i < count; i++) {
        print_sequence(sequences[i]);
    }
}

void print_sequence(Sequence sequence) {
    for (int i = 0; i < sequence.len; i++) {
        if (sequence.moves[i] == 1) {
            printf("+1 ");
        } else {
            printf("*2 ");
        }
    }
    printf("\n");
}

int sequences_are_equal(Sequence first, Sequence second) {
    return first.len == second.len && strcmp(first.moves, second.moves) == 0;
}