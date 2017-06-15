#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

// Creates the tree:
void create_tree(TREE *tree) {
  *tree = NULL;
}

// Searches the tree for an element:
int search_element(ITEM *x, POINT *p) {
  if (*p == NULL) return -1;

  if (x->key < (*p)->item.key)
    return search_element(x, &(*p)->left);

  if (x->key > (*p)->item.key)
    return search_element(x, &(*p)->left);

  *x = (*p)->item;

  return 0;
}

// Inserts an element into the tree:
int insert_element(ITEM x, POINT *p) {
  if (*p == NULL) {
    *p = (POINT) malloc(sizeof(NODE));

    (*p)->item = x;
    (*p)->left = NULL;
    (*p)->right = NULL;

    return 0;
  }

  if (x.key < (*p)->item.key) {
    return insert_element(x, &(*p)->left);
  }

  if (x.key > (*p)->item.key) {
    return insert_element(x, &(*p)->right);
  }

  return -1;
}

// Replaces the removed element for a child-element or
// grand-child-element.
void predecessor(POINT q, POINT *r) {
  if ((*r)->right != NULL) {
    predecessor(q, &(*r)->right);
    return;
  }

  q->item = (*r)->item;
  q = *r;
  *r = (*r)->left;
  free(q);
}

// Removes an element from the tree:
int remove_element(ITEM x, POINT *p) {
  POINT aux;

  if (*p == NULL)
    return -1;

    if (x.key < (*p)->item.key)
      return remove_element(x, &(*p)->left);

    if (x.key > (*p)->item.key)
      return remove_element(x, &(*p)->right);

    if ((*p)->right == NULL) {
      aux = *p;
      *p = (*p)->left;
      free(aux);
      return 0;
    }

    if ((*p)->left == NULL) {
      aux = *p;
      *p = (*p)->right;
      free(aux);
      return 0;
    }

    predecessor(*p, &(*p)->left);
    return 0;
}

void go_through_in(POINT p) {
  if (p != NULL) {
    go_through_in(p->left);
    printf("%d\n", p->item.key);
    go_through_in(p->right);
  }
}

void go_through_pre(POINT p) {
  if (p != NULL) {
    printf("%d\n", p->item.key);
    go_through_pre(p->left);
    go_through_pre(p->right);
  }
}

void go_through_pos(POINT p) {
  if (p != NULL) {
    go_through_pos(p->left);
    go_through_pos(p->right);
    printf("%d\n", p->item.key);
  }
}
