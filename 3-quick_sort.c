#include "sort.h"

/**
 * quicksort - uses the Lomuto partition scheme for quicksort implementation
 *
 * @array: array to sort
 * @lo: lowest index
 * @hi: highest index
 * @size: size of the array
 */
void quicksort(int *array, int lo, int hi, size_t size)
{
	int partition_i;

	if (lo >= hi || lo < 0)
		return;

	partition_i = partition(array, lo, hi, size);

	quicksort(array, lo, partition_i - 1, size); /* sort left side */
	quicksort(array, partition_i, hi, size); /* sort right side */
}

/**
 * partition - divides array into two partitions
 * 
 * a pivot is created and the array is partitioned into two:
 * the indices less than the pivot and those greater than it
 *
 * @lo: lowest index
 * @hi: highest index
 * @array: array to partitions
 * @size: length of array
 *
 * Return: index between the partitions
 */
int partition(int *array, int lo, int hi, size_t size)
{
	int pivot, pivot_i, i, tmp;

	pivot = array[hi];
	/* set temporary pivot index */
	pivot_i = lo - 1;

	/* divide array into two: numbers below and numbers above pivot */
	for (i = lo; i < hi; ++i)
	{
		/*
		 * move numbers less than or equal to pivot to the left
		 * and numbers greater than pivot to the right
		 */
		if (array[i] <= pivot)
		{
			++pivot_i;
			tmp = array[i];
			array[i] = array[pivot_i];
			array[pivot_i] = tmp;

			/* values were swapped */
			if (array[i] != array[pivot_i])
				print_array(array, size);
		}
	}
	/*
	 * ensure previously registered high index correctly lies either to the
	 * left or to the right of the pivot
	 */
	++pivot_i;
	tmp = array[pivot_i];
	array[pivot_i] = array[hi];
	array[hi] = tmp;

	/* values were swapped */
	if (array[hi] != array[pivot_i])
		print_array(array, size);

	return (pivot_i);
}

/**
 * quick_sort - quick sort wrapper function
 *
 * @array: array to sort
 * @size: size of array to sort
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
