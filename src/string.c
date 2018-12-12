/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** string funtions
*/

#include <stdlib.h>

int my_strlen(const char *str)
{
	int i = 0;

	if (str == NULL)
		return (0);
	while (str[i] != '\0') {
		i++;
	}
	return (i);
}

char *my_strcpy(char *dest, const char *src)
{
	int i = 0;

	if (dest == NULL || src == NULL)
		return (NULL);
	while (src[i] != '\0') {
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char *my_strdup(const char *src)
{
	char *str;

	if (src == NULL)
		return (NULL);
	str = malloc(sizeof(char) * (my_strlen(src) + 1));
	if (str == NULL)
		return (NULL);
	my_strcpy(str, src);
	return (str);
}

char **my_realloc(char **array, char *str)
{
	int i = 0;
	int j = 0;
	char **new = NULL;

	while (array[i] != NULL)
		i++;
	if ((new = malloc(sizeof(char*) * (i + 2))) == NULL)
		return (NULL);
	while (j != i) {
		new[j] = array[j];
		j++;
	}
	new[i] = str;
	new[i + 1] = NULL;
	return (new);
}
