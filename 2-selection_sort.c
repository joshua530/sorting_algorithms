#include "sort.h"

/**
 * selection_sort - selection sort algorithm implementation
 *
 * for each iteration, the minimum number is selected from the
 * array and inserted into the current position
 *
 * @array: array to sort
 * @size: size of array to sort
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;
	int tmp;

	for (i = 0; i < size; ++i)
	{
		min_index = i;
		for (j = i + 1; j < size; ++j)
		{
			if (array[j] < array[min_index])
				min_index = j;
		}
		if (min_index != i)
		{
			tmp = array[i];
			array[i] = array[min_index];
			array[min_index] = tmp;
			print_array(array, size);
		}
	}
}
