/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** game init functions
*/

#include <stdlib.h>
#include "my_rpg.h"

int malloc_sprite(t_player *player)
{
	int i = 0;

	if (!(player->sprite = malloc(sizeof(sfSprite**) * 5)))
		return (-1);
	while (i != 5) {
		if (!(player->sprite[i] = malloc(sizeof(sfSprite*) * 15)))
			return (-1);
		i++;
	}
	return (0);
}

int load_player_sprite(t_player *player)
{
	char *path = "sprite/iop_sheet.png";
	sfTexture *texture = NULL;
	sfIntRect area = {0, 0, 260, 260};

	if (malloc_sprite(player) == -1)
		return (-1);
	for (int i = 0; i != 5; i += 1, area.left = 0, area.top += 260) {
		for (int j = 0; j != 15; j+= 1, area.left += 260) {
			if (!(texture = sfTexture_createFromFile(path, &area)))
				return (-1);
			if (!(player->sprite[i][j] = sfSprite_create()))
				return (-1);
			sfSprite_setTexture(player->sprite[i][j], texture, 0);
			sfSprite_setOrigin(player->sprite[i][j], \
					(sfVector2f){130, 0});
		}
	}
	return (0);
}

int **malloc_path(void)
{
	int i = 0;
	int **path = NULL;

	if ((path = malloc(sizeof(int*) * 40)) == NULL)
		return (NULL);
	while (i != 40) {
		if ((path[i] = malloc(sizeof(int) * 14)) == NULL)
			return (NULL);
		i++;
	}
	return (path);
}

int init_player(t_game *game, t_player *player)
{
	sfVector2f *tile = get_tile(1, 0, game);

	if (tile == NULL)
		return (-1);
	player->cur.x = (int)tile[2].x;
	player->cur.y = (int)tile[3].y;
	player->new.x = player->cur.x;
	player->new.y = player->cur.y;
	if (!(player->cmove = sfClock_create()))
		return (-1);
	return (0);
}

int load_map_sprite(t_game *game)
{
	sfTexture *texture = NULL;

	if (!(texture = sfTexture_createFromFile("sprite/map.png", 0)))
		return (-1);
	if (!(game->sp_map = sfSprite_create()))
		return (-1);
	sfSprite_setTexture(game->sp_map, texture, 0);
	sfSprite_setPosition(game->sp_map, (sfVector2f){0, 0});
	return (0);
}

int init_game(t_game *game, t_player *player, t_path *path, t_anim *anim)
{
	sfVector2f *tile = get_tile(0, 0, game);

	if (tile == NULL)
		return (-1);
	game->shiftx = tile[1].x - tile[2].x;
	game->shifty = tile[0].y - tile[3].y;
	if (init_player(game, player) != 0)
		return (-1);
	if (!(game->map = load_map("map", path)))
		return (-1);
	if (!(game->path = malloc_path()))
		return (-1);
	reset_map(game->path);
	if (load_player_sprite(player) == -1)
		return (-1);
	anim->p_anim = sfClock_create();
	if (load_map_sprite(game) == -1)
		return (-1);
	return (0);
}
