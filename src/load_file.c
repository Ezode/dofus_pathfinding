/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** load file fucntions
*/

#include <stdlib.h>
#include <stdio.h>
#include "my_rpg.h"

int check_char(char *line)
{
	int i = 0;

	while (line[i] != '\n') {
		if (line[i] - 48 < 0 || line[i] - 48 > 9)
			return (-1);
		else
			i++;
	}
	return (0);
}

int check_file(char **file)
{
	int i = 0;
	int len = my_strlen(file[0]);

	if (len == 0)
		return (-1);
	while (file[i] != NULL) {
		if (my_strlen(file[i]) != len)
			return (-1);
		else if (check_char(file[i]) == -1)
			return (-1);
		i++;
	}
	return (0);
}

char **malloc_tab(FILE *stream, t_path *info)
{
	char **file = NULL;
	char *line = NULL;
	size_t len = 0;

	info->h = 0;
	info->w = 0;
	if ((file = malloc(sizeof(char*))) == NULL)
		return (NULL);
	file[0] = NULL;
	while (getline(&line, &len, stream) != -1) {
		if ((file = my_realloc(file, line)) == NULL)
			return (NULL);
		line = NULL;
		info->h++;
	}
	info->w = my_strlen(file[0]) - 1;
	return (file);
}

int **convert_map(char **map, t_path *info)
{
	int i = 0;
	int j = 0;
	int **copy = NULL;

	if ((copy = malloc(sizeof(int*) * info->h)) == NULL)
		return (NULL);
	while (i != info->h) {
		if ((copy[i] = malloc(sizeof(int) * info->w)) == NULL)
			return (NULL);
		i++;
	}
	for (i = 0; i != info->h; i++) {
		for (j = 0; j != info->w; j++)
			copy[i][j] = map[i][j] - 48;
	}
	return (copy);
}

int **load_map(char *name, t_path *info)
{
	char **file = NULL;
	FILE *stream = NULL;

	if ((stream = fopen(name, "r")) == NULL) {
		my_putstr("Error loading file\n");
		return (NULL);
	}
	if ((file = malloc_tab(stream, info)) == NULL) {
		my_putstr("Error loading file\n");
		fclose(stream);
		return (NULL);
	}
	fclose(stream);
	if (info->w != 14 || info->h != 40 || check_file(file) == -1) {
		my_putstr("Invalid map file\n");
		return (NULL);
	}
	return (convert_map(file, info));
}
