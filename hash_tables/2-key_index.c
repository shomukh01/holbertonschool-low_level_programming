#include "hash_tables.h"

/**
 * key_index - gives the index of a key
 * @key: the key
 * @size: the size of the array
 *
 * Return: index of the key
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash;

	if (key == NULL || *key == '\0' || size == 0)
		return (0);

	hash = hash_djb2(key);

	return (hash % size);
}
