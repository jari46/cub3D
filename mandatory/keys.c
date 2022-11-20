#include "cub3d.h"
#include <stdlib.h>

# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define KEY_LEFT		123
# define KEY_RIGHT	124
# define KEY_ESC		53

int	exit_game(t_game_info *p_game, int status)
{
	//메모리 할당 해제
	(void)p_game;
	exit(status);
	return (status);
}

int	exit_hook(t_game_info *game)
{
	return (exit_game(game, EXIT_SUCCESS));
}

int	key_press(int keycode, t_game_info *p_game)
{
	if (keycode == KEY_W)
		p_game->key.move_forward = PRESS;

	if (keycode == KEY_ESC)
		return (exit_game(p_game, EXIT_SUCCESS));

	return (0);
}

int	key_release(int keycode, t_game_info *p_game)
{
	if (keycode == KEY_W)
		p_game->key.move_forward = PRESS;

	if (keycode == KEY_ESC)
		return (exit_game(p_game, EXIT_SUCCESS));

	return (0);
}
