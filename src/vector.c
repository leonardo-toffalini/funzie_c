#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void vector_init(Vector *vector, size_t element_size) {
  vector->data = NULL;
  vector->element_size = element_size;
  vector->size = 0;
  vector->capacity = 0;
}

void vector_push_back(Vector *vector, void *element) {
  if (vector->size == vector->capacity) {
    vector->capacity = (vector->capacity == 0) ? 1 : vector->capacity * 2;
    vector->data =
        realloc(vector->data, vector->capacity * vector->element_size);
    if (!vector->data) {
      fprintf(stderr, "Memory allocation failed\n");
      exit(EXIT_FAILURE);
    }
  }
  void *target = (char *)vector->data + (vector->size * vector->element_size);
  memcpy(target, element, vector->element_size);
  vector->size++;
}

void vector_pop_back(Vector *vector) {
  if (vector->size > 0) {
    vector->size--;
  }
}

void *vector_get(Vector *vector, size_t index) {
  if (index >= vector->size) {
    fprintf(stderr, "Index out of bounds\n");
    return NULL;
  }
  return (char *)vector->data + (index * vector->element_size);
}

void vector_free(Vector *vector) {
  free(vector->data);
  vector->data = NULL;
  vector->size = 0;
  vector->capacity = 0;
}
