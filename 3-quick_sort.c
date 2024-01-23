#include "sort.h"

/**
* swap - swaps two integer
* Description: helper fxn used by Lomuto
* partition scheme to swap elements
* @a: pointer to the first integer
* @b: pointer to the second integer
*/
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
* lomuto_partition - function to implement Lomuto
* @array: array to be partitioned
* @low: starting index of the partition
* @high: ending index of the partition
* Return: The partition index
*/
int lomuto_partition(int *array, int low, int high)
{
	int pivot, i, j;

	pivot = array[high];
	i = low;
	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			swap(&array[i], &array[j]);
			i++;
		}
	}
	swap(&array[i], &array[high]);
	print_array(array, high + 1);
	return (i);
}

/**
* quick_sort_recursively - fxn to recursively implement
* quick sort
* @array: Array to be sorted
* @low: starting index of the subarray
* @high: ending index of the subarray
*/
void quick_sort_recursively(int *array, int low, int high)
{
	int partition_index;

	if (low < high)
	{
		partition_index = lomuto_partition(array, low, high);
		quick_sort_recursively(array, low, partition_index - 1);
		quick_sort_recursively(array, partition_index + 1, high);
	}
}

/**
* quick_sort - wrapper fxn for quick_sort_recursively()
* @array: Array to be sorted
* @size: size of the array
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
	{
		return;
	}
	print_array(array, size);
	quick_sort_recursively(array, 0, size - 1);
}
