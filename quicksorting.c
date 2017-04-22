#include <stdlib.h>
#include <stdio.h>

// Method that slices the array into two arrays.
int partition_array (int *arr, int left, int right) {
  int aux;
  int count = left;

  for (int i = left + 1; i <= right; i++) {
    if (*(arr + i) < *(arr + left)) {
      count++;
      aux = *(arr + i);
      *(arr + i) = *(arr + count);
      *(arr + count) = aux;
      }
  }

  aux = *(arr + left);
  *(arr + left) = *(arr + count);
  *(arr + count) = aux;

  return count;
}

// Recursive Quick Sorting method
void quick_sort (int *arr, int left, int right) {
  int pivot;

  if (left < right) {
    pivot = partition_array(arr, left, right);
    quick_sort(arr, left, pivot - 1);
    quick_sort(arr, pivot + 1, right);
  }
}

void print (int *arr, int size) {
  for (int i = 0; i < size; i++) {
    i == size - 1 ? printf("%d ", arr[i]) : printf("%d, ", arr[i]);
  }
}

int main(void) {
  int arr[] = {7, 8, 2, 6, 3, 5, 4, 0, 9, 1}; // Desordenated array
  int size = sizeof(arr) / sizeof(int); // Size of the array

  printf("Before: ");
  print(arr, size);

  printf("\n\n");
  quick_sort(arr, 0, size - 1);

  printf("After: \t");
  print(arr, size);
}
