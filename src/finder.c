/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** pathfinding algo functions
*/

#include "my_rpg.h"

void get_dist(int xA, int yA, t_path *a, int cost)
{
	int x = a->xB - xA;
	int y = a->yB - yA;
	int dist = 0;

	if (x < 0)
		x = x * (-1);
	if (y < 0)
		y = y * (-1);
	dist = x + y + cost;
	if (a->dist == -1 || dist < a->dist) {
		a->dist = dist;
		a->dist = dist;
		a->xcell = xA;
		a->ycell = yA;
	}
}

void get_short_dist(int **map, int x, int y, t_path *a)
{
	if (x < a->w - 1 && map[y][x + 1] == 0)
		get_dist(x + 1, y, a, 10);
	if (x > 0 && map[y][x - 1] == 0)
		get_dist(x - 1, y, a, 10);
	if (y < a->h - 1 && map[y + 1][x] == 0)
		get_dist(x, y + 1, a, 10);
	if (y > 0 && map[y - 1][x] == 0)
		get_dist(x, y - 1, a, 10);
	if (x > 0 && y > 0 && map[y - 1][x - 1] == 0)
		get_dist(x - 1, y - 1, a, 14);
	if (x < a->w - 1 && y > 0 && map[y - 1][x + 1] == 0)
		get_dist(x + 1, y - 1, a, 14);
	if (x > 0 && y < a->h - 1 && map[y + 1][x - 1] == 0)
		get_dist(x - 1, y + 1, a, 14);
	if (x < a->w - 1 && y < a->h - 1 && map[y + 1][x + 1] == 0)
		get_dist(x + 1, y + 1, a, 14);
}

int check_around(int **map, int x, int y, t_path *a)
{
	if (x < a->w - 1 && map[y][x + 1] == 0)
		return (1);
	if (x > 0 && map[y][x - 1] == 0)
		return (1);
	if (y < a->h - 1 && map[y + 1][x] == 0)
		return (1);
	if (y > 0 && map[y - 1][x] == 0)
		return (1);
	if (x > 0 && y > 0 && map[y - 1][x - 1] == 0)
		return (1);
	if (x < a->w - 1 && y > 0 && map[y - 1][x + 1] == 0)
		return (1);
	if (x > 0 && y < a->h - 1 && map[y + 1][x - 1] == 0)
		return (1);
	if (x < a->w - 1 && y < a->h - 1 && map[y + 1][x + 1] == 0)
		return (1);
	return (0);
}

int finder(int **map, int x, int y, t_path *a)
{
	do {
		if (x == a->xB && y == a->yB) {
			map[y][x] = a->num;
			return (1);
		}
		get_short_dist(map, x, y, a);
		if (a->dist == -1) {
			map[y][x] = a->num;
			a->num--;
			return (0);
		}
		a->dist = -1;
		map[y][x] = a->num;
		a->num += 1;
		if (finder(map, a->xcell, a->ycell, a) == 1)
			return (1);
	} while (check_around(map, x, y, a) == 1);
	a->num--;
	return (0);
}
