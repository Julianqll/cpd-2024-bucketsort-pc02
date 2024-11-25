#include "bucketsort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>

#define N_BUCKETS 94
#define LENGTH 8

typedef struct {
  long int *data;
  int length;
  long int total;
} bucket;

void sort(char *a, bucket *bucket) {
  int j, i;
  long int key;
  for (j = 1; j < bucket->total; j++) {
    key = bucket->data[j];
    i = j - 1;
    while (i >= 0 && strcmp(a + bucket->data[i] * bucket->length,
                            a + key * bucket->length) > 0) {
      bucket->data[i + 1] = bucket->data[i];
      i--;
    }
    bucket->data[i + 1] = key;
  }
}

long int *bucket_sort(char *a, int length, long int size) {
  long int i;
  bucket buckets[N_BUCKETS];
  long int *returns = (long int *)malloc(sizeof(long int) * size);
  long int *bucket_data[N_BUCKETS];

  // Allocate memory for each bucket
  for (i = 0; i < N_BUCKETS; i++) {
    bucket_data[i] = (long int *)malloc(sizeof(long int) * size);
    buckets[i].data = bucket_data[i];
    buckets[i].length = length;
    buckets[i].total = 0;
  }

  // Distribute elements into buckets in parallel
  #pragma omp parallel for
  for (i = 0; i < size; i++) {
    int bucket_index = *(a + i * length) - 0x21;
    #pragma omp critical
    {
      buckets[bucket_index].data[buckets[bucket_index].total++] = i;
    }
  }

  // Sort each bucket in parallel
  #pragma omp parallel for
  for (i = 0; i < N_BUCKETS; i++) {
    sort(a, &buckets[i]);
  }

  // Collect sorted elements
  long int index = 0;
  for (i = 0; i < N_BUCKETS; i++) {
    for (int j = 0; j < buckets[i].total; j++) {
      returns[index++] = buckets[i].data[j];
    }
  }

  // Free bucket memory
  for (i = 0; i < N_BUCKETS; i++) {
    free(bucket_data[i]);
  }

  return returns;
}
