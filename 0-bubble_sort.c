#include "sort.h"

/**
 * bubble_sort - bubble sort algorithm implementation
 *
 * Bubble sort "Bubbles up" the least or greatest item till no
 * more items are left to be "Bubbled up"
 *
 * @array: doubly linked list to sort
 * @size: size of the list to sort
 */
void bubble_sort(int *array, size_t size)
{
	int i = 0;
	int j, tmp;

	while (i < size)
	{
		for (j = 0; j < size - i; ++j)
		{
			if (j < (size - i - 1) && array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
		}
		++i;
	}
}
