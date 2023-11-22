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
                current->next = fHead;
                fHead = current;
				*list = fHead;
            }
			else
			{
				while (temp->next != NULL && current->n > temp->next->n)
					temp = temp->next;
				prev->next = current->next;
				current->next = temp->next;
				temp->next = current;
			}
			current = prev->next;
			print_list(*list);
		}
		
	}
	*list = fHead;
}
