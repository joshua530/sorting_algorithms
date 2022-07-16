#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - counting sort implementation
 *
 * @array: array to sort
 * @size: size of array
 */
void counting_sort(int *array, size_t size)
{
	size_t i;
	int j, k, num, dup;
	int *counts;

	if (array == NULL || size < 2)
		return;

	k = array[0];
	for (i = 1; i < size; i++)
		if (array[i] > k)
			k = array[i];

	counts = malloc(sizeof(int) * (k + 1));
	if (counts == NULL)
		return;

	for (j = 0; j < (k + 1); ++j)
		counts[j] = 0;
	for (i = 0; i < size; ++i)
	{
		num = array[i];
		counts[num] += 1;
	}
	for (j = 0; j < k; j++)
		counts[j + 1] += counts[j];
	print_array(counts, k + 1);

	for (i = 0, j = 0; j < k; ++j)
	{
		if ((j == 0) && counts[j] != 0)
			for ((dup = counts[j]); dup > 0; --dup)
				array[i++] = j;
		if (counts[j + 1] > counts[j])
			for ((dup = counts[j + 1] - counts[j]); dup > 0; --dup)
				array[i++] = (j + 1);
	}

	free(counts);
}
