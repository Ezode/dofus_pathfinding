/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** sprite scale functions
*/

#include "my_rpg.h"

void invert_sprite(t_player *player, int scale)
{
	int i = 1;
	int j = 0;

	while (i != 4) {
		while (j != 15) {
			sfSprite_setScale(player->sprite[i][j], \
					(sfVector2f){scale, 1});
			j++;
		}
		j = 0;
		i++;
	}
}

void check_scale(t_player *player, int dir)
{
	if (player->dir != dir) {
		if (dir == RIGHT)
			invert_sprite(player, 1);
		else
			invert_sprite(player, -1);
	}
	player->dir = dir;
}
