#include "Includes/ft_fdf.h"



// cte, env.iso_cte1 env.iso_cte2 entre 0,5 et 1
void    ft_transfo_iso(t_env env)
{
    ft_putstr("\nALICIA\n");
    env.coord_tab->X_proj = (env.coord_tab->x * env.iso_cte1 - env.iso_cte2 * env.coord_tab->y);
    env.coord_tab->Y_proj = 1; //(env.coord_tab->z + env.iso_cte1 / 2 * env.coord_tab->x + env.iso_cte2 / 2 * env.coord_tab->y);
    ft_putnbr(env.coord_tab->x);
    ft_putstr("\n");
    ft_putnbr(env.coord_tab->z);
    ft_putstr("\n");
    ft_putnbr(env.coord_tab->X_proj);
    ft_putstr("\n");
    ft_putnbr(env.coord_tab->Y_proj);
    ft_putstr("\n");

}


void    ft_transfo_para(t_env env)
{
    ft_putstr("\nALICIA\n");

    env.coord_tab->X_proj = env.coord_tab->x + env.para_cte* env.coord_tab->z;
    env.coord_tab->Y_proj = 1;//(env.coord_tab->y + env.para_cte / 2 * env.coord_tab->z);
    ft_putnbr(env.coord_tab->x);
    ft_putstr("\n");
    ft_putnbr(env.coord_tab->z);
    ft_putstr("\n");
    ft_putnbr(env.coord_tab->X_proj);
    ft_putstr("\n");
    ft_putnbr(env.coord_tab->Y_proj);
    ft_putstr("\n");
}


// ds transfo ajouter taille fenetre et mettre proportionellement

void    ft_transfo(t_env env, void (*ft_transfo_coord)(t_env))
{
    int     i;
    
    i = 0;
    while (i < env.x_size * env.y_size)
    {
        ft_transfo_coord(env);
        i++;
    }
    ft_show_coord_tab(env.coord_tab, env.x_size, env.y_size);

}

