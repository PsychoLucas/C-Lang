#ifndef LIST_H
#define LIST_H

typedef struct CEL_TAG *PTR;

typedef struct {
  int line, col;
  double value;
} ITEM;

typedef struct CEL_TAG {
  ITEM item;
  PTR right;
  PTR below;
} CEL;

typedef struct {
  PTR first, last;
} LIST;

void create(LIST*);
int insert_in_line(LIST*, PTR);
int insert_in_col(LIST*, PTR);
void print_line(LIST*, int);

#endif
