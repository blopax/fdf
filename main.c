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

	env.coord_tab = get_coord_table(env);

    ft_putstr("\n\n");
    ft_putnbr(env.coord_tab[0].z);
    ft_putstr("\n\n");
    ft_putnbr(env.coord_tab[1].z);
    ft_putstr("\n\n");
    ft_putnbr(env.coord_tab[5].z);
    ft_putstr("\n\n");
    ft_putnbr(env.coord_tab[11].z);
    ft_putstr("\n\n");
    
    ft_transfo(env, &ft_transfo_iso);

    
    env.para_cte = 0.5;
    env.iso_cte1 = 0.5;
    env.iso_cte2 = 0.5;
    env.transfo = 0;
    

//a enlever
//	ft_show_tab(env.tab, env.x_size, env.y_size);
  //  ft_show_tab(env.tab, env.x_size, env.y_size);
    //ft_putstr("\n\n\n");

    
	if (close(fd) != 0)
		return (ft_error());

	error = 0;
//	error = ft_mlx_tab_treat(env);
    //ft_putstr("6");


    free_tab(env.tab, env.y_size);
    //ft_putstr("7");

    free(env.coord_tab);
//que se passe t il si vide ?)
    //ft_putstr("8");

	if (error != 0)
		return (ft_error());
//	sleep(100);
//nettoyé --> 0  avant d'utiliser ft_mlx_tab_treat
	return (0);
}
