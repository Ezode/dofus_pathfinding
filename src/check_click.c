/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** check mouse click functions
*/

#include "my_rpg.h"

int check_click_is_inside(int x, int y, t_pos p)
{
	if (x < p.l.x || x > p.r.x || y > p.t.y || y < p.b.y)
		return (1);
	if (x <= p.b.x && y <= p.l.y)
		if ((y - p.b.y) * (p.b.x - p.l.x) < \
		    (p.l.y - p.b.y) * (p.b.x - x))
			return (1);
	if (x >= p.b.x && y <= p.r.y)
		if ((y - p.b.y) * (p.r.x - p.b.x) < \
		(p.r.y - p.b.y) * (x - p.b.x))
			return (1);
	if (x >= p.t.x && y >= p.r.y)
		if ((p.t.y - y) * (p.r.x - p.t.x) < \
		(p.t.y - p.r.y) * (x - p.t.x))
			return (1);
	if (x <= p.t.x && y >= p.l.y)
		if ((p.t.y - y) * (p.t.x - p.l.x) < \
		(p.t.y - p.l.y) * (p.t.x - x))
			return (1);
	return (0);
}

int check_tile(t_game *g, int i, int j)
{
	sfVector2f *tile = NULL;
	t_pos p;

	tile = get_tile(i, j, g);
	p.l = tile[2];
	p.r = tile[1];
	p.t = tile[0];
	p.b = tile[3];
	if (check_click_is_inside(g->mx, g->my, p) == 0)
		return (1);
	return (0);
}

int check_mouse_click(sfEvent event, t_game *game, t_player *player, t_path *p, int click)
{
	int i = 0;
	int j = 0;

	game->mx = event.mouseButton.x;
	game->my = event.mouseButton.y;
	for (i = 0; i != MAP_Y; i++) {
		for (j = 0; j != MAP_X; j++) {
			if (check_tile(game, j, i) == 1 \
			&& game->map[i][j] == 0) {
				p->xB = j;
				p->yB = i;
//				game->map[i][j] = click;
				pathfinding(game, player, p);
				return (1);
			}
		}
	}
	return (0);
}
