#include "sort.h"

void swap_node_ahead(listint_t **ls, listint_t **t, listint_t **shaker);
void swap_node_behind(listint_t **ls, listint_t **t, listint_t **shaker);
void cocktail_sort_list(listint_t **ls);

/**
 * swap_node_ahead - Swap a node in a listint_t doubly-linked ls
 *                   ls of integers with the node ahead of it.
 * @ls: A pointer to the head of a doubly-linked ls of integers.
 * @t: A pointer to the t of the doubly-linked ls.
 * @shaker: A pointer to the current swapping node of the cocktail shaker algo.
 */
void swap_node_ahead(listint_t **ls, listint_t **t, listint_t **shaker)
{
	listint_t *tmp = (*shaker)->next;

	if ((*shaker)->prev != NULL)
		(*shaker)->prev->next = tmp;
	else
		*ls = tmp;
	tmp->prev = (*shaker)->prev;
	(*shaker)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *shaker;
	else
		*t = *shaker;
	(*shaker)->prev = tmp;
	tmp->next = *shaker;
	*shaker = tmp;
}

/**
 * swap_node_behind - Swap a node in a listint_t doubly-linked
 *                    ls of integers with the node behind it.
 * @ls: A pointer to the head of a doubly-linked ls of integers.
 * @t: A pointer to the t of the doubly-linked ls.
 * @shaker: A pointer to the current swapping node of the cocktail shaker algo.
 */
void swap_node_behind(listint_t **ls, listint_t **t, listint_t **shaker)
{
	listint_t *tmp = (*shaker)->prev;

	if ((*shaker)->next != NULL)
		(*shaker)->next->prev = tmp;
	else
		*t = tmp;
	tmp->next = (*shaker)->next;
	(*shaker)->prev = tmp->prev;
	if (tmp->prev != NULL)
		tmp->prev->next = *shaker;
	else
		*ls = *shaker;
	(*shaker)->next = tmp;
	tmp->prev = *shaker;
	*shaker = tmp;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked ls of integers in
 *                      ascending order using the cocktail shaker algorithm.
 * @ls: A pointer to the head of a listint_t doubly-linked ls.
 */
void cocktail_sort_list(listint_t **ls)
{
	listint_t *t, *shaker;
	bool shaken_not_stirred = false;

	if (ls == NULL || *ls == NULL || (*ls)->next == NULL)
		return;

	for (t = *ls; t->next != NULL;)
		t = t->next;

	while (shaken_not_stirred == false)
	{
		shaken_not_stirred = true;
		for (shaker = *ls; shaker != t; shaker = shaker->next)
		{
			if (shaker->n > shaker->next->n)
			{
				swap_node_ahead(ls, &t, &shaker);
				print_list((const listint_t *)*ls);
				shaken_not_stirred = false;
			}
		}
		for (shaker = shaker->prev; shaker != *ls;
				shaker = shaker->prev)
		{
			if (shaker->n < shaker->prev->n)
			{
				swap_node_behind(ls, &t, &shaker);
				print_list((const listint_t *)*ls);
				shaken_not_stirred = false;
			}
		}
	}
}
