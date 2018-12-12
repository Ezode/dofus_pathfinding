/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** check position functions
*/

#include "my_rpg.h"

int set_player_pos(t_game *game, t_player *player, int x, int y)
{
	int num = game->path[y][x] - 1;
	sfVector2f *tile = NULL;

	if (num > 0 && y < 39 && game->path[y + 1][x] == num)
		y += 1;
	else if (num > 0 && y > 0 && game->path[y - 1][x] == num)
		y -= 1;
	if (!(tile = get_tile(x, y, game)))
		return (-1);
	player->new.x = (int)tile[2].x;
	player->new.y = (int)tile[3].y;
	player->x = x;
	player->y = y;
	return (1);
}

int check_side_pos(int x, int y, t_game *game, t_player *player)
{
	int num = game->path[y][x];

	if (x < 13 && game->path[y][x + 1] == num - 1)
		return (set_player_pos(game, player, x + 1, y));
	if (x > 0 && game->path[y][x - 1] == num - 1)
		return (set_player_pos(game, player, x - 1, y));
	if (y < 39 && game->path[y + 1][x] == num - 1)
		return (set_player_pos(game, player, x, y + 1));
	if (y > 0 && game->path[y - 1][x] == num - 1)
		return (set_player_pos(game, player, x, y - 1));
	return (0);
}

int check_diag_pos(int x, int y, t_game *game, t_player *player)
{
	int num = game->path[y][x];

	if (x > 0 && y > 0 && game->path[y - 1][x - 1] == num - 1)
		return (set_player_pos(game, player, x - 1, y - 1));
	if (x < 13 && y > 0 && game->path[y - 1][x + 1] == num - 1)
		return (set_player_pos(game, player, x + 1, y - 1));
	if (x > 0 && y < 39 && game->path[y + 1][x - 1] == num - 1)
		return (set_player_pos(game, player, x - 1, y + 1));
	if (x < 13 && y < 39 && game->path[y + 1][x + 1] == num - 1)
		return (set_player_pos(game, player, x + 1, y + 1));
	return (0);
}

int check_next_pos(t_game *game, t_player *player, int x, int y)
{
	int ret = 0;
	int num = game->path[y][x];

	if (num == 1) {
		if (player->state == 1) {
			player->state = 0;
			game->display = 1;
		}
		return (0);
	}
	ret = check_side_pos(x, y, game, player);
	if (ret == 0)
		ret = check_diag_pos(x, y, game, player);
	if (ret == -1)
		return (-1);
	return (0);
}

int check_player_move(t_game *game, t_player *player)
{
	if (player->cur.x == player->new.x && player->cur.y == player->new.y)
		return (check_next_pos(game, player, player->x, player->y));
	else {
		player->state = 1;
		move_player(player);
		game->display = 1;
	}
	return (0);
}
