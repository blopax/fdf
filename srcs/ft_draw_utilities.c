/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_utilities.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 19:00:42 by pclement          #+#    #+#             */
/*   Updated: 2018/03/13 15:40:01 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fdf.h"

double		ft_2d_distance(int x0, int y0, int x1, int y1)
{
	return (sqrt((((double)ft_power_n(x1 - x0, 2) + ft_power_n(y1 - y0, 2)))));
}

double		max(double a, double b)
{
	if (a <= b)
		return (b);
	else
		return (a);
}

double		min(double a, double b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

void		ft_param_colour(t_env *env_ptr)
{
	if (env_ptr->param.colour_mode <= 1)
	{
		env_ptr->param.blue_hgt = BLUE_HGT;
		env_ptr->param.green_hgt = GREEN_HGT;
		env_ptr->param.red_hgt = RED_HGT;
		env_ptr->param.white_hgt = WHITE_HGT;
	}
	else if (env_ptr->param.colour_mode == 2)
	{
		env_ptr->param.blue_hgt = env_ptr->xy_info.z_min;
		env_ptr->param.green_hgt = env_ptr->xy_info.z_min +
			(env_ptr->xy_info.z_max - env_ptr->xy_info.z_min) / 3.0;
		env_ptr->param.red_hgt = env_ptr->xy_info.z_min +
			2.0 * (env_ptr->xy_info.z_max - env_ptr->xy_info.z_min) / 3.0;
		env_ptr->param.white_hgt = env_ptr->xy_info.z_max;
	}
}

void		ft_height_min_max(t_env *env_ptr)
{
	int		i;

	i = 0;
	env_ptr->xy_info.z_min = env_ptr->double_coord_tab[i].z;
	env_ptr->xy_info.z_max = env_ptr->double_coord_tab[i].z;
	while (i < env_ptr->x_size * env_ptr->y_size)
	{
		if (env_ptr->double_coord_tab[i].z < env_ptr->xy_info.z_min)
			env_ptr->xy_info.z_min = env_ptr->double_coord_tab[i].z;
		if (env_ptr->double_coord_tab[i].z > env_ptr->xy_info.z_max)
			env_ptr->xy_info.z_max = env_ptr->double_coord_tab[i].z;
		i++;
	}
	ft_param_colour(env_ptr);
}
