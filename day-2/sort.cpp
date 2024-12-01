#include <iostream>
#include <stdlib.h>
#include <vector>

#include "sort.h"

void swap(std::vector<int> &A, int i, int j) {
  int c = A[i];
  A[i] = A[j];
  A[j] = c;
  return;
}

int partition(std::vector<int> &A, int low, int high) {
  int i = low;
  int pivot = A[high];

  for (int j = low; j < high; j++) {
    if (A[j] <= pivot) {
      swap(A, j, i);
      i++;
    }
  }

  swap(A, i, high);
  return i;
}

void quicksort(std::vector<int> &A, int low, int high) {
  if (low >= high || low < 0)
    return;
  int p = partition(A, low, high);
  quicksort(A, low, p - 1);
  quicksort(A, p + 1, high);
  return;
}
