#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order
 * @array: Points to the array
 * @size: Contains the size of the array to be sorted
 */

void bubble_sort(int *array, size_t size)
{
	int temp, swap = 0;
	size_t i, j;

	if (array == NULL || size == 0)
		return;
	if (size > 1)
	{
		for (i = 0; i < size; i++)
		{
			for (j = 0; j < (size - i - 1); j++)
			{
				if (array[j] > array[j + 1])
				{
					temp = array[j];
					array[j] = array[j + 1];
					array[j + 1] = temp;
					swap = 1;
					print_array(array, size);
				}
			}
			if (!swap)
				break;
		}
	}
	else
	{
		print_array(array, size);
	}
}
