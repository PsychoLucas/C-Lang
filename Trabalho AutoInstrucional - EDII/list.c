#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// Função p/ criar a lista.
void create (LIST *list) {
  list->first = (PTR) malloc (sizeof (CEL));
  list->last = list->first;
  list->first->right = NULL;
  list->first->below = NULL;
}

// Funções p/ inserção de linha.
int insert_in_line (LIST *list, PTR cel) {
  list->last->right = cel;
  list->last = list->last->right;
  list->last->right = NULL;
  return 0;
}

int get_last_position_line (LIST *list, PTR cel) {
  PTR p;

  p = list->first;
  while (p->right != NULL) {
    if (cel->item.col < p->right->item.col) {
      cel->right = p->right;
      p->right = cel;
      return 0;
    }
    p = p->right;
  }

  return insert_in_line(list, cel);
}

// Funções p/ inserção na coluna.
int insert_in_col (LIST *list, PTR cel) {
  list->last->below = cel;
  list->last = list->last->below;
  list->last->right = NULL;
  return 0;
}

int get_last_position_col (LIST *list, PTR col) {
  PTR p;

  p = list->first;
  while (p->below != NULL) {
    if (col->item.line < p->below->item.line) {
      col->below = p->below;
      p->below = col;
      return 0;
    }
    p = p->below;
  }

  return insert_in_col(list, col);
}

// Função p/ imprimir a linha.
void print_line(LIST *list, int last_col) {
  PTR aux;
  int next_col = 1;

  aux = list->first->right;
  while (aux != NULL) {
    for (int i = 0; i < aux->item.col; i++)
      printf("%.1lf ", 0.0);
    printf("%.1lf ", aux->item.value);
    next_col = aux->item.col + 1;
    aux = aux->right;
  }

  for (int i = next_col; i < last_col; i++)
    printf("%.1lf ", 0.0);

  printf("\n");
}
