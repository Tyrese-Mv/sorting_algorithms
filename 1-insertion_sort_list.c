#include "sort.h"
/**
 * insertion_sort_list - uses insertion to reorder lists
 * @list: doubly linked list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *prev = (*list), *current = (*list)->next, *fHead = (*list), *temp;

	if (*list == NULL || (*list)->next == NULL)
		return;
	while (current)
	{
		if (current->n >= prev->n)
		{
			prev = current;
			current = current->next;
		}
		else
		{
			temp = fHead;
			if (current->n < temp->n)
			{
				prev->next = current->next;
				if (current->next != NULL)
					current->next->prev = prev;
				current->next = fHead;
				fHead->prev = current;
				current->prev = NULL;
				fHead = current;
				*list = fHead;
				print_list(*list);
			}
			else
			{
				while (temp->next != NULL && current->n > temp->next->n)
					temp = temp->next;
				prev->next = current->next;
				if (current->next != NULL)
					current->next->prev = prev;
				current->next = temp->next;
				if (temp->next != NULL)
					temp->next->prev = current;
				temp->next = current;
				current->prev = temp;
				print_list(*list);
			}
			current = prev->next;
		}
	}
	*list = fHead;
}
