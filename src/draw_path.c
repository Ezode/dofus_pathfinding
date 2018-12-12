/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** path drawing functions
*/

#include "my_rpg.h"

void cmp_val(int x, int y, int **map, t_path *a)
{
	if (a->val == 0 || map[y][x] < a->val) {
		a->val = map[y][x];
		a->xcell = x;
		a->ycell = y;
	}
}

void check_val(int x, int y, int **map, t_path *a)
{
	if (x < a->w - 1 && map[y][x + 1] > 0)
		cmp_val(x + 1, y, map, a);
	if (x > 0 && map[y][x - 1] > 0)
		cmp_val(x - 1, y, map, a);
	if (y < a->h - 1 && map[y + 1][x] > 0)
		cmp_val(x, y + 1, map, a);
	if (y > 0 && map[y - 1][x] > 0)
		cmp_val(x, y - 1, map, a);
	if (x > 0 && y > 0 && map[y - 1][x - 1] > 0)
		cmp_val(x - 1, y - 1, map, a);
	if (x < a->w - 1 && y > 0 && map[y - 1][x + 1] > 0)
		cmp_val(x + 1, y - 1, map, a);
	if (x > 0 && y < a->h - 1 && map[y + 1][x - 1] > 0)
		cmp_val(x - 1, y + 1, map, a);
	if (x < a->w - 1 && y < a->h - 1 && map[y + 1][x + 1] > 0)
		cmp_val(x + 1, y + 1, map, a);
}

void draw_path(int x, int y, int **map, int **path, t_path *a)
{
	path[y][x] = a->num;
	if (map[y][x] == 1)
		return;
	a->num++;
	check_val(x, y, map, a);
	draw_path(a->xcell, a->ycell, map, path, a);
}
