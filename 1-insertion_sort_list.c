#include "sort.h"
/**
 * insertion_sort_list - uses insertion to reorder lists
 * @list: doubly linked list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *prev = (*list), *current = (*list)->next, *fHead = (*list), *temp;

	if ((*list)->next == NULL || *list == NULL)
		return;
	while (current)
	{
		if (current->n > prev->n)
		{
			prev = current;
			current = current->next;
		}
		temp = fHead;
		while (current->n > temp->next->n)
			temp = temp->next;
		prev->next = current->next;
		current->next = temp->next;
		temp->next = current;
		current = prev->next;
		print_list(*list);
	}
}
