#include "Includes/ft_fdf.h"

int		main(int argc, char **argv)
{
	int		fd;
	int		error;
	t_env	env;

	if (argc == 1)
	{
		ft_putstr("Usage: Use ./fdf with a valid map\n\n");
		ft_putstr("Mouse:\n\tScroll to zoom\n\tClick on 2 points to draw\n\n");
		ft_putstr("Keyboard:\n\tescape to close window\n\tr to reset (ar for all)\n\tt to change transformation mode\n\tp and m for plus and minus to be used after following options\n\th & v to resize window\n\td to change depth (z_rotationscale)\n\ts to zoom\n\tq to modify para cte\n\tw & e to modify iso cte\n\tx y z to rotate on the relevant axis\n");
		return (0);
	}

	if (argc > 2)
		return (ft_error());

	if ((fd = open(argv[1], O_RDONLY)) <= 0)
		return (ft_error());

	ft_init_env(&env);
	env.tab = get_table(fd, &env);
//	env.coord_tab = get_coord_table(env);

	ft_init_param(&(env.param));
	ft_manipulate_data(&env);

	error = 0;
	error = ft_mlx_tab_treat(env);


    free_tab(env.tab, env.y_size);
    free(env.coord_tab);
//que se passe t il si vide ?)

if (close(fd) != 0)
		return (ft_error());
	if (error != 0)
		return (ft_error());
//nettoyé --> 0  avant d'utiliser ft_mlx_tab_treat
	return (0);
}
