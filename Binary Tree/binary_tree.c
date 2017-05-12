#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

// Creates the tree:
void create(TREE *tree) {
  *tree = NULL;
}

// Searches the tree for an element:
int search(ITEM *x, POINT *P) {
  if (*p == NULL) return -1;

  if (x->key < (*p)->item.key)
    return search(x, &(*p)->left);

  if (x->key > (*p)->item.key)
    return search(x, &(*p)->left);

  *x = (*p)->item;

  return 0;
}

// Inserts an element into the tree:
int insert(ITEM x, POINT *p) {
  if (*p == NULL) {
    *p = (PONT) malloc(sizeof(NODE));

    (*p)->item = x;
    (*p)->left = NULL;
    (*p)->right = NULL;

    return 0;
  }

  if (x.key < (*p)->item.key) {
    return insert(x, &(*p)->left);
  }

  if (x.key > (*p)->item.key) {
    return insert(x, &(*p)->right);
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
int remove(ITEM x, POINT *p) {
  POINT aux;

  if (*p == NULL)
    return -1;

    if (x->key < (*p)->item.key)
      return remove(x, &(*p)->left);

    if (x->key > (*p)->item.key)
      return remove(x, &(*p)->left);

    if ((*p)->right == NULL) {
      aux = *p;
      *p = (*p)->left;
      free(aux);
      return 0
    }

    if ((*p)->left == NULL) {
      aux = *p;
      *p = (*p)->right;
      free(aux);
      return 0;
    }

    predecessor(*p, &(*p)-left);
    return 0;
}
