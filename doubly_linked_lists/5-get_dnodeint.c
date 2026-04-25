#include "lists.h"

/**
	* get_dnodeint_at_index - returns nth node
	* @head: pointer to head
	* @index: index of node
	*
	* Return: node or NULL
	*/
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i = 0;

	while (head != NULL)
	{
		if (i == index)
			return (head);

		head = head->next;
		i++;
	}

	return (NULL);
}
