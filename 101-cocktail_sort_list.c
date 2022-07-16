#include "sort.h"


/**
 * cocktail_sort_list - sorts a doubly linked list using the
 * cocktail shaker algorithm
 *
 * @list: list to sort
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *cur, *next;
	int swapped;

	if (list == NULL || !(*list) || (*list)->next == NULL)
		return;

	cur = *list;
	do {
		swapped = 0;
		while (cur->next)
		{
			next = cur->next;
			if (next && cur->n > next->n)
			{
				swap_nodes(cur, next, list);
				swapped = 1;
				print_list(*list);
			}
			else
				cur = cur->next;
		}
		cur = cur->prev;
		while (cur->prev)
		{
			next = cur->prev;
			if (next && cur->n < next->n)
			{
				swap_nodes(next, cur, list);
				swapped = 1;
				print_list(*list);
			}
			else
				cur = cur->prev;
		}
		cur = cur->next;
	} while (swapped);
}

/**
 * swap_nodes - swaps two nodes
 *
 * @a: first node
 * @b: second node
 * @list: parent list of the nodes
 */
void swap_nodes(listint_t *a, listint_t *b, listint_t **list)
{
	if (!(a->prev))
	{
		a->next = b->next;
		if (b->next)
			b->next->prev = a;
		b->next = a;
		b->prev = NULL;
		a->prev = b;
		*list = b;
	}
	else
	{
		b->prev->next = b->next;
		if (b->next)
			b->next->prev = b->prev;
		a->prev->next = b;
		b->prev = a->prev;
		a->prev = b;
		b->next = a;
	}
}
