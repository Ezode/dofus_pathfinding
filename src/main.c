/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** Main function of the My RPG project
*/

#include <stdlib.h>
#include "my_rpg.h"

int my_strcmp(const char *s1, const char *s2)
{
	int i = 0;

	while (s1[i] == s2[i]) {
		if (s1[i] == '\0')
			return (0);
		i++;
	}
	if (s1[i] > s2[i])
		return (1);
	else if (s1[i] < s2[i])
		return (-1);
	return (0);
}

int check_line(char *line, char *name)
{
	int i = 0;

	while (line[i] != '=') {
		if (line[i] == '\0')
			return (0);
		if (line[i] != name[i])
			return (0);
		i++;
	}
	if (line[i + 1] == ':' && line[i + 2] == '0')
		return (1);
	return (0);
}

int check_env(char **env)
{
	int i = 0;

	while (env[i] != NULL) {
		if (check_line(env[i], "DISPLAY") == 1)
			return (0);
		i++;
	}
	return (1);
}

int lauch_screen(sfRenderWindow *win)
{
	sfTexture *screen = NULL;
	sfSprite *sprite = NULL;

	if (!(screen = sfTexture_createFromFile("sprite/lauch_screen.jpg", 0)))
		return (-1);
	if (!(sprite = sfSprite_create()))
		return (-1);
	sfSprite_setTexture(sprite, screen, 0);
	sfRenderWindow_clear(win, sfBlack);
	sfRenderWindow_drawSprite(win, sprite, NULL);
	sfRenderWindow_display(win);
	return (0);
}

int main(int argc, char **argv, char **envp)
{
	sfRenderWindow *win = NULL;
	sfVideoMode mode = {1920, 1080, 32};

	if (check_env(envp) != 0)
		return (84);
	if (!(win = sfRenderWindow_create(mode, APP_NAME, sfFullscreen, NULL)))
		return (84);
	sfRenderWindow_setFramerateLimit(win, 60);
	sfRenderWindow_setKeyRepeatEnabled(win, 0);
	if (lauch_screen(win) == -1)
		return (84);
	if (game_loop(win) == -1)
		return (84);
	return (0);
}
