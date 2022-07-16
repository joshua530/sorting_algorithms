#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - insertion sort implementation
 *
 * @list: list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *tmp, *cur;

	if (list == NULL || *list == NULL)
		return;

	iter = *list;

	while (iter->next)
	{
		iter = iter->next;
		tmp = iter;

		while (tmp->prev && tmp->prev->n > tmp->n)
		{
			cur = tmp->prev;

			if (cur->prev)
			{
				cur->prev->next = tmp;
			}
			tmp->prev = cur->prev;
			cur->prev = tmp;

			if (tmp->next)
			{
				tmp->next->prev = cur;
			}
			cur->next = tmp->next;
			tmp->next = cur;

			if (!tmp->prev)
				*list = tmp;
			print_list(*list);
		}
	}
}
