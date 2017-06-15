#ifndef MATRIX_H
#define MATRIX_H

#include "list.h"

typedef struct {
  int line_n, col_n;
  LIST *line;
  LIST *col;
} MATRIX;

void create_matrix(MATRIX*);
void read_matrix(MATRIX*);
void print_matrix(MATRIX*);
void sum_matrix(MATRIX*, MATRIX*, MATRIX*);
void multiply_matrix(MATRIX*, MATRIX*, MATRIX*);
void erase_matrix(MATRIX*);
int is_empty(MATRIX*);
void insert_in_matrix(MATRIX*, int, int, double);

#endif
