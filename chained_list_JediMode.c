#include <stdio.h>
#include <stdlib.h>

// Define o ponteiro para a celula.
typedef struct CEL_TAG *PTR;

// Define o item.
typedef struct {
  int id;
} ITEM;

// Define a celula.
typedef struct CEL_TAG {
  ITEM item;
  PTR next;
} CEL;

// Define a lista.
typedef struct {
  PTR first, last;
} LIST;

void initList(LIST *list) {
  PTR new = malloc(sizeof(CEL));

  new->next = NULL; // Lista na próxima posição recebe null;
  list->first = new; // Lista na primeira posição recebe o novo elemento;
  list->last = new; // Lista na última posição recebe o novo elemento;
}

int is_empty(celula *list) {
  return list->prox == NULL ? 1 : 0;
}

void insertElementsAtEnd(LIST *list) {
  PTR new = malloc(sizeof(CEL));

  new->next = NULL;

  for (int i = 0; i < 5; i++) {
    printf("Type number: \n");
    scanf("%d\n", &new->id);

    if (is_empty(list))
      list->last = new;
    else
      CEL *aux = list;

      while (aux->next != NULL) aux = aux->next;

      aux->s = new;
  }

}

int main(void) {
  LIST list;

  initList(&list);

}
