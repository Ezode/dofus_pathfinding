/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** game functions
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "my_rpg.h"

void save_map(t_game *game)
{
	int i = 0;
	int j = 0;
	char buf[1];
	int fd = open("map_saved", O_WRONLY);

	if (fd == -1) {
		write(1, "Error saving the map\n", 21);
		return;
	}
	for (i = 0; i != 40; i++) {
		for (j = 0; j != 14; j++) {
			buf[0] = game->map[i][j] + 48;
			write(fd, buf, 1);
		}
		write(fd, "\n", 1);
	}
}

void grid_state(t_game *game)
{
	if (game->grid == 0)
		game->grid = 1;
	else
		game->grid = 0;
	game->display = 1;
}

int handle_event(sfRenderWindow *win, t_game *game, t_player *plyr, t_path *pth)
{
	sfEvent event;
	int click = 0;

	if (sfRenderWindow_pollEvent(win, &event) == sfTrue) {
		if (event.type == sfEvtMouseButtonPressed) {
			if (event.mouseButton.button == 0)
				click = 1;
			else if (event.mouseButton.button == 1)
				click = 0;
			check_mouse_click(event, game, plyr, pth, click);
		}
		else if (event.type == sfEvtKeyPressed) {
			if (event.key.code == sfKeyEscape)
				sfRenderWindow_close(win);
			else if (event.key.code == sfKeyS)
				save_map(game);
			if (event.key.code == sfKeyG)
				grid_state(game);
		}
	}
	return (0);
}

void check_anim(t_anim *anim, t_player *player)
{
	sfTime time = sfClock_getElapsedTime(anim->p_anim);

	if (player->state == 1) {
		if (time.microseconds >= 30000) {
			if (anim->p_num == 14)
				anim->p_num = 0;
			anim->p_num += 1;
			sfClock_restart(anim->p_anim);
		}
	}
	else if (anim->p_num != 0)
		anim->p_num = 0;
}

int check_scene(t_game *game, t_player *player, t_path *path)
{
//	if (player->x == 0) {
//		if ((game->map = load_map("map2", path)) == NULL)
//			return (-1);
//	}
	return (0);
}

int game_loop(sfRenderWindow *win)
{
	t_player player = {NULL, {0}, {0}, 1, 0, FACE, RIGHT, 0, NULL};
	t_game game = {0, 0, 0, 0, 0, 1, NULL, NULL, {0}, NULL};
	t_path path = {0, 0, 0, 0, 0, 0, -1, 1, 0};
	t_anim anim = {0, NULL};

	game.win_size = sfRenderWindow_getSize(win);
	if (init_game(&game, &player, &path, &anim) != 0)
		return (-1);
	while (sfRenderWindow_isOpen(win)) {
		handle_event(win, &game, &player, &path);
		if (check_player_move(&game, &player) == -1)
			return (-1);
		check_anim(&anim, &player);
		if (check_scene(&game, &player, &path) == -1)
			return (-1);
		if (game.display == 1)
			disp_win(win, &game, &player, &anim);
	}
	return (0);
}
