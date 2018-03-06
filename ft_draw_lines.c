#include "Includes/ft_fdf.h"

int     max(int a, int b)
{
	if (a <= b)
		return (b);
	else
		return (a);
}

int     min(int a, int b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

void	ft_height_min_max(t_env *env_ptr)
{
	int		i;

	i = 0;
	env_ptr->XY_info.z_min = env_ptr->double_coord_tab[i].z;
	env_ptr->XY_info.z_max = env_ptr->double_coord_tab[i].z;
/*	ft_putnbr(env_ptr->XY_info.z_min);
	ft_putstr(" / ");
	ft_putnbr(env_ptr->XY_info.z_max);
	ft_putstr("\n");*/
	while (i < env_ptr-> x_size * env_ptr->y_size)
	{
		if (env_ptr->double_coord_tab[i].z < env_ptr->XY_info.z_min)
			env_ptr->XY_info.z_min = env_ptr->double_coord_tab[i].z;
		if (env_ptr->double_coord_tab[i].z > env_ptr->XY_info.z_max)
			env_ptr->XY_info.z_max = env_ptr->double_coord_tab[i].z;
		i++;
	}
	if (env_ptr->param.colour_mode <= 1)
	{
		env_ptr->param.blue_hgt = BLUE_HGT;
		env_ptr->param.green_hgt = GREEN_HGT;
		env_ptr->param.red_hgt = RED_HGT;
		env_ptr->param.white_hgt = WHITE_HGT;
	}
	else if (env_ptr->param.colour_mode == 2)
	{
			env_ptr->param.blue_hgt = env_ptr->XY_info.z_min;
			env_ptr->param.green_hgt = env_ptr->XY_info.z_min + (env_ptr->XY_info.z_max - env_ptr->XY_info.z_min) / 3.0;
			env_ptr->param.red_hgt = env_ptr->XY_info.z_min + 2.0 * (env_ptr->XY_info.z_max - env_ptr->XY_info.z_min) / 3.0;
			env_ptr->param.white_hgt = env_ptr->XY_info.z_max;
	}
}

double	ft_height(int x, int y,  t_coord point0, t_coord point1)
{
	double	distance_proportion;

	if (point0.X_proj == point1.X_proj && point0.Y_proj == point1.Y_proj)
		return (point0.z);
	else
	{
		if (ft_2D_distance(point0.X_proj, point0.Y_proj, point1.X_proj, point1.Y_proj) == 0)
			distance_proportion = 1.0;
		else
			distance_proportion =(double)ft_2D_distance(point0.X_proj, point0.Y_proj, x, y) / (double)ft_2D_distance(point0.X_proj, point0.Y_proj, point1.X_proj, point1.Y_proj);
	}
	return((double)point0.z + (double)(distance_proportion * (double)(point1.z - point0.z)));
}

int		ft_colour(t_env env, int x, int y, t_coord point0, t_coord point1)
{
	double z;
	int colour;

	ft_height_min_max(&env);
	z = ft_height(x, y, point0, point1);
	if (env.param.colour_mode == 0 || (env.param.colour_mode == 1 && env.XY_info.z_max == env.XY_info.z_min))
		return (WHITE);
	colour = (int)(BLUE * (1 - min(max((z - env.param.blue_hgt)/(env.param.green_hgt - env.param.blue_hgt), 0), 1)) + GREEN * (1 - min(max((z - env.param.green_hgt)/(env.param.blue_hgt - env.param.green_hgt), 0), 1) -  min(max((z - env.param.green_hgt)/(env.param.red_hgt - env.param.green_hgt), 0), 1))+ RED * (1 - min(max((z - env.param.red_hgt)/(env.param.green_hgt - env.param.red_hgt), 0), 1) -  min(max((z - env.param.red_hgt)/(env.param.white_hgt - env.param.red_hgt), 0), 1))+ WHITE * (1 - min(max((z - env.param.white_hgt)/(env.param.red_hgt - env.param.white_hgt), 0), 1)));
	return (colour);
}

void	mlx_put_pxl_to_img(t_env env, int x, int y, int colour)
{
	int		r;

	if (y >= 0 && y < env.param.win_y && x >= 0 && x < env.param.win_x)
	{
		r = ((y * env.param.win_x + x)* 4);
		env.img_addr[r] = colour / (256 * 256) % 256;
		env.img_addr[r + 1] = (colour / 256) % 256;
		env.img_addr[r + 2] = colour % 256;
		env.img_addr[r + 3] = 0;
	}
}

void	plot_line (t_env env, t_coord point0, t_coord point1)
{
	int x, y, dx, dy, sx, sy, err, e2;

	x = point0.X_proj;
	y = point0.Y_proj;
	dx =  abs (point1.X_proj - x);
	sx = x < point1.X_proj ? 1 : -1;
	dy = -abs (point1.Y_proj - y);
	sy = y < point1.Y_proj ? 1 : -1;
	err = dx + dy;

//	mlx_pixel_put(env.mlx, env.win, x, y, 0XFFFFFF);
	mlx_put_pxl_to_img(env, x, y, ft_colour(env, x, y, point0, point1));
	while (x != point1.X_proj || y != point1.Y_proj) 
	{  
		mlx_put_pxl_to_img(env, x, y, ft_colour(env, x, y, point0, point1));
//	mlx_pixel_put(env.mlx, env.win, x, y, 0XFFFFFF);
		e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			x += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			y += sy;
		}
	}
}

void	draw(t_env *env_ptr)
{
	int     i;

	i = 0;
	while (i < env_ptr->x_size * env_ptr->y_size)
	{
		if ((i % env_ptr->x_size) + 1 < env_ptr->x_size)
			plot_line(*env_ptr, env_ptr->coord_tab[i], env_ptr->coord_tab[i + 1]);
		if ((i / env_ptr->x_size) + 1 < env_ptr->y_size)
			plot_line(*env_ptr, env_ptr->coord_tab[i], env_ptr->coord_tab[i + env_ptr->x_size]);
		i++;
	}
}
