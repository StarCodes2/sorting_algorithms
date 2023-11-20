#include "sort.h"

/**
 * selection_sort - Sorts an array in ascending order using the selection sort
 * algorithm
 * @array: Points to the array
 * @size: Contains the size of the array
 */

void selection_sort(int *array, size_t size)
{
	int tmp;
	size_t i, j, s_id;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		s_id = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[s_id] > array[j])
				s_id = j;
		}

		if (i != s_id)
		{
			tmp = array[i];
			array[i] = array[s_id];
			array[s_id] = tmp;
			print_array(array, size);
		}
	}
}
