#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @list: Double pointer to the head of the list.
 * @node1: First node to be swapped.
 * @node2: Second node to be swapped.
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (!node1 || !node2)
		return;
	if (node1->prev)
		node1->prev->next = node2;
	else
		*list = node2;
	if (node2->next)
		node2->next->prev = node1;
	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list using Cocktail Shaker Sort.
 * @list: Double pointer to the head of the list.
 */
void cocktail_sort_list(listint_t **list)
{
	if (!list || !(*list) || !(*list)->next)
		return;
	int shake_range = 1000000;
	listint_t *current_node = *list;

	do {
		bool forward_swapped = false;
		bool backward_swapped = false;
		int num_checks;

		for (num_checks = 0;
				current_node->next && num_checks < shake_range; num_checks++)
		{
			if (current_node->next->n < current_node->n)
			{
				swap_nodes(list, current_node, current_node->next);
				forward_swapped = true;
			}
			else
				current_node = current_node->next;
		}
		if (!current_node->next)
			shake_range = num_checks;
		if (forward_swapped)
			current_node = current_node->prev;
		shake_range--;
		for (num_checks = 0;
				current_node->prev && num_checks < shake_range; num_checks++)
		{
			if (current_node->n < current_node->prev->n)
			{
				swap_nodes(list, current_node->prev, current_node);
				backward_swapped = true;
			}
			else
				current_node = current_node->prev;
		}
		if (backward_swapped)
			current_node = current_node->next;
	} while (forward_swapped || backward_swapped);
}
