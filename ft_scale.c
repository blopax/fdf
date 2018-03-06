/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scale.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 18:41:07 by pclement          #+#    #+#             */
/*   Updated: 2018/03/06 18:53:17 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/ft_fdf.h"

void	ft_x_proj_width(t_env *env_ptr)
{
	double	x_proj_max;
	double	x_proj_min;
	int		i;
	int		size;

	x_proj_max = env_ptr->double_coord_tab[0].x_proj;
	x_proj_min = env_ptr->coord_tab[0].x_proj;
	size = env_ptr->x_size * env_ptr->y_size;
	i = 0;
	while (i < env_ptr->x_size * env_ptr->y_size)
	{
		if (x_proj_max < env_ptr->double_coord_tab[i].x_proj)
			x_proj_max = env_ptr->double_coord_tab[i].x_proj;
		if (x_proj_min > env_ptr->double_coord_tab[i].x_proj)
			x_proj_min = env_ptr->double_coord_tab[i].x_proj;
		i++;
	}
	env_ptr->xy_info.x_proj_max = x_proj_max;
	env_ptr->xy_info.x_proj_min = x_proj_min;
	env_ptr->xy_info.x_proj_width = x_proj_max - x_proj_min;
}

void	ft_y_proj_width(t_env *env_ptr)
{
	double	y_proj_max;
	double	y_proj_min;
	int		i;
	int		size;

	y_proj_max = env_ptr->double_coord_tab[0].y_proj;
	y_proj_min = env_ptr->double_coord_tab[0].y_proj;
	i = 0;
	size = env_ptr->x_size * env_ptr->y_size;
	while (i < env_ptr->x_size * env_ptr->y_size)
	{
		if (y_proj_max < env_ptr->double_coord_tab[i].y_proj)
			y_proj_max = env_ptr->double_coord_tab[i].y_proj;
		if (y_proj_min > env_ptr->double_coord_tab[i].y_proj)
			y_proj_min = env_ptr->double_coord_tab[i].y_proj;
		i++;
	}
	env_ptr->xy_info.y_proj_max = y_proj_max;
	env_ptr->xy_info.y_proj_min = y_proj_min;
	env_ptr->xy_info.y_proj_width = y_proj_max - y_proj_min;
}

void	ft_scale(t_env *env_ptr)
{
	double	x_proj_width;
	double	y_proj_width;
	double	scale_coef;
	int		win_x;
	int		win_y;

	ft_x_proj_width(env_ptr);
	ft_y_proj_width(env_ptr);
	x_proj_width = env_ptr->xy_info.x_proj_width;
	y_proj_width = env_ptr->xy_info.y_proj_width;
	scale_coef = env_ptr->param.manual_total_scale;
	win_x = env_ptr->param.win_x;
	win_y = env_ptr->param.win_y;
	if (x_proj_width == 0 && y_proj_width == 0)
		env_ptr->scale = 1;
	else if (x_proj_width == 0)
		env_ptr->scale = (double)win_y / (double)(y_proj_width) * scale_coef;
	else if (y_proj_width == 0)
		env_ptr->scale = (double)win_x / (double)(x_proj_width) * scale_coef;
	else if (win_x / x_proj_width < win_y / y_proj_width)
		env_ptr->scale = (double)win_x / (double)(x_proj_width) * scale_coef;
	else
		env_ptr->scale = (double)win_y / (double)(y_proj_width) * scale_coef;
}

void	ft_scale_apply(t_env *env_ptr)
{
	int		i;
	double	x_proj_width;
	double	y_proj_width;
	int		win_x;
	int		win_y;

	ft_scale(env_ptr);
	x_proj_width = env_ptr->xy_info.x_proj_width * env_ptr->scale;
	y_proj_width = env_ptr->xy_info.y_proj_width * env_ptr->scale;
	win_x = env_ptr->param.win_x;
	win_y = env_ptr->param.win_y;
	i = 0;
	while (i < env_ptr->x_size * env_ptr->y_size)
	{
		env_ptr->double_coord_tab[i].x_proj = -env_ptr->xy_info.x_proj_min *
			env_ptr->scale + (win_x - x_proj_width) / 2.0 +
			(env_ptr->double_coord_tab[i].x_proj) * env_ptr->scale;
		env_ptr->double_coord_tab[i].y_proj = -env_ptr->xy_info.y_proj_min *
			env_ptr->scale + (win_y - y_proj_width) / 2.0 +
			(env_ptr->double_coord_tab[i].y_proj) * env_ptr->scale;
		i++;
	}
}
