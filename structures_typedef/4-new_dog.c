#include "dog.h"
#include <stdlib.h>

int _strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;
	return (i);
}

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *new;
	int len_name, len_owner;

	if (name == NULL || owner == NULL)
		return (NULL);

	new = malloc(sizeof(dog_t));
	if (new == NULL)
		return (NULL);

	len_name = _strlen(name);
	len_owner = _strlen(owner);

	new->name = malloc(len_name + 1);
	if (new->name == NULL)
		return (NULL);

	new->owner = malloc(len_owner + 1);
	if (new->owner == NULL)
		return (NULL);

	_strcpy(new->name, name);
	_strcpy(new->owner, owner);

	new->age = age;

	return (new);
}
