#include "sort.h"

/**
 * node_swap - Moves a node in a doubly linked list from one position
 * to another within the list
 * @list: Points to the first node in the list
 * @pos: Points to the node in the position the node will be moved to
 * @node: Points to the node to be moved
 */

void node_swap(listint_t **list, listint_t *pos, listint_t *node)
{
	if (pos == NULL || node == NULL)
		return;

	node->prev->next = node->next;
	if (node->next)
		node->next->prev = node->prev;

	node->prev = pos->prev;
	if (pos->prev)
		pos->prev->next = node;
	else
		*list = node;

	node->next = pos;
	pos->prev = node;
}

/**
 * insertion_sort_list - Sorts a doubly linked list in ascending order using
 * the insertion sort algorithm
 * @list: Points to the list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *tmp_bw, *tmp_fw, *node;

	if (list == NULL || *list == NULL || !(*list)->next)
		return;

	for (node = (*list)->next; node != NULL; node = tmp_fw)
	{
		tmp_fw = node->next;
		tmp_bw = node->prev;

		while (tmp_bw && node->n < tmp_bw->n)
		{
			node_swap(list, tmp_bw, node);
			print_list(*list);
			tmp_bw = tmp_bw->prev->prev;
		}
	}
}
