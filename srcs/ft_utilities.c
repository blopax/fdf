/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 18:32:09 by pclement          #+#    #+#             */
/*   Updated: 2018/03/06 18:48:09 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fdf.h"

int		ft_power_n(int x, int n)
{
	int		i;
	int		result;

	i = 0;
	result = 1;
	while (i < n)
	{
		result = result * x;
		i++;
	}
	return (result);
}

int		ft_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

void	free_tab(int **tab, int tab_lines)
{
	int		i;

	i = 0;
	if (tab)
	{
		while (i < tab_lines)
		{
			if (tab[i])
			{
				free(tab[i]);
				tab[i] = 0;
			}
			i++;
		}
		free(tab);
	}
}

void	ft_init_param(t_param *param)
{
	param->x_rotation = 30;
	param->y_rotation = 0;
	param->z_rotation = 0;
	param->applied_transfo = 0;
	param->para_cte = 1;
	param->iso_cte1 = 0.5;
	param->iso_cte2 = 0.5;
	param->manual_total_scale = 0.9;
	param->manual_z_scale = 1;
	param->win_x = WIN_X;
	param->win_y = WIN_Y;
	param->colour_mode = 0;
}

void	ft_init_env(t_env *env_ptr)
{
	env_ptr->mlx = 0;
	env_ptr->win = 0;
	env_ptr->img = 0;
	env_ptr->tab = 0;
	env_ptr->x_size = 0;
	env_ptr->y_size = 0;
	env_ptr->coord_tab = 0;
	env_ptr->double_coord_tab = 0;
	env_ptr->scale = 1;
	env_ptr->previous_key = 0;
	env_ptr->flag = 0;
}
/*
void	ft_show_tab(int **tab, int x_size, int y_size)
{
	int		i;
	int		j;

	j = 0;
	while (j < y_size)
	{
		i = 0;
		while (i < x_size)
		{
			ft_putnbr(tab[j][i]);
			ft_putstr("\t");
			i++;
		}
		j++;
		ft_putstr("\n");
	}
}


void	ft_show_coord_tab(t_coord *coord_tab, int x_size, int y_size)
{
    int		i;
    
    i = 0;
    while (i < x_size * y_size)
    {
		if (coord_tab[i].x == 0)
			ft_putstr("\n");
        ft_putnbr(coord_tab[i].x_proj);
        ft_putstr("/");
        ft_putnbr(coord_tab[i].y_proj);
        ft_putstr("\t");
        i++;
    }
}

void	ft_show_double_coord_tab(t_double_coord *double_coord_tab, int x_size, int y_size)
{
    int		i;
 
	i = 0;
    while (i < x_size * y_size)
    {
		if (i % x_size == 0)
			printf("\n");
        printf("%f/%f/%f\t",double_coord_tab[i].x, double_coord_tab[i].y, double_coord_tab[i].z);
        i++;
    }

        printf("\n\n");
        i++;
	i = 0;
    while (i < x_size * y_size)
    {
		if (i % x_size == 0)
			printf("\n");
		printf("%f/%f\t", double_coord_tab[i].x_proj, double_coord_tab[i].y_proj);
		i++;
	}
}
*/