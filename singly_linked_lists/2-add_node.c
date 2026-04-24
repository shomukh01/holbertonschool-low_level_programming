#include "lists.h"
#include <stdlib.h>
#include <string.h>

/**
	* add_node - adds a new node at the beginning
	* @head: pointer to head
	* @str: string to store
	*
	* Return: address of new element, or NULL
	*/
list_t *add_node(list_t **head, const char *str)
{
	list_t *new;

	if (str == NULL)
		return (NULL);

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);

	new->str = strdup(str);
	if (new->str == NULL)
	{
		free(new);
		return (NULL);
	}

	new->len = strlen(str);
	new->next = *head;
	*head = new;

	return (new);
}
