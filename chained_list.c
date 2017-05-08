#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node celula;

struct node {
  int num;
  struct node *prox;
};

// init list.
void init(celula *list) {
  list->prox = NULL;
}

// Verify if the lists if empty.
int is_empty(celula *list) {
  return list->prox == NULL ? 1 : 0;
}

// Select list's size.
int list_size() {
  int size;

  printf("Type list's size: ");
  scanf("%d\n", &size);

  return size;
}

// Add a element at the beginning of the list.
void add_element_beginning(celula *list) {
  celula *new_element = malloc(sizeof(celula));
  new_element->prox = NULL;

  printf("Type a integer number: ");
  scanf("%d", &new_element->num);

  new_element->prox = list->prox;
  list->prox = new_element;

}

// Add a element at the end of the list.
void add_element_end(celula *list) {
  celula *new_element = malloc(sizeof(celula));
  new_element->prox = NULL;

  int size = list_size();

  for (int i = 0; i < size; i++) {
    printf("Type a integer number: ");
    scanf("%d", &new_element->num);

    if (is_empty(list)) {
      list->prox = new_element;
    } else {
      celula *aux = list;

      while (aux->prox != NULL) aux = aux->prox;

      aux->prox = new_element;
    }
  }
}

// Print list's elements.
void print_list(celula *list) {
  celula *aux;

  aux = list->prox;

  while (aux != NULL) {
    printf("%d, ", aux->num);
    aux = aux->prox;
  }
}

void menu(celula *list) {
  int option;

  do {
    printf("==== MENU ====\n");
    printf("Add Element To List.........: 1\n");
    printf("Verify List.................: 2\n");
    printf("Delete List.................: 3\n");
    printf("Print List..................: 4\n");
    printf("Finish......................: 0\n");
    printf("Select>> ");
    scanf("%d", &option);

    switch (option) {
      case 1:
        add_element_end(list);
        break;
      case 2:
        if(is_empty(list))
          printf("Empty List\n");
        else printf("List is not empty\n");
        break;
      case 3:
        //destroy_list(list);
        break;
      case 4:
        print_list(list);
        break;
      case 0:
        exit(1);
        break;
      default:
        printf("Invalid Option\n");
        break;
    }
  } while(option != 0);

}

int main(void) {
  // Allocate memory.
  celula *list = malloc(sizeof(celula));

  // Initiate list.
  init(list);

  menu(list);
}
