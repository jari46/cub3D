#include "cub3d.h"
#include "mlx.h"
#include <math.h>
#include <stdio.h>
#include "../libft/libft.h"

int world_map[MAP_SIZE_Y][MAP_SIZE_X]=
{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

//int world_map[MAP_SIZE_Y][MAP_SIZE_X]=
//{
//	{1,1,1,1,1,1,1,1,1,1},
//	{1,0,0,0,0,0,0,0,0,1},
//	{1,0,0,0,0,0,0,0,0,1},
//	{1,0,0,0,0,0,0,0,0,1},
//	{1,0,0,0,0,0,0,0,0,1},
//	{1,0,0,0,0,0,0,0,0,1},
//	{1,0,0,0,0,0,0,0,0,1},
//	{1,0,0,0,0,0,0,0,0,1},
//	{1,0,0,0,0,0,0,0,0,1},
//	{1,1,1,1,1,1,1,1,1,1}
//};

int	set_pixel(t_img *pimg, int y, int x, t_color color);
int	update_ray_vector(const t_player_info *p_player, int width_idx, t_vector *p_ray);
void set_correct_wall_distance(t_game_info *p_game, t_wall_info *p_wall, t_vector *p_ray);
int	init_mlx_lib(t_mlx *pmin, t_img *pimg);
int	find_wall_distance(
		t_game_info *pgi,
		t_vector *pray,
		t_hit *phit,
		t_wall_info *p_wall
);
void fill_wall_slice(t_game_info *p_game, const t_vector *p_ray, const t_wall_info *p_wall, const int width_idx);

int	fill_wall_slice_pixel(t_img *p_img, int width_idx, double height)
{
	double	screen_wall_height;
	int		start_point;
	int		end_point;
	t_color	color;

	if (p_img == 0)
		return (-1);
	ft_memset(&color, 0, sizeof(t_color));
	color.green = 255;
	screen_wall_height = (double)(SCREEN_HEIGHT) / height;
	start_point = ((double)SCREEN_HEIGHT / 2) - (screen_wall_height / 2);
	if (start_point < 0)
		start_point = 0;
	end_point = ((double)SCREEN_HEIGHT / 2) + (screen_wall_height / 2);
	if (end_point > SCREEN_HEIGHT - 1)
		end_point = SCREEN_HEIGHT - 1;
	while (start_point <= end_point)
	{
		set_pixel(p_img, start_point, width_idx, color);
		start_point++;
	}
	return (0);
}

int	draw_screen(t_game_info *p_game)
{
	if (p_game == 0)
		return (-1);
	mlx_put_image_to_window(p_game->mlx.mlx_ptr,
		p_game->mlx.win_ptr, p_game->mlx.screen.img_ptr, 0, 0);
	return (0);
}

int	update_screen(t_game_info *p_game)
{
	t_vector		ray;
	t_wall_info		wall;
	int				width_idx;

	width_idx = 0;
	while (width_idx < SCREEN_WIDTH)
	{
		if (update_ray_vector(&(p_game->player), width_idx, &ray) < 0)
			return (-1);
		if (find_wall_distance(p_game, &ray, &wall.hit_side, &wall) < 0)
			return (-1);
		set_correct_wall_distance(p_game, &wall, &ray);
		//fill_wall_slice_pixel(&(p_game->mlx.screen), width_idx, wall.corrected_distance);
		fill_wall_slice(p_game, &ray, &wall, width_idx);
		width_idx++;
	}
	if (draw_screen(p_game) < 0)
		return (-1);
	return (0);
}

#define MOVE_SPEED 1

int	update_player(t_game_info *p_game)
{
	t_key_status	is_updated;

	is_updated = RELEASE;
	if (p_game->key.move_forward == PRESS)
	{
		p_game->player.pos.x += (p_game->player.dir.x * MOVE_SPEED);
		p_game->player.pos.y += (p_game->player.dir.y * MOVE_SPEED);
		is_updated = PRESS;
	}

	return (is_updated);
}

int	game_loop(void *param)
{
	t_game_info		*p_game;
	t_key_status	is_updated;

	p_game = param;
	is_updated = update_player(p_game);
	if (is_updated == PRESS)
	{
		update_screen(p_game);
	}
	return (0);
}


int	init_parse_info(t_parse_info *p_parse)
{
	t_color floor;
	t_color	ceiling;

	if (p_parse == 0)
		return (-1);
	ft_memset(p_parse, 0, sizeof(t_parse_info));
	ft_memset(&floor, 0, sizeof(t_color));
	ft_memset(&ceiling, 0, sizeof(t_color));
	floor.blue = 100;
	ceiling.green = 100;
	p_parse->floor = floor;
	p_parse->ceiling = ceiling;


	p_parse->map = (int **)world_map;
	return (0);
}

int	init_player_info(t_player_info *p_player)
{
	if (p_player == 0)
		return (-1);
	p_player->dir.x = PLAYER_DIR_X;
	p_player->dir.y = PLAYER_DIR_Y;
	p_player->pos.x = PLAYER_POS_X;
	p_player->pos.y = PLAYER_POS_Y;
	p_player->view.x = 1;
	p_player->view.y = 0;
	return (0);
}

#include <stdio.h>

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_EXIT					17
int	key_press(int keycode, t_game_info *p_game);
int	key_release(int keycode, t_game_info *p_game);


int main()
{
	t_game_info	game;

	if (init_parse_info(&game.parse) < 0)
		return (1);
	if (init_player_info(&game.player) < 0)
		return (1);
	if (init_mlx_lib(&game.mlx, &game.mlx.screen) < 0)
		return (1);

	mlx_hook(game.mlx.win_ptr, X_EVENT_KEY_PRESS, 0, &key_press, &game);
	mlx_hook(game.mlx.win_ptr, X_EVENT_KEY_RELEASE, 0, &key_release, &game);
	//mlx_hook(game.mlx.win_ptr, X_EVENT_EXIT, 0, &exit, &game);
	mlx_loop_hook(game.mlx.mlx_ptr, game_loop, &game);
	mlx_loop(game.mlx.mlx_ptr);	
	return (0);
}
