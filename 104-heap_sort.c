#include "sort.h"

/**
* swap_ints - A function that swap two integers in an array.
* @a: The first integer to swap.
* @b: The second integer to swap.
*/

void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * sift_down - Turn a binary tree into a complete binary heap.
 * @array: An array of integers representing a binary tree.
 * @size: The size of the array or tree.
 * @b_index: The index of the base row of the tree.
 * @root_node: The base node of the binary tree.
 */

void sift_down(int *array, size_t size, size_t b_index, size_t root_node)
{
	size_t l_node, right_node, large;

	l_node = 2 * root_node + 1;
	right_node = 2 * root_node + 2;
	large = root_node;

	if (l_node < b_index && array[l_node] > array[large])
		large = l_node;
	if (right_node < b_index && array[right_node] > array[large])
		large = right_node;

	if (large != root_node)
	{
		swap_ints(array + root_node, array + large);
		print_array(array, size);
		sift_down(array, size, b_index, large);
	}
}

/**
 * heap_sort - A function that sort an array of integers in ascending order
 * using sift_down heap sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */

void heap_sort(int *array, size_t size)
{
	int k;

	if (array == NULL || size < 2)
		return;

	for (k = (size / 2) - 1; k >= 0; k--)
		sift_down(array, size, size, k);

	for (k = size - 1; k > 0; k--)
	{
		swap_ints(array, array + k);
		print_array(array, size);
		sift_down(array, size, k, 0);
	}
}
