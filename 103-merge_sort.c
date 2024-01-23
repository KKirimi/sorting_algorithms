#include "sort.h"

/**
 * div_list - function that divides the unsorted list
 * @subarray: A subarray of an array.
 * @buffer: A buffer to store divided subarray.
 * @lower: The lower bound index of the array.
 * @mid: The middle index of the array.
 * @upper: The upper bound index of the array.
 */
void div_list(int *subarray, int *buffer, size_t lower, size_t mid,
size_t upper)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarray + lower, mid - lower);

	printf("[right]: ");
	print_array(subarray + mid, upper - mid);

	for (i = lower, j = mid; i < mid && j < upper; k++)
		buffer[k] = (subarray[i] < subarray[j]) ? subarray[i++] : subarray[j++];
	for (; i < mid; i++)
		buffer[k++] = subarray[i];
	for (; j < upper; j++)
		buffer[k++] = subarray[j];
	for (i = lower, k = 0; i < upper; i++)
		subarray[i] = buffer[k++];

	printf("[Done]: ");
	print_array(subarray + lower, upper - lower);
}

/**
 * mergeSortRecursive - repeatedly merges subarrays into sorted.
 * @subarray: A subarray of an array.
 * @buffer: A buffer to store the sorted subarray.
 * @lower: The lower bound index of subarray.
 * @upper: The upper bound index of subarray.
 */
void mergeSortRecursive(int *subarray, int *buffer, size_t lower,
		size_t upper)
{
	size_t mid;

	if (upper - lower > 1)
	{
		mid = lower + (upper - lower) / 2;
		mergeSortRecursive(subarray, buffer, lower, mid);
		mergeSortRecursive(subarray, buffer, mid, upper);
		div_list(subarray, buffer, lower, mid, upper);
	}
}

/**
 * merge_sort - Sorts an array of integers in ascending
 * @array: An array of integers.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	mergeSortRecursive(array, buffer, 0, size);

	free(buffer);
}
