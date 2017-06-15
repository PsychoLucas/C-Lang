#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include"list.c"

// Função p/ criar a matrix com os valores default (0, NULL).
void create_matrix(MATRIX *matrix) {
  matrix->col = NULL;
  matrix->line = matrix->col;

  matrix->col_n = 0;
  matrix->line_n = matrix->col_n;
}

// Função p/ inicilizar a matriz a, alocando os vetores de listas a partir da
// quantidade de linhas e colunas indicadas nos paramêtros.
void init_matrix(MATRIX *matrix, int lines, int cols) {
  matrix->line_n = lines;
  matrix->col_n = cols;

  matrix->line = (LIST*) malloc(matrix->line_n * sizeof(LIST));
  for (int i = 0; i < matrix->line_n; i++)
    create(&matrix->line[i]);

  matrix->col = (LIST*) malloc(matrix->col_n * sizeof(LIST));
  for (int i = 0; i < matrix->col_n; i++)
    create(&matrix->col[i]);
}

// Função p/ inserir valores na matriz.
void insert_in_matrix(MATRIX *matrix, int line, int col, double value) {
  PTR cel;

  cel = (CEL*) malloc(sizeof(CEL));

  cel->item.line = line;
  cel->item.col = col;
  cel->item.value = value;

  cel->right = NULL;
  cel->below = NULL;

  insert_in_line(&matrix->line[line - 1], cel);
  insert_in_col(&matrix->col[col - 1], cel);
}

// Função p/ ler os dados da matriz.
void read_matrix(MATRIX *matrix) {
  int line, line_n, col, col_n;
  double value;

  printf("Número de linhas:\n");
  scanf("\n%d", &line_n);

  printf("Número de Colunas:\n");
  scanf("\n%d", &col_n);

  if (line_n == col_n && (line_n != 0 && col_n != 0))
    init_matrix(matrix, line_n, col_n);

  while(1) {
    printf("Linha:\n");
    scanf("\n%d", &line);
    printf("Coluna:\n");
    scanf("\n%d", &col);
    printf("Valor:\n");
    scanf("\n%lf", &value);

    if (line < 1) break;

    insert_in_matrix(matrix, line, col, value);
  }
}

// Função p/ imprimir a matriz recebida através do paramêtro em um formato
// conveniente.
void print_matrix(MATRIX *matrix) {
  printf("Matrix:\n");

  for (int i = 0; i < matrix->line_n; i++)
    print_line(&matrix->line[i], matrix->col_n);

  printf("---------\n");
}

// Função que recebe duas matrizes A e B e faz a soma das duas e retorna uma
// matriz C
void sum_matrix(MATRIX *a, MATRIX *b, MATRIX *c) {
  PTR ptr_a, ptr_b;
  int sum;

  if (a->line_n != b->line_n || a->col_n != b->col_n) {
    printf("ERRO! Matrizes incorretas!\n");
    return;
  }

  init_matrix(c, a->line_n, a->col_n);

  for (int i = 0; i < a->line_n; i++) {
    ptr_a = a->line[i].first->right;
    ptr_b = b->line[i].first->right;

    while (ptr_a && ptr_b) {
      if (ptr_a->item.col < ptr_b->item.col) {
        insert_in_matrix(c, i + 1, ptr_a->item.col, ptr_a->item.value);
        ptr_a = ptr_a->right;
      } else if (ptr_a->item.col > ptr_b->item.col) {
        insert_in_matrix(c, i + 1, ptr_b->item.col, ptr_b->item.value);
        ptr_b = ptr_b->right;
      } else {
        sum = ptr_a->item.value + ptr_b->item.value;
        if (sum != 0)
          insert_in_matrix(c, i + 1, ptr_a->item.col, sum);

        ptr_a = ptr_a->right;
        ptr_b = ptr_b->right;
      }
    }

    while (ptr_a) {
      insert_in_matrix(c, i + 1, ptr_a->item.col, ptr_a->item.value);
      ptr_a = ptr_a->right;
    }

    while (ptr_b) {
      insert_in_matrix(c, i + 1, ptr_b->item.col, ptr_b->item.value);
      ptr_b = ptr_b->right;
    }
  }
}

// Função para verificar se a matriz está vazia.
int is_empty(MATRIX *matrix) {
  return matrix->line_n == 0;
}

// Função que recebe duas matrizes A e B e faz a multiplicação das duas e retorna
// uma matriz C
void multiply_matrix(MATRIX *a, MATRIX *b, MATRIX *c) {
  PTR ptr_a, ptr_b;
  double product;

  if (is_empty(a) || is_empty(b) || is_empty(c)) {
    printf("ERRO! Matrizes incorretas!\n");
    return;
  }

  if (a->line_n != b->line_n || a->col_n != b->col_n) {
    printf("ERRO! Matrizes incorretas!\n");
    return;
  }

  init_matrix(c, a->line_n, a->col_n);

  for (int i = 0; i < a->line_n; i++) {
    for (int j = 0; j < b->col_n; j++) {
      ptr_a = a->line[i].first->right;
      ptr_b = b->col[j].first->below;
      product = 0;

      while (ptr_a && ptr_b) {
        if (ptr_a->item.col < ptr_b->item.line)
          ptr_a = ptr_a->right;
        else if (ptr_a->item.col > ptr_b->item.line)
          ptr_b = ptr_b->below;
        else {
          product += ptr_a->item.value * ptr_b->item.value;

          ptr_a = ptr_a->right;
          ptr_b = ptr_b->below;
        }
      }

      insert_in_matrix(c, i + 1, j + 1, product);
    }
  }
}

// Função para apagar a matriz.
void erase_matrix(MATRIX *matrix) {
  PTR p;

  for (int i = 0; i < matrix->line_n; i++) {
    while(matrix->line[i].first != NULL) {
      p = matrix->line[i].first;
      matrix->line[i].first = p->right;
      free(p);
    }
  }

  for (int i = 0; i < matrix->col_n; i++) {
    free(matrix->col[i].first);
  }

  free(matrix->line);
  free(matrix->col);
}
