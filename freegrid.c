#include "monty.h"

/**
 * __freeGrid - deallocates a 2D array
 * @grid: a 2D aray pointer
 * Return: Nothing
 */
void __freeGrid(char **grid)
{
char **copy_grid = grid;

for (; *grid != NULL; grid++)
{
free(*grid);
}
free(copy_grid);
}

/**
 * __freeList - frees nodes in a doubly linked list
 * @head: pointer to list end
 */
void __freeList(stack_t *head)
{
	stack_t *current = head;

	if (head == NULL)
		return;

	do {
		if (current->next == NULL)
			break;
		current = current->next;
		if (current != NULL || current->prev != NULL)
			free(current->prev);
	} while (current);

	free(current);
}
