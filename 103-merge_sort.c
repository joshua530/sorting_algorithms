#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * print_seg - prints array segment
 * 
 * @arr: parent array
 * @seg: segment to print
 * @start: starting index
 * @end: ending index
 */
void print_seg(int *arr, char *seg, size_t start, size_t end)
{
	size_t i;

	printf("[%s]: ", seg);
	for (i = start; i < end; i++)
	{
		if (i != (end - 1))
			printf("%d, ", arr[i]);
		else
			printf("%d\n", arr[i]);
	}

}
/**
 * mergesort - performs merge sort operation
 * 
 * @array: original array
 * @working_arr: temporary array for holding sorted items
 * @lo: starting index
 * @hi: ending index
 */
void mergesort(int *array, int *working_arr, size_t lo, size_t hi)
{
	size_t i, l_half, r_half;
	size_t mid = (lo + hi) / 2;

	if (hi - lo <= 1)
		return;

	mergesort(array, working_arr, lo, mid);
	mergesort(array, working_arr, mid, hi);
	printf("Merging...\n");
	print_seg(array, "left", lo, mid);
	print_seg(array, "right", mid, hi);
	l_half = lo;
	r_half = mid;
	for (i = lo; i < hi; i++)
	{
		if ((l_half < mid) &&
		    ((r_half == hi) || (array[l_half] < array[r_half])))
		{
			working_arr[i] = array[l_half];
			++l_half;
		}
		else
		{
			working_arr[i] = array[r_half];
			++r_half;
		}
	}
	print_seg(working_arr, "Done", lo, hi);
	for (i = lo; i < hi; i++)
		array[i] = working_arr[i];
}

/**
 * merge_sort - wrapper for the merge sort function
 * 
 * @array: array to sort
 * @size: size of array
 */
void merge_sort(int *array, size_t size)
{
	int *working_arr;

	if (!array || size < 2)
		return;
	working_arr = malloc(sizeof(int) * size);
	if (!(working_arr))
		return;
	mergesort(array, working_arr, 0, size);
	free(working_arr);
}
