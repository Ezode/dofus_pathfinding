/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** pathfinding functions
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my_rpg.h"

void reset_map(int **map)
{
	int i = 0;
	int j = 0;

	while (i != 40) {
		while (j != 14) {
			map[i][j] = 0;
			j++;
		}
		j = 0;
		i++;
	}
}

int **cpy_map(int **map, t_path *info)
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
			if (map[i][j] != 0)
				copy[i][j] = -1;
			else
				copy[i][j] = map[i][j];
	}
	return (copy);
}

int pathfinding(t_game *game, t_player *player, t_path *info)
{
	int **map = NULL;

	info->dist = -1;
	info->num = 1;
	info->val = 0;
	if ((map = cpy_map(game->map, info)) == NULL)
		return (-1);
	if (finder(map, player->x, player->y, info) == 1) {
		info->num = 1;
		reset_map(game->path);
		draw_path(info->xB, info->yB, map, game->path, info);
	}
	return (0);
}
