/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** map rendering functions
*/

#include <stdlib.h>
#include <math.h>
#include "my_rpg.h"

sfVector2f iso_pnt(int x, int y)
{
	sfVector2f point2d = {0};

	point2d.x = COS * x - COS * y;
	point2d.y = SIN * y + SIN * x;
	return (point2d);
}

sfVector2f *get_tile(int x, int y, t_game *g)
{
	int i = 0;
	int j = 0;
	int k = 0;
	sfVector2f *t = NULL;

	if ((t = malloc(sizeof(sfVector2f) * 4)) == NULL)
		return (NULL);
	for (j = 0; j != 2; j++) {
		for (i = 0; i != 2; i += 1, k += 1) {
			t[k] = iso_pnt(i * SCAL_X, j * SCAL_Y);
			t[k].x += g->win_size.x / 2 - \
				(g->shiftx * 7 + g->shiftx / 4) + \
				(g->shiftx / 2 + x * g->shiftx + \
				(y % 2) * g->shiftx / 2);
			t[k].y += g->shifty + y * g->shifty / 2;
		}
	}
	return (t);
}

sfVertexArray *create_tile(sfVector2f *tile, sfPrimitiveType type)
{
	sfVertexArray *v_array = sfVertexArray_create();
	sfVertex vertex1 = {.position = tile[0], .color = sfWhite};
	sfVertex vertex2 = {.position = tile[1], .color = sfWhite};
	sfVertex vertex3 = {.position = tile[3], .color = sfWhite};
	sfVertex vertex4 = {.position = tile[2], .color = sfWhite};
	sfVertex vertex5 = {.position = tile[0], .color = sfWhite};

	if (v_array == NULL)
		return (NULL);
	sfVertexArray_append(v_array, vertex1);
	sfVertexArray_append(v_array, vertex2);
	sfVertexArray_append(v_array, vertex3);
	sfVertexArray_append(v_array, vertex4);
	sfVertexArray_append(v_array, vertex5);
	sfVertexArray_setPrimitiveType(v_array, type);
	return (v_array);
}

int draw_tile(sfRenderWindow *win, t_game *game, int i, int j)
{
	sfVector2f *tile = NULL;
	sfVertexArray *v_array = NULL;
	sfPrimitiveType type;

	if (game->map[j][i] == 0)
		type = sfLinesStrip;
	else
		type = sfQuads;
	if ((tile = get_tile(i, j, game)) == NULL)
		return (-1);
	if ((v_array = create_tile(tile, type)) == NULL)
		return (-1);
	sfRenderWindow_drawVertexArray(win, v_array, NULL);
	return (0);
}

int draw_map(sfRenderWindow *win, t_game *game)
{
	int i = 0;
	int j = 0;
	int ret = 0;

	for (j = 0; j != MAP_Y && ret == 0; j++) {
		for (i = 0; i != MAP_X && ret == 0; i++) {
			ret = draw_tile(win, game, i, j);
		}
	}
	return (ret);
}
