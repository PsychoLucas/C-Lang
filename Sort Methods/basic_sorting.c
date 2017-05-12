#include <stdio.h>
#include <stdlib.h>

void sort(int *arr, int size) {
  int pivot = 1;
  int i;
  int j;
  int aux;

  for (i = 0, pivot = 1; pivot <= 2; pivot++) {
    j = size - 1;
    do {
      while(pivot > arr[i]) i++;

      while(pivot <= arr[j]) j--;

      if(i < j) {
        aux = arr[i];
        arr[i] = arr[j];
        arr[j] = aux;
        i++;
        j--;
      }
    } while (i <= j);
  }

}

int get_biggest(int *arr, int size) {
  int pivot = 0;
  for (int i = 0; i < size; i++) {
    if(arr[i] > pivot) {
      pivot = arr[i];
    }
  }

  return pivot;
}

void print(int *arr, int size) {
  for (int i = 0; i < size; i++)
    printf("%d ", arr[i]);
}

int main(void) {
  int arr[] = {0, 1, 2, 1, 0, 2, 2, 1, 0, 1};
  int size = sizeof(arr)/sizeof(int);
  int pivot = get_biggest(arr, size);

  printf("Before: ");
  print(arr, size);

  printf("\n\n");

  printf("After: \t");
  sort(arr, size);
  print(arr, size);

}
