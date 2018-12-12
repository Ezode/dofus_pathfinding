/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** player move functions
*/

#include "my_rpg.h"

void move_player_x(t_player *player)
{
	float pix = 4;

	if (player->cur.x < player->new.x) {
		check_scale(player, RIGHT);
		if (player->cur.x + pix > player->new.x)
			player->cur.x = player->new.x;
		else
			player->cur.x += pix;
	}
	else {
		check_scale(player, LEFT);
		if (player->cur.x - pix < player->new.x)
			player->cur.x = player->new.x;
		else
			player->cur.x -= pix;
	}
}

int move_player_y(t_player *player)
{
	float pix = 2.2;

	if (player->cur.y < player->new.y) {
		if (player->cur.y + pix > player->new.y)
			player->cur.y = player->new.y;
		else
			player->cur.y += pix;
		return (1);
	}
	else {
		if (player->cur.y - pix < player->new.y)
			player->cur.y = player->new.y;
		else
			player->cur.y -= pix;
		return (2);
	}
}

void move_player_diag(t_player *p)
{
	move_player_x(p);
	if (move_player_y(p) == 1)
		p->way = DIAG_F;
	else
		p->way = DIAG_B;
}

void move_player_axis(t_player *p)
{
	if (p->cur.x != p->new.x) {
		move_player_x(p);
		p->way = SIDE;
	}
	else {
		if (move_player_y(p) == 1)
			p->way = FACE;
		else
			p->way = BACK;
	}
}

void move_player(t_player *p)
{
	sfTime time = sfClock_getElapsedTime(p->cmove);

	if (time.microseconds >= 8000) {
		if (p->cur.x != p->new.x && p->cur.y != p->new.y)
			move_player_diag(p);
		else
			move_player_axis(p);
		sfClock_restart(p->cmove);
	}
}
