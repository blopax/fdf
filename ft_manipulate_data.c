#include "Includes/ft_fdf.h"


void	ft_coord_tab_fill(t_env *env_ptr)
{
	int		i;
	int		size;

	size = env_ptr->x_size * env_ptr->y_size;
	if (!(env_ptr->coord_tab = (t_coord *)malloc(sizeof(t_coord) * size)))
		exit(0);
	i = 0;
	while (i < env_ptr->x_size * env_ptr->y_size)
	{
		env_ptr->coord_tab[i].x = (i % env_ptr->x_size);
		env_ptr->coord_tab[i].y = (i / env_ptr->x_size);
		env_ptr->coord_tab[i].z = env_ptr->tab[i / env_ptr->x_size]
			[i % env_ptr->x_size] *env_ptr->param.manual_z_scale;
		env_ptr->coord_tab[i].X_proj = 0;
		env_ptr->coord_tab[i].Y_proj = 0;
		i++;
	}
}

void	ft_copy_double_tab(t_env *env_ptr)
{
	int		i;
	int		size;

	size = env_ptr->x_size * env_ptr->y_size;
	if (!env_ptr->double_coord_tab)
	{
		if (!(env_ptr->double_coord_tab = (t_double_coord *)
				malloc(sizeof(t_double_coord) * size)))
			exit(0);
	}
	i = 0;
	while (i < size)
	{	
		env_ptr->double_coord_tab[i].x = (double)(env_ptr->coord_tab[i].x);
		env_ptr->double_coord_tab[i].y = (double)(env_ptr->coord_tab[i].y);
		env_ptr->double_coord_tab[i].z = (double)(env_ptr->coord_tab[i].z);
		env_ptr->double_coord_tab[i].X_proj = 0.0;
		env_ptr->double_coord_tab[i].Y_proj = 0.0;
		i++;
	}
}

void	ft_origin_fill(t_env *env_ptr)
{
	env_ptr->origin.x = (double)(env_ptr->x_size - 1) / 2.0;
	env_ptr->origin.y = (double)(env_ptr->y_size - 1) / 2.0;
	env_ptr->origin.z = 0;
}

void	ft_int_transfo(t_env *env_ptr)
{
	int		i;
	int		size;

	size = env_ptr->x_size * env_ptr->y_size;
	i = 0;
	while (i < size)
	{
		env_ptr->coord_tab[i].X_proj = (int)(env_ptr->double_coord_tab[i].X_proj);
		env_ptr->coord_tab[i].Y_proj = (int)(env_ptr->double_coord_tab[i].Y_proj);
		i++;
	}
}

void	ft_manipulate_data(t_env *env_ptr)
{
	ft_coord_tab_fill(env_ptr);
	ft_copy_double_tab(env_ptr);
	ft_origin_fill(env_ptr);
	ft_rotate(env_ptr);
	ft_double_transfo(env_ptr);
	ft_scale_apply(env_ptr);
	ft_int_transfo(env_ptr);
//	ft_show_double_coord_tab(env_ptr->double_coord_tab, env_ptr->x_size, env_ptr->y_size);
//	ft_show_coord_tab(env_ptr->coord_tab, env_ptr->x_size, env_ptr->y_size);
}
