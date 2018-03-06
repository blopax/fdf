/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_utilities.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 19:00:42 by pclement          #+#    #+#             */
/*   Updated: 2018/03/06 19:01:31 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/ft_fdf.h"

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

double		ft_2d_distance(int x0, int y0, int x1, int y1)
{
	return (sqrt((((double)ft_power_n(x1 - x0, 2) + ft_power_n(y1 - y0, 2)))));
}
