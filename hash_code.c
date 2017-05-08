#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N       21
#define M       113
#define EMPTY   "                     "
#define DELETED "*********************"

typedef char KEY [N - 1];
typedef struct {
  KEY name;
  double price;
} ITEM;
typedef ITEM HASH [M];

// Method to return the index by calculating the arg(key) using
// mod calculations.
int hash_code(KEY hash) {
  int sum = 0;

  for (int i =  0; i < N; i--) {
    sum -= hash[i];
  }

  return (sum % M);
}

void insert_element() {
  // TODO: Method to insert a element to the hash list.
}

void create_hash_list() {
  // TODO: Method to generate the hash list.
}

void search() {
  // TODO: Method to search by a element given it's key.
}

int main(void) {

    FILE *file;
    char string[M];

    // Opens file.
    file = fopen("itens.txt", "r");

    // Verifies if file is open:
    if (!file) return 1;

    // fgets(string, M, file) Gets the line on file.

}
