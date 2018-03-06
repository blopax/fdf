/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotation_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 18:54:04 by pclement          #+#    #+#             */
/*   Updated: 2018/03/06 18:55:22 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/ft_fdf.h"

void	ft_rotate_x(t_env *env_ptr)
{
	int				i;
	int				size;
	double			theta;
	t_double_coord	coord_i;

	i = 0;
	theta = -(double)(env_ptr->param.x_rotation) / 180.0 * 3.141592;
	size = env_ptr->x_size * env_ptr->y_size;
	while (i < size)
	{
		coord_i.x = env_ptr->double_coord_tab[i].x - env_ptr->origin.x;
		coord_i.y = env_ptr->double_coord_tab[i].y - env_ptr->origin.y;
		coord_i.z = env_ptr->double_coord_tab[i].z - env_ptr->origin.z;
		env_ptr->double_coord_tab[i].y = coord_i.y * cos(theta) + coord_i.z *
			sin(theta) + env_ptr->origin.y;
		env_ptr->double_coord_tab[i].z = -coord_i.y * sin(theta) + coord_i.z *
			cos(theta) + env_ptr->origin.z;
		i++;
	}
}

void	ft_rotate_y(t_env *env_ptr)
{
	int				i;
	int				size;
	double			theta;
	t_double_coord	coord_i;

	i = 0;
	theta = -(double)(env_ptr->param.y_rotation) / 180.0 * 3.141592;
	size = env_ptr->x_size * env_ptr->y_size;
	while (i < size)
	{
		coord_i.x = env_ptr->double_coord_tab[i].x - env_ptr->origin.x;
		coord_i.y = env_ptr->double_coord_tab[i].y - env_ptr->origin.y;
		coord_i.z = env_ptr->double_coord_tab[i].z - env_ptr->origin.z;
		env_ptr->double_coord_tab[i].x = coord_i.x * cos(theta) - coord_i.z *
			sin(theta) + env_ptr->origin.x;
		env_ptr->double_coord_tab[i].z = coord_i.x * sin(theta) + coord_i.z *
			cos(theta) + env_ptr->origin.z;
		i++;
	}
}

void	ft_rotate_z(t_env *env_ptr)
{
	int				i;
	int				size;
	double			theta;
	t_double_coord	coord_i;

	i = 0;
	theta = -(double)(env_ptr->param.z_rotation) / 180.0 * 3.141592;
	size = env_ptr->x_size * env_ptr->y_size;
	while (i < size)
	{
		coord_i.x = env_ptr->double_coord_tab[i].x - env_ptr->origin.x;
		coord_i.y = env_ptr->double_coord_tab[i].y - env_ptr->origin.y;
		coord_i.z = env_ptr->double_coord_tab[i].z - env_ptr->origin.z;
		env_ptr->double_coord_tab[i].x = coord_i.x * cos(theta) + coord_i.y *
			sin(theta) + env_ptr->origin.x;
		env_ptr->double_coord_tab[i].y = -coord_i.x * sin(theta) + coord_i.y *
			cos(theta) + env_ptr->origin.y;
		i++;
	}
}

void	ft_rotate(t_env *env_ptr)
{
	if (env_ptr->param.x_rotation % 360 != 0)
		ft_rotate_x(env_ptr);
	if (env_ptr->param.y_rotation % 360 != 0)
		ft_rotate_y(env_ptr);
	if (env_ptr->param.z_rotation % 360 != 0)
		ft_rotate_z(env_ptr);
}
