#include <stdio.h>
#include <stdlib.h>
#include "matrix.c"

/*
 * Trabalho Auto Instrucional - Estrutura de Dados II
 * Participantes: Lucas Assunção, Nelson Sinis
 */

int main(int argc, char const *argv[]) {
  MATRIX matrix_a, matrix_b, matrix_c;

  printf("Primeiro Grupo de Matrizes:\n");
  create_matrix(&matrix_a);
  read_matrix(&matrix_a);
  print_matrix(&matrix_a);

  create_matrix(&matrix_b);
  read_matrix(&matrix_b);
  print_matrix(&matrix_b);

  printf("Soma das matrizes:\n");
  create_matrix(&matrix_c);
  sum_matrix(&matrix_a, &matrix_b, &matrix_c);
  print_matrix(&matrix_c);

  printf("Produto das matrizes:\n");
  erase_matrix(&matrix_c);
  multiply_matrix(&matrix_a, &matrix_b, &matrix_c);
  print_matrix(&matrix_c);

  erase_matrix(&matrix_a);
  erase_matrix(&matrix_b);
  erase_matrix(&matrix_c);

  printf("Segundo grupo de matrizes:\n");
  read_matrix(&matrix_a);
  print_matrix(&matrix_a);
  read_matrix(&matrix_b);
  print_matrix(&matrix_b);

  printf("Soma das matrizes:\n");
  create_matrix(&matrix_c);
  sum_matrix(&matrix_a, &matrix_b, &matrix_c);
  print_matrix(&matrix_c);

  printf("Produto das matrizes:\n");
  erase_matrix(&matrix_c);
  multiply_matrix(&matrix_a, &matrix_b, &matrix_c);
  print_matrix(&matrix_c);

  erase_matrix(&matrix_a);
  erase_matrix(&matrix_b);
  erase_matrix(&matrix_c);

  return 0;
}
