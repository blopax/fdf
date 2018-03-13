/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_lines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 19:02:48 by pclement          #+#    #+#             */
/*   Updated: 2018/03/13 16:05:00 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fdf.h"

double	ft_height(int x, int y, t_coord point0, t_coord point1)
{
	double	distance_proportion;

	if (point0.x_proj == point1.x_proj && point0.y_proj == point1.y_proj)
		return (point0.z);
	else
	{
		if (ft_2d_distance(point0.x_proj, point0.y_proj, point1.x_proj,
					point1.y_proj) == 0)
			distance_proportion = 1.0;
		else
			distance_proportion = (double)ft_2d_distance(point0.x_proj,
					point0.y_proj, x, y) / (double)ft_2d_distance(point0.x_proj,
						point0.y_proj, point1.x_proj, point1.y_proj);
	}
	return ((double)point0.z + (double)(distance_proportion *
				(double)(point1.z - point0.z)));
}

int		ft_colour(t_env env, int x, int y, t_coord point0, t_coord point1)
{
	double	z;
	int		colour;

	z = ft_height(x, y, point0, point1);
	if (env.param.colour_mode == 0 || (env.param.colour_mode == 1 &&
				env.xy_info.z_max == env.xy_info.z_min))
		return (WHITE);
	colour = (int)(BLUE * (1.0 - min(max((z - env.param.blue_hgt) /
						(env.param.green_hgt - env.param.blue_hgt), 0.0), 1.0))
			+ GREEN * (1.0 - min(max((z - env.param.green_hgt) /
						(env.param.blue_hgt - env.param.green_hgt), 0.0), 1.0) -
				min(max((z - env.param.green_hgt) / (env.param.red_hgt -
							env.param.green_hgt), 0.0), 1.0))
			+ RED * (1.0 - min(max((z - env.param.red_hgt) / (env.param.green_hgt
							- env.param.red_hgt), 0.0), 1.0) -
				min(max((z - env.param.red_hgt) / (env.param.white_hgt -
							env.param.red_hgt), 0.0), 1.0)) + WHITE * (1.0 -
					min(max((z - env.param.white_hgt) / (env.param.red_hgt
								- env.param.white_hgt), 0.0), 1.0)));
	return (colour);
}

void	mlx_put_pxl_to_img(t_env env, int x, int y, int colour)
{
	int		r;

	if (y >= 0 && y < env.param.win_y && x >= 0 && x < env.param.win_x)
	{
		r = ((y * env.param.win_x + x) * 4);
		env.img_addr[r] = colour / (256 * 256) % 256;
		env.img_addr[r + 1] = (colour / 256) % 256;
		env.img_addr[r + 2] = colour % 256;
		env.img_addr[r + 3] = 0;
	}
}

void	plot_line(t_env env, t_coord point0, t_coord point1)
{
	t_bresenheim bres_info;

	bres_info.x = point0.x_proj;
	bres_info.y = point0.y_proj;
	bres_info.dx = abs(point1.x_proj - bres_info.x);
	bres_info.sx = bres_info.x < point1.x_proj ? 1 : -1;
	bres_info.dy = -abs(point1.y_proj - bres_info.y);
	bres_info.sy = bres_info.y < point1.y_proj ? 1 : -1;
	bres_info.err = bres_info.dx + bres_info.dy;
	mlx_put_pxl_to_img(env, bres_info.x, bres_info.y, ft_colour(env, bres_info.x, bres_info.y, point0, point1));
	while (bres_info.x != point1.x_proj || bres_info.y != point1.y_proj)
	{
		mlx_put_pxl_to_img(env, bres_info.x, bres_info.y, ft_colour(env, bres_info.x, bres_info.y, point0, point1));
		bres_info.e2 = 2 * bres_info.err;
		if (bres_info.e2 >= bres_info.dy)
		{
			bres_info.err += bres_info.dy;
			bres_info.x += bres_info.sx;
		}
		if (bres_info.e2 <= bres_info.dx)
		{
			bres_info.err += bres_info.dx;
			bres_info.y += bres_info.sy;
		}
	}
}
//faire une structure bresenheim  x y dx dy sx sy err e2
// envoyer strucutre ds ft_colour
// Error (line 35): ft_colour have 5 parameters
// Error (line 50): line has 82 characters
// Error (line 73): bad spacing after plot_line
// Error (line 73, col 0): plot_line has 8 variables
// Error (line 75): multiple declarations
// Error (line 101): C++ comment
// Error (line 101): spaces at the end of line
// Error (line 102): C++ comment
// Error (line 102): spaces at the end of line

void	draw(t_env *env_ptr)
{
	int		i;

	i = 0;
	ft_height_min_max(env_ptr);
	while (i < env_ptr->x_size * env_ptr->y_size)
	{
		if ((i % env_ptr->x_size) + 1 < env_ptr->x_size)
			plot_line(*env_ptr, env_ptr->coord_tab[i],
					env_ptr->coord_tab[i + 1]);
		if ((i / env_ptr->x_size) + 1 < env_ptr->y_size)
			plot_line(*env_ptr, env_ptr->coord_tab[i],
					env_ptr->coord_tab[i + env_ptr->x_size]);
		i++;
	}
}
