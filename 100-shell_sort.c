#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using Shell Sort
 * @array: Points to the array
 * @size: Holds the soze of the array
 */

void shell_sort(int *array, size_t size)
{
	size_t gap, i, j, n = 1;
	int tmp;

	if (array == NULL || size < 2)
		return;

	while (n < size)
	{
		gap = n;
		n = (n * 3) + 1;
	}

	for (n = gap; n > 0; n = (n - 1) / 3)
	{
		for (i = n; i < size; i++)
		{
			for (j = i; (j >= n) && (array[j - n] > array[j]);
					j -= n)
			{
				tmp = array[j];
				array[j] = array[j - n];
				array[j - n] = tmp;
			}
		}
		print_array(array, size);
	}
}
