#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>

typedef struct {
  void *data;          // Pointer to the elements
  size_t element_size; // Size of each element
  size_t size;         // Current number of elements
  size_t capacity;     // Total capacity of the vector
} Vector;

// Function declarations
Vector vector_init(size_t element_size);
void vector_push_back(Vector *vector, void *element);
void vector_pop_back(Vector *vector);
void *vector_get(Vector *vector, size_t index);
void vector_set(Vector *vector, size_t index, void *element);
void vector_free(Vector *vector);

#endif // !VECTOR_H
