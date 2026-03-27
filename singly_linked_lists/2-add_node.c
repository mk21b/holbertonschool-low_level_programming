#include "lists.h"
/**
 * add_node - Adds a new node at the beginning of a list_t list.
 * @head: A double pointer to the list_t list.
 * @str: The string to be added to the new node.
 *
 * Return: The address of the new element, or NULL if it failed.
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new;
	int i;

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);
	for (i = 0; str[i]; i++)
		;
	new->len = i;
	new->str = strdup(str);
	new->next = *head;

	*head = new;

	return (new);
}
