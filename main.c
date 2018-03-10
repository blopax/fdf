/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 18:27:20 by pclement          #+#    #+#             */
/*   Updated: 2018/03/06 18:31:57 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/ft_fdf.h"

int		ft_usage(void)
{
	ft_putstr("Usage: Use ./fdf with a valid map\n\n");
	ft_putstr("Mouse:\n\tScroll to zoom\n\n");
	ft_putstr("Keyboard:\n\tescape to close window\n\tr to reset (a r for all)\
			\n\tt to change transformation mode\
			\n\tp and m for plus and minus to be used after following options\
			\n\th & v to resize window\
			\n\td to change depth (z_scale)\n\ts to zoom\
			\n\tq to modify para cte\
			\n\tw & e to modify iso cte\
			\n\tx y z to rotate on the relevant axis\n");
	return (1);
}

int		main(int argc, char **argv)
{
	int		fd;
	int		error;
	t_env	env;

	if (argc == 1)
		return (ft_usage());
	if (argc > 2)
		return (ft_error());
	if ((fd = open(argv[1], O_RDONLY)) <= 0)
		return (ft_error());
	ft_init_env(&env);
	env.tab = get_table(fd, &env);
	ft_init_param(&(env.param));
	ft_manipulate_data(&env);
	error = 0;
	error = ft_mlx_tab_treat(env);
	free_tab(env.tab, env.y_size);
	free(env.coord_tab);
	if (close(fd) != 0)
		return (ft_error());
	if (error != 0)
		return (ft_error());
	return (0);
}

// verifier arg=echo "1"; ./fdf ARG 
// si fichier vide non rectangulaire etc...
