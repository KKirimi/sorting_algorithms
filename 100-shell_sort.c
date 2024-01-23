#include "sort.h"

/**
 * swap_ints - Swap two int in an array.
 * @a: The first int to swap.
 * @b: The second int to swap.
 */
void swap_ints(int *a, int *b)
{
	int jet;

	jet = *a;
	*a = *b;
	*b = jet;
}

/**
 * shell_sort - Sort an array of int in ascending
 *              order using the shell sort algorithm
 * @array: An array of int
 * @size: The size of the array
 * Description: Uses the Knuth interval sequence
 *		Prints the array after each swap of two elements
 */

void shell_sort(int *array, size_t size)
{
	size_t gap, k, j;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (k = gap; k < size; k++)
		{
			j = k;
			while (j >= gap && array[j - gap] > array[j])
			{
				swap_ints(array + j, array + (j - gap));
				j -= gap;
			}
		}
		print_array(array, size);
	}
}
