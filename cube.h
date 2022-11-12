#ifndef CUBE_H
#define CUBE_H

#define PATH_MAX            128
#define SCREEN_WIDTH        640
#define SCREEN_HEIGHT       480

typedef struct s_RGB
{
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} t_RGB;

typedef struct s_map_info
{
    char    path_north_texture[PATH_MAX];
    char    path_south_texture[PATH_MAX];
    char    path_west_texture[PATH_MAX];
    char    path_east_texture[PATH_MAX];
    t_RGB   floor;
    t_RGB   ceil;
	int     **map;
} t_map_info;

typedef struct s_pos
{
	double	x;
	double y;
} t_pos;

typedef struct s_dir
{
	double	x;
	double	y;
} t_dir;

typedef struct s_view
{
	double x;
	double y;
} t_view;

typedef struct s_ray
{
	double x;
	double y;
} t_ray;

typedef struct s_map
{
	int	x;
	int	y;
} t_map;

typedef struct s_dda
{
    double  delta_dist_horizon;
    double  delta_dist_vertical;
    double  first_dist_horizon;
    double  first_dist_vertical;
    int     step_horizon;
    int     step_vertical;
    t_map   map;
} t_dda;

typedef struct s_vector
{
    t_pos   pos;
    t_dir   dir;
    t_view  view;
    t_ray   ray;
} t_vector;

#endif