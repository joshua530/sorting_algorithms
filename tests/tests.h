#ifndef TESTS_H
#define TESTS_H

#include "../sort.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void print_result(bool test_passed, char *message);

listint_t *create_list(const int *nums, size_t size);
bool are_equal_int_arrays(int *a, int *b, int size);
bool are_equal_int_lists(listint_t *a, listint_t *b, int size);

#endif
