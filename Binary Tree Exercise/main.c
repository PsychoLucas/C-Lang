#include <stdio.h>
#include "binary_tree.c"

int main(void) {

  FILE *file;
  TREE tree;
  ITEM item;
  int i;

  create_tree(&tree);
  file = fopen("file.txt", "r");
  while(fscanf(file, "%d", &i) != EOF) {
    item.key = i;
    if(insert_element(item, &tree) == -1)
      printf("ERROR! Failed to insert: %d\n", i);
  }

  printf("Pre-Order:\n");
  go_through_pre(tree);

  printf("Pos-Oder:\n");
  go_through_pos(tree);

  printf("Inside-Order:\n");
  go_through_in(tree);
}
