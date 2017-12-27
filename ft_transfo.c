#include "Includes/ft_fdf.h"



// cte, env.iso_cte1 env.iso_cte2 entre 0,5 et 1
void    ft_transfo_iso(t_env env, int i)
{
	env.para_cte = 0;
    env.coord_tab[i].X_proj = (env.coord_tab[i].x * env.iso_cte1 - env.iso_cte2 * env.coord_tab[i].y) * 50;
    env.coord_tab[i].Y_proj = (env.coord_tab[i].z + env.iso_cte1 / 2 * env.coord_tab[i].x + env.iso_cte2 / 2 * env.coord_tab[i].y) *50;
}


void    ft_transfo_para(t_env env, int i)
{
    env.coord_tab[i].X_proj = (env.coord_tab[i].x + env.para_cte* env.coord_tab[i].z) * 50;
    env.coord_tab[i].Y_proj = (env.coord_tab[i].y + env.para_cte / 2 * env.coord_tab[i].z) * 50;
	
}


// ds transfo ajouter taille fenetre et mettre proportionellement

void    ft_transfo(t_env env, void (*ft_transfo_coord)(t_env env, int i))
{
    int     i;
    
    i = 0;
	ft_transfo_coord = &ft_transfo_para;

    while (i < env.x_size * env.y_size)
    {
		env.coord_tab[i].x = i % env.x_size;
		env.coord_tab[i].y = i / env.x_size;
		env.coord_tab[i].z = env.tab[i / env.x_size][i % env.x_size];
        (*ft_transfo_coord)(env, i);
		ft_putnbr(env.coord_tab[i].x);
ft_putstr("\n");
		ft_putnbr(env.coord_tab[i].y);
ft_putstr("\n");
		ft_putnbr(env.coord_tab[i].z);
ft_putstr("\n");
ft_putstr("\n");

        i++;
    }
    ft_show_coord_tab(env.coord_tab, env.x_size, env.y_size);

}

