#include "Includes/ft_fdf.h"

int		main(int argc, char **argv)
{
	int		fd;
	int		error;
	t_env	env;

	if (argc != 2)
		return (ft_error());

	if ((fd = open(argv[1], O_RDONLY)) <= 0)
		return (ft_error());

	ft_init_env(&env);
	env.tab = get_table(fd, &env);
//	env.coord_tab = get_coord_table(env);
	if (close(fd) != 0)
		return (ft_error());

	ft_init_param(&(env.param));
	ft_manipulate_data(&env);

	error = 0;
	error = ft_mlx_tab_treat(env);


    free_tab(env.tab, env.y_size);
    free(env.coord_tab);
//que se passe t il si vide ?)

	if (error != 0)
		return (ft_error());
//	sleep(100);
//nettoyé --> 0  avant d'utiliser ft_mlx_tab_treat
	return (0);
}
