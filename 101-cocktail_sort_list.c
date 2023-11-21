#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list in ascending order using
 *			the Cocktail Sort algorithm
 * @list: Points to a pointer to the head of the list
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *temp;
	int swapped;

	if (list == NULL || *list == NULL || !(*list)->next)
		return;

	temp = *list;
	do {
		swapped = 0;
		while (temp->next)
		{
			if (temp->n > temp->next->n)
			{
				list_swap(list, temp, temp->next);
				print_list(*list);
				swapped = 1;
				continue;
			}
			temp = temp->next;
		}
		temp = temp->prev;
		if (!swapped)
			break;

		while (temp->prev)
		{
			if (temp->n < temp->prev->n)
			{
				list_swap(list, temp->prev, temp);
				print_list(*list);
				swapped = 1;
				continue;
			}
			temp = temp->prev;
		}
		temp = temp->next;
	} while (swapped);
}

/**
 * list_swap - Swaps two elements in a listint_t doubly linked list
 * @list: Points to a pointer to the head of the list
 * @left_n: Points to the node on the left side
 * @right_n: Points to the node on the right side
 */

void list_swap(listint_t **list, listint_t *left_n, listint_t *right_n)
{
	left_n->next = right_n->next;
	if (left_n->next)
		left_n->next->prev = left_n;
	right_n->next = left_n;

	right_n->prev = left_n->prev;
	if (right_n->prev)
		right_n->prev->next = right_n;
	else
		*list = right_n;
	left_n->prev = right_n;
}
