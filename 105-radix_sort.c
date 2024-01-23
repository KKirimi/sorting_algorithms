#include "sort.h"

/**
 * get_max - Get the maximum integer value
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int max, i;

	for (max = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

return (max);
}

/**
 * bucket - Bucket digits in ascending order
 * @array: An array of integers.
 * @size: The size of the array.
 * @digit: The significant digit to sort on.
 * @buffer: A buffer to store the sorted array.
 */
void bucket(int *array, size_t size, int digit, int *buffer)
{
	int count[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / digit) % 10] += 1;

	for (i = 0; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		buffer[count[(array[i] / digit) % 10] - 1] = array[i];
		count[(array[i] / digit) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = buffer[i];
}

/**
 * radix_sort - concatenates the buckets
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the LSD radix sort algorithm. Prints
 * the array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
	int max, digit, *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	max = get_max(array, size);
	for (digit = 1; max / digit > 0; digit *= 10)
	{
		bucket(array, size, digit, buffer);
		print_array(array, size);
	}

free(buffer);
}
