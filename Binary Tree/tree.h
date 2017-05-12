#ifndef TREE_H
#define TREE_H

typedef struct {
  int key;
} ITEM;

typedef struct NODE_TAG *POINT;

typedef struct NODE_TAG {
  ITEM item;
  POINT left, right;
} NODE;

typedef POINT TREE;

void create(TREE *);
int search(ITEM*, POINT*);
int insert(ITEM, POINT*);
int remove(ITEM, POINT*);
void go_through_in(POINT p);
void go_through_pre(POINT p);
void go_through_pos(POINT p);

#endif
