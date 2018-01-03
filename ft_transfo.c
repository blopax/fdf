#include "Includes/ft_fdf.h"



// cte, env.iso_cte1 env.iso_cte2 entre 0,5 et 1
void    ft_transfo_iso(t_env env, int i)
{
	env.para_cte = 0;
    env.coord_tab[i].X_proj = (env.coord_tab[i].x * env.iso_cte1 - env.iso_cte2 * env.coord_tab[i].y);
    env.coord_tab[i].Y_proj = (env.coord_tab[i].z + env.iso_cte1 / 2 * env.coord_tab[i].x + env.iso_cte2 / 2 * env.coord_tab[i].y);
}


void    ft_transfo_para(t_env env, int i)
{
    env.coord_tab[i].X_proj = (env.coord_tab[i].x  + env.para_cte* env.coord_tab[i].z);
    env.coord_tab[i].Y_proj = (env.coord_tab[i].y  + env.para_cte / 2 * env.coord_tab[i].z);
	
}


// ds transfo ajouter taille fenetre et mettre proportionellement

void    ft_transfo(t_env env, void (*ft_transfo_coord)(t_env env, int i))
{
    int     i;
	int		X_proj_max;
	int		Y_proj_max;
	int		scale;

	i = 0;
	ft_transfo_coord = &ft_transfo_para;
    while (i < env.x_size * env.y_size)
    {
		env.coord_tab[i].x = (i % env.x_size);
		env.coord_tab[i].y = (i / env.x_size);
		env.coord_tab[i].z = env.tab[i / env.x_size][i % env.x_size];
        (*ft_transfo_coord)(env, i);
		i++;
	}
    i = 0;
	X_proj_max = env.coord_tab[0].X_proj;
	Y_proj_max = env.coord_tab[0].Y_proj;
	while (i < env.x_size * env.y_size)
    {
		if (X_proj_max < env.coord_tab[i].X_proj)
			X_proj_max = env.coord_tab[i].X_proj;
		if (Y_proj_max < env.coord_tab[i].Y_proj)
			Y_proj_max = env.coord_tab[i].Y_proj;
		i++;
	}

	if (WIN_X / X_proj_max < WIN_Y / Y_proj_max) 
		scale = WIN_X / X_proj_max;
	else
		scale = WIN_Y / Y_proj_max;
 ft_putstr("scale\t");
 ft_putnbr(scale);
 ft_putstr("scale\t");
	while (i < env.x_size * env.y_size)
	{
		env.coord_tab[i].X_proj = /*scale / 2 + (WIN_X - X_proj_max * scale) / 2 + */(env.coord_tab[i].X_proj)  * scale * 1000;
		env.coord_tab[i].Y_proj = /*scale / 2 + (WIN_Y - Y_proj_max * scale) / 2 +*/  (env.coord_tab[i].X_proj) * scale * 1000;
		i++;
	}
    ft_show_coord_tab(env.coord_tab, env.x_size, env.y_size);
}


//ft_putstr("\n");
//		ft_putnbr(env.coord_tab[i].y);
//		ft_putstr("\nz = \t");
//		ft_putnbr(env.coord_tab[i].z);
//ft_putstr("\n");
//ft_putstr("\n");

  //      i++;
    //}


void    ft_transfo_xy(t_env env)
{
    int     i;
	int		x_max;
	int		y_max;
	int		scale;

	x_max = env.x_size;
	y_max = env.y_size;
	if (WIN_X / x_max < WIN_Y / y_max) 
		scale = WIN_X / x_max;
	else
		scale = WIN_Y / y_max;

	i = 0;
    while (i < env.x_size * env.y_size)
    {
		env.coord_tab[i].x = scale / 2 + (WIN_X - x_max * scale) / 2 + (i % env.x_size) * scale;
		env.coord_tab[i].y = scale / 2 + (WIN_Y - y_max * scale) / 2 + (i / env.x_size) * scale;
//		env.coord_tab[i].z = env.tab[i / env.x_size][i % env.x_size];
//ft_putstr("\n x  = \t");
//		ft_putnbr(env.coord_tab[i].x);
//ft_putstr("\n");
//ft_putstr("\n y  = \t");
//		ft_putnbr(env.coord_tab[i].y);
//		ft_putstr("\nz = \t");
//		ft_putnbr(env.coord_tab[i].z);
//ft_putstr("\n");

        i++;
    }
//    ft_show_coord_tab(env.coord_tab, env.x_size, env.y_size);

}



