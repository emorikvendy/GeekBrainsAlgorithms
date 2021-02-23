cmake_minimum_required(VERSION 3.17)
project(GeekBrains C)

set(CMAKE_C_STANDARD 99)

add_executable(GeekBrains main.c homework1/automorphic_numbers.c homework1/math.c homework1/random.c homework1/max_number.c homework1/average.c homework2/executor_calc.c homework2/pow.c homework3/sort.c homework3/search.c homework4/knight.c homework5/rpn.c homework5/rpn.h homework5/brackets.h homework5/brackets.c homework6/hash.c homework6/hash.h homework6/btree.c homework6/btree.h homework7/graph.h homework7/graph.c)
