#include "sort.h"

/**
 * quick_sort_hoare - Calls the function that sorts an array of integers in
 * ascending order using the Quick Sort algorithm
 * @array: Points to the array to be sorted
 * @size: Holds the size of the array
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hq_sort(array, size, 0, size - 1);
}

/**
 * hq_sort - Uses recursion to further split and sort the array splited by the
 * hoare_part funtion
 * @array: Points to the array
 * @size: Holds the size of the array
 * @start: Holds the index where the lomuto_part function starts scanning from
 * @end: Holds the index where the lomuto^part function stop scanning at
 */

void hq_sort(int *array, size_t size, int start, int end)
{
	int part;

	if (start >= 0 && end >= 0 && start < end)
	{
		part = hoare_part(array, size, start, end);
		hq_sort(array, size, start, part - 1);
		hq_sort(array, size, part + 1, end);
	}
}

/**
 * hoare_part - Partitions an array in respect to an element in the middle
 *		of the array, sorting elements that less than it to the left
 *		and ones that larger to the right
 * @array: Points to the array
 * @size: Hold the size of the entire array
 * @start: Holds the index where the function will start scanning from
 * @end: Holds the index where the function will scan to in the array
 *
 * Return: the index where the array will be partitioned
 */

int hoare_part(int *array, size_t size, int start, int end)
{
	int i, j, pivot, tmp;

	pivot = array[((end - start) / 2) + start];
	i = start;
	j = end;

	while (1)
	{
		while (array[i] < pivot)
			i++;

		while (array[j] > pivot)
			j--;

		if (i >= j)
			return (j);

		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;

		print_array(array, size);
	}
}
