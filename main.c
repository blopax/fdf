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
	
	
	env.tab = get_table(fd, &env);

ft_putstr("\nA\n");
	env.coord_tab = get_coord_table(env);
    
    env.para_cte = 0.5;
    env.iso_cte1 = 0.5;
    env.iso_cte2 = 0.5;
    env.transfo = 0;

ft_putstr("\nB\n");
    ft_transfo(env, &ft_transfo_iso);


ft_putstr("\nC\n");

//a enlever
//	ft_show_tab(env.tab, env.x_size, env.y_size);
  //  ft_show_tab(env.tab, env.x_size, env.y_size);
    //ft_putstr("\n\n\n");

    
	if (close(fd) != 0)
		return (ft_error());

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
