#include "sort.h"

/**
 * swap_nodes - Swap two nodes in the listint_t doubly linked list.
 * @h: A double pointer to the doubly linked list head node.
 * @n1: A double pointer to the first node to swap.
 * @n2: A pointer to the second node to swap.
 */

void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - A functin that sorts a doubly linked list using
 *	insertion sort algorithm.
 * @list: The doubly linked list to be sorted.
 * Description: Prints the list after each swap.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current_lead, *current_follow, *next_node;

	if (!list || !(*list) || !((*list)->next))
		return;

	current_follow = (*list);
	current_lead = (*list)->next;
	while (current_lead)
	{
		next_node = current_lead->next;
		while (current_follow && current_lead->n < current_follow->n)
		{
			swap_nodes(list, &current_follow, current_lead);
			print_list(*list);
			current_follow = current_lead->prev;
		}
		current_lead = next_node;
		if (current_lead)
			current_follow = current_lead->prev;
	}
}
