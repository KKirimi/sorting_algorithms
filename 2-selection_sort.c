#include "sort.h"
/**
 *selection_sort- function that sorts using selection sort algorithm
 *@array: array to be sorted
 *@size: size of the array
 *
 */

void selection_sort(int *array, size_t size)
{
	size_t m, j, k;
	int temp;

	if (!array || !size)
		return;
	for (m = 0; m < size - 1; m++)
	{
		for (j = size - 1, k = m + 1; j > m; j--)
		{
			if (array[j] < array[k])
			{
				k = j;
			}
		}
		if (array[m] > array[k])
		{
			temp = array[m];
			array[m] = array[k];
			array[k] = temp;
			print_array(array, size);
		}
	}
}
