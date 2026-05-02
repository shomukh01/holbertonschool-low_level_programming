#include <stdlib.h>
#include <string.h>
#include "hash_tables.h"

/**
 * update_value - updates value if key exists
 * @current: current node
 * @key: key
 * @value: value
 *
 * Return: 1 if updated, 0 otherwise
 */
int update_value(hash_node_t *current, const char *key, const char *value)
{
	char *value_copy;

	while (current)
	{
		if (strcmp(current->key, key) == 0)
		{
			value_copy = strdup(value);
			if (!value_copy)
				return (0);
			free(current->value);
			current->value = value_copy;
			return (1);
		}
		current = current->next;
	}
	return (0);
}

/**
 * hash_table_set - adds an element to the hash table
 * @ht: hash table
 * @key: key
 * @value: value
 *
 * Return: 1 if success, 0 if fail
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *node;

	if (!ht || !key || *key == '\0' || !value)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);

	if (update_value(ht->array[index], key, value))
		return (1);

	node = malloc(sizeof(hash_node_t));
	if (!node)
		return (0);

	node->key = strdup(key);
	node->value = strdup(value);

	if (!node->key || !node->value)
	{
		free(node->key);
		free(node->value);
		free(node);
		return (0);
	}

	node->next = ht->array[index];
	ht->array[index] = node;

	return (1);
}
