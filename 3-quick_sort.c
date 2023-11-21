#include "sort.h"

/**
 * quick_sort - Calls the function that sorts an array of integers in
 * ascending order using the Quick Sort algorithm
 * @array: Points to the array to be sorted
 * @size: Holds the size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	q_sort(array, size, 0, size - 1);
}

/**
 * q_sort - Uses recursion to further split and sort the array splited by the
 * lomuto_part funtion
 * @array: Points to the array
 * @size: Holds the size of the array
 * @start: Holds the index where the lomuto_part function starts scanning from
 * @end: Holds the index where the lomuto^part function stop scanning at
 */

void q_sort(int *array, size_t size, int start, int end)
{
	int part;

	if (start >= end)
		return;

	part = lomuto_part(array, size, start, end);
	q_sort(array, size, start, part - 1);
	q_sort(array, size, part + 1, end);
}

/**
 * lomuto_part - Partitions an array in respect to it last element, sorting
 *		elements that less than it to the left and ones that larger
 *		to the right
 * @array: Points to thale array
 * @size: Hold the size of the entire array
 * @start: Holds the index where the function will start scanning from
 * @end: Holds the index where the function will scan to in the array
 *
 * Return: the index where the array will be partitioned
 */

int lomuto_part(int *array, size_t size, int start, int end)
{
	int i = start, j, pivot = array[end], tmp;

	for (j = start; j < end; j++)
	{
		if (array[j] <= pivot)
		{
			if (i < j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
			i++;
		}
	}

	if (array[i] > pivot)
	{
		tmp = array[i];
		array[i] = array[end];
		array[end] = tmp;
		print_array(array, size);
	}

	return (i);
}
