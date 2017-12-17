#include "ft_fdf.h"

int		main(int argc, char **argv)
{
	int		fd;
	int		error;
	t_env	env;

	if (argc != 2)
		return (ft_error());

	if ((fd = open(argv[1], O_RDONLY)) <= 0)
		return (ft_error());
	
	
	
	env.tab = get_table(fd, &env);

//a enlever
	ft_show_tab(env.tab, env.x_size, env.y_size);

	if (close(fd) != 0)
		return (ft_error());

	error = 0;
	error = ft_mlx_tab_treat(env);
	free_tab(env.tab, env.y_size);

	if (error != 0)
		return (ft_error());
//	sleep(100);
//nettoyé --> 0  avant d'utiliser ft_mlx_tab_treat
	return (0);
}
