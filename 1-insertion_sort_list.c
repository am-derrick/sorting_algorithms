#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of int using
 * Insertion sort algorithm
 * @list: double pointer to head of linked list to be sorted
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *swap_node, *swap_next;

	if (list == NULL || *list == NULL)
		return;
	swap_node = (*list)->next;
	while (swap_node != NULL)
	{
		swap_next = swap_node->next;
		while (swap_node->prev != NULL && swap_node->prev->n > swap_node->n)
		{
			swap_node->prev->next = swap_node->next;
			if (swap_node->next != NULL)
				swap_node->next->prev = swap_node->prev;
			swap_node->next = swap_node->prev;
			swap_node->prev = swap_node->next->prev;
			swap_node->next->prev = swap_node;
			if (swap_node->prev == NULL)
				*list = swap_node;
			else
				swap_node->prev->next = swap_node;
			print_list(*list);
		}
		swap_node = next_swap;
	}
}
