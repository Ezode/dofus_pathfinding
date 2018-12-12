/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** display functions
*/

#include "my_rpg.h"

void disp_player(sfRenderWindow *win, t_player *p, t_anim *anim)
{
	sfVector2f pos_p = {p->cur.x + 45, p->cur.y - 130};

	sfSprite_setPosition(p->sprite[p->way][anim->p_num], pos_p);
	sfRenderWindow_drawSprite(win, p->sprite[p->way][anim->p_num], NULL);
}

int disp_win(sfRenderWindow *win, t_game *game, t_player *player, t_anim *anim)
{
	sfRenderWindow_clear(win, sfBlack);
	sfRenderWindow_drawSprite(win, game->sp_map, NULL);
	if (game->grid == 1) {
		if (draw_map(win, game) != 0)
			return (-1);
	}
	disp_player(win, player, anim);
	sfRenderWindow_display(win);
	game->display = 0;
	return (0);
}
