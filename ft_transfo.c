#include "Includes/ft_fdf.h"



// cte, env_ptr->iso_cte1 env_ptr->iso_cte2 entre 0,5 et 1
void    ft_transfo_iso(t_env *env_ptr, int i)
{
	double		adjusted_z;

	adjusted_z = env_ptr->double_coord_tab[i].z;// * env_ptr->param.manual_z_scale;
	env_ptr->double_coord_tab[i].X_proj = env_ptr->double_coord_tab[i].x * env_ptr->param.iso_cte1 - env_ptr->param.iso_cte2 * env_ptr->double_coord_tab[i].y;
	env_ptr->double_coord_tab[i].Y_proj = -adjusted_z - env_ptr->param.iso_cte1 / 2 * env_ptr->double_coord_tab[i].x + env_ptr->param.iso_cte2 / 2 + env_ptr->double_coord_tab[i].y;
}

void    ft_transfo_para(t_env *env_ptr, int i)
{
	double		adjusted_z;

	adjusted_z = env_ptr->double_coord_tab[i].z;// * env_ptr->param.manual_z_scale;
	env_ptr->double_coord_tab[i].X_proj = env_ptr->double_coord_tab[i].x  + env_ptr->param.para_cte * adjusted_z;
	env_ptr->double_coord_tab[i].Y_proj = env_ptr->double_coord_tab[i].y  - env_ptr->param.para_cte / 2 * adjusted_z;
}

// ds transfo ajouter taille fenetre et mettre proportionellement
void    ft_double_transfo(t_env *env_ptr)
{
	int     i;

	i = 0;

	while (env_ptr->param.applied_transfo == 0 && i < env_ptr->x_size * env_ptr->y_size)
	{
		ft_transfo_para(env_ptr, i);
		i++;
	}
	while (env_ptr->param.applied_transfo == 1 && i < env_ptr->x_size * env_ptr->y_size)
	{
		ft_transfo_iso(env_ptr, i);
		i++;
	}
}

