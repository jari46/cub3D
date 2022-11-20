#include "cub3d.h"
#include "mlx.h"

static int	init_mlx_window(t_mlx *p_mlx, t_img *p_screen)
{
	p_screen->img_ptr = mlx_new_image(p_mlx->mlx_ptr, SCREEN_WIDTH,
			SCREEN_HEIGHT);
	if (p_screen->img_ptr == 0)
	{
		mlx_destroy_window(p_mlx->mlx_ptr, p_mlx->win_ptr);
		return (FAIL);
	}
	p_screen->p_data = (unsigned int *)mlx_get_data_addr(p_mlx->screen.img_ptr, &p_screen->bpp,
			&p_screen->size_line, &p_screen->endian);
	if (p_screen->p_data == 0)
	{
		mlx_destroy_window(p_mlx->mlx_ptr, p_mlx->win_ptr);
		return (FAIL);
	}
	return (SUCCESS);
}

static int	init_mlx_texture_image(t_mlx *p_mlx, t_parse_info *p_parse)
{
	p_mlx->north_img.img_ptr = mlx_xpm_file_to_image(p_mlx->mlx_ptr, p_parse->path.arry[NORTH_IDX], &p_mlx->north_img.width,  &p_mlx->north_img.height);
	p_mlx->south_img.img_ptr = mlx_xpm_file_to_image(p_mlx->mlx_ptr, p_parse->path.arry[SOUTH_IDX], &p_mlx->south_img.width,  &p_mlx->south_img.height);
	p_mlx->east_img.img_ptr = mlx_xpm_file_to_image(p_mlx->mlx_ptr, p_parse->path.arry[EAST_IDX], &p_mlx->east_img.width,  &p_mlx->east_img.height);
	p_mlx->west_img.img_ptr = mlx_xpm_file_to_image(p_mlx->mlx_ptr, p_parse->path.arry[WEST_IDX], &p_mlx->west_img.width,  &p_mlx->west_img.height);
	if (p_mlx->north_img.img_ptr == 0 || p_mlx->south_img.img_ptr == 0 || p_mlx->north_img.img_ptr == 0 || p_mlx->south_img.img_ptr == 0)
			return (FAIL);

	p_mlx->north_img.p_data = (unsigned int *)mlx_get_data_addr(p_mlx->north_img.img_ptr, &(p_mlx->north_img.bpp), &(p_mlx->north_img.size_line), &(p_mlx->north_img.endian));
	p_mlx->south_img.p_data = (unsigned int *)mlx_get_data_addr(p_mlx->south_img.img_ptr, &(p_mlx->south_img.bpp), &(p_mlx->south_img.size_line), &(p_mlx->south_img.endian));
	p_mlx->east_img.p_data = (unsigned int *)mlx_get_data_addr(p_mlx->east_img.img_ptr, &(p_mlx->east_img.bpp), &(p_mlx->east_img.size_line), &(p_mlx->east_img.endian));
	p_mlx->west_img.p_data = (unsigned int *)mlx_get_data_addr(p_mlx->west_img.img_ptr, &(p_mlx->west_img.bpp), &(p_mlx->west_img.size_line), &(p_mlx->west_img.endian));
	return (SUCCESS);
}

int	init_mlx_info(t_mlx *p_mlx, t_img *p_screen, t_parse_info *p_parse)
{
	if (p_mlx == 0 || p_screen == 0)
		return (FAIL);
	p_mlx->mlx_ptr = mlx_init();
	if (p_mlx->mlx_ptr == 0)
		return (FAIL);
	p_mlx->win_ptr = mlx_new_window(p_mlx->mlx_ptr, SCREEN_WIDTH,
			SCREEN_HEIGHT, "cub3D");
	if (p_mlx->win_ptr == 0)
		return (FAIL);
	if (init_mlx_screen_image(p_mlx, p_screen) == FAIL)
		return (FAIL);
	if (init_mlx_texture_image(p_mlx, p_parse) == FAIL)
		return (FAIL);
	return (SUCCESS);
}

int	set_pixel(t_img *p_img, int y, int x, t_color color)
{
	if (p_img == 0)
		return (FAIL);
	*(p_img->p_data + (y * (p_img->size_line / (p_img->bpp / 8))) + x)
		= *(unsigned int *)&color;
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