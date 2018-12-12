/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** Header file of the My RPG project
*/

#ifndef MY_RPG
#define MY_RPG

#define MAP_X 14
#define MAP_Y 40
#define SCAL_X 90
#define SCAL_Y 90
#define COS cos(45)
#define SIN sin(34.85)
#define APP_NAME "My RPG"
#define FACE 0
#define DIAG_F 1
#define SIDE 2
#define DIAG_B 3
#define BACK 4
#define RIGHT 1
#define LEFT 2

#include <SFML/Graphics.h>

typedef struct s_path
{
	int xB;
	int yB;
	int w;
	int h;
	int xcell;
	int ycell;
	int dist;
	int num;
	int val;
}t_path;

typedef struct s_pos
{
	sfVector2f l;
	sfVector2f r;
	sfVector2f t;
	sfVector2f b;
}t_pos;

typedef struct s_player
{
	sfSprite ***sprite;
	sfVector2f cur;
	sfVector2f new;
	int x;
	int y;
	int way;
	int dir;
	int state;
	sfClock *cmove;
}t_player;

typedef struct s_game
{
	float shiftx;
	float shifty;
	int mx;
	int my;
	int grid;
	int display;
	int **map;
	int **path;
	sfVector2u win_size;
	sfSprite *sp_map;
}t_game;

typedef struct s_anim
{
	int p_num;
	sfClock *p_anim;
}t_anim;

char **my_realloc(char **array, char *str);
char *my_strdup(const char *src);
int my_strlen(const char *str);
int **load_map(char *name, t_path *path);
int pathfinding(t_game *game, t_player *player, t_path *info);
int finder(int **map, int x, int y, t_path *a);
void draw_path(int x, int y, int **map, int **path, t_path *a);
void reset_map(int **map);
int game_loop(sfRenderWindow *window);
int draw_map(sfRenderWindow *win, t_game *game);
sfVector2f *get_tile(int x, int y, t_game *g);
int check_mouse_click(sfEvent event, t_game *game, t_player *player, t_path *p, int click);
void move_player(t_player *p);
int check_player_move(t_game *game, t_player *player);
int init_game(t_game *game, t_player *player, t_path *path, t_anim *anim);
int disp_win(sfRenderWindow *win, t_game *game, t_player *player, t_anim *anim);
void check_scale(t_player *player, int dir);
int my_putstr(const char *str);

#endif
