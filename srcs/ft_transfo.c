/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transfo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 18:37:40 by pclement          #+#    #+#             */
/*   Updated: 2018/03/06 18:53:22 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fdf.h"

void	ft_transfo_iso(t_env *env_ptr, int i)
{
	env_ptr->double_coord_tab[i].x_proj = env_ptr->double_coord_tab[i].x *
		env_ptr->param.iso_cte1 - env_ptr->param.iso_cte2 *
		env_ptr->double_coord_tab[i].y;
	env_ptr->double_coord_tab[i].y_proj = -env_ptr->double_coord_tab[i].z *
		env_ptr->param.manual_z_scale - env_ptr->param.iso_cte1 / 2 *
		env_ptr->double_coord_tab[i].x + env_ptr->param.iso_cte2 / 2 +
		env_ptr->double_coord_tab[i].y;
}

void	ft_transfo_para(t_env *env_ptr, int i)
{
	env_ptr->double_coord_tab[i].x_proj = env_ptr->double_coord_tab[i].x
		+ env_ptr->param.para_cte * env_ptr->double_coord_tab[i].z;
	env_ptr->double_coord_tab[i].y_proj = env_ptr->double_coord_tab[i].y
		- env_ptr->param.para_cte / 2 * env_ptr->double_coord_tab[i].z;
}

void	ft_double_transfo(t_env *env_ptr)
{
	int		i;

	i = 0;
	while (env_ptr->param.applied_transfo == 0 && i < env_ptr->x_size *
			env_ptr->y_size)
	{
		ft_transfo_para(env_ptr, i);
		i++;
	}
	while (env_ptr->param.applied_transfo == 1 && i < env_ptr->x_size *
			env_ptr->y_size)
	{
		ft_transfo_iso(env_ptr, i);
		i++;
	}
}
