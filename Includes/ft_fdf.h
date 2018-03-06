#ifndef FT_FDF_H

#include "../minilibx_macos/mlx.h"
#include "../libft/libft.h"
#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

# define FT_FDF_H
# define WIN_X 840
# define WIN_Y 840
# define BLUE 0xFF0000
# define GREEN 0x00FF00
# define RED 0x0000FF
# define WHITE 0xFFFFFF
# define BLUE_HGT -10.0
# define GREEN_HGT 0.0
# define RED_HGT 10.0
# define WHITE_HGT 100.0

typedef struct	s_coord
{
	int		x;
	int		y;
	int		z;
    int     X_proj;
    int     Y_proj;
    int     colour;
}				t_coord;

typedef struct	s_double_coord
{
	double		x;
	double		y;
	double		z;
    double		X_proj;
    double		Y_proj;
}				t_double_coord;

typedef struct	s_param
{
	int		x_rotation;
	int		y_rotation;
	int		z_rotation;
	int		applied_transfo;
	double	para_cte;
    double	iso_cte1;
    double	iso_cte2;
	double	manual_total_scale;
	double	manual_z_scale;
    int		win_x;
	int		win_y;
	int		colour_mode;
	double	blue_hgt;
	double	green_hgt;
	double	red_hgt;
	double	white_hgt;
}				t_param;


typedef struct	s_XY_info
{
	double		X_max;
	double		X_min;
	double		X_width;
    double		Y_max;
    double		Y_min;
    double		Y_width;
	double		z_min;
	double		z_max;
}				t_XY_info;

typedef struct	s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*img_addr;
	int				bit_pxl;
	int				size_line;
	int				endian;
	int				**tab;
	int				x_size;
	int				y_size;
	t_XY_info		XY_info;
	t_coord			*coord_tab;
	t_double_coord	*double_coord_tab;
	double			scale;
	t_double_coord	origin;
	t_param			param;
	int				previous_key;
	t_coord			point0;
	t_coord			point1;
	int				flag;
}					t_env;


int		ft_error();
//retourne 1 et ecrit qqc sur sortie d'erreur (peut aussi eventuellement prendre param si on ecrit plusieurs choses


void	ft_show_tab(int **tab, int x_size, int y_size);
void	ft_show_coord_tab(t_coord *coord_tab, int x_size, int y_size);
void	ft_show_double_coord_tab(t_double_coord *double_coord_tab, int x_size, int y_size);

int		**get_table(int fd, t_env *env_ptr);
//ac GNL et split remplit un tableau (en checkant erreurs) a voir si on finit chaque linge par 0 (fait partie du split? )

t_coord		*get_coord_table(t_env env);
//tableau de coord plus simple a traiter.

void	free_tab(int **tab, int tab_lines);
//free toutes les lignes de tab jusqu a tablines a voir si on balance la size de tab ou pasi

int		ft_mlx_tab_treat(t_env env);

void    ft_double_transfo(t_env *env_ptr);
t_double_coord		*ft_rotation(t_double_coord *initial, t_double_coord *origin, char c, int angle);


int     ft_colour(t_env env, int x, int y, t_coord point0, t_coord point1);
void	draw_lines(t_env env, int x1, int y1, int z1, int x2, int y2, int z2);
void	draw(t_env *env_ptr);

void	ft_init_env(t_env *env_ptr);
void	ft_init_param(t_param *param);
void	ft_rotate(t_env *env_ptr);
void	ft_scale(t_env *env_ptr);
void	ft_scale_apply(t_env *env_ptr);
void	ft_manipulate_data(t_env *env_ptr);

void	ft_previous_key(int k, t_env *env_ptr);
void	ft_keycode_plus(t_env *env_ptr);
void	ft_keycode_minus(t_env *env_ptr);
void	ft_reset(t_env *env_ptr);

int		ft_mlx_win_treat(t_env env);
int		expose_hook(t_env *env_ptr);
void	mlx_put_pxl_to_img(t_env env, int x, int y, int colour);
double	ft_2D_distance(int x0, int y0, int x1, int y1);
void	plot_line (t_env env, t_coord point0, t_coord point1);
void	ft_height_min_max(t_env *env_ptr);

#endif
