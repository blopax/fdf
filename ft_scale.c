#include "Includes/ft_fdf.h"

void	ft_X_width(t_env *env_ptr)
{
	double	X_proj_max;
	double	X_proj_min;
	int		i;
	int		size;

	X_proj_max = env_ptr->double_coord_tab[0].X_proj;
	X_proj_min = env_ptr->coord_tab[0].X_proj;
	size = env_ptr->x_size * env_ptr->y_size;
	i = 0;
	while (i < env_ptr->x_size * env_ptr->y_size)
	{
		if (X_proj_max < env_ptr->double_coord_tab[i].X_proj)
			X_proj_max = env_ptr->double_coord_tab[i].X_proj;
		if (X_proj_min > env_ptr->double_coord_tab[i].X_proj)
			X_proj_min = env_ptr->double_coord_tab[i].X_proj;
		i++;
	}
	env_ptr->XY_info.X_max = X_proj_max;
	env_ptr->XY_info.X_min = X_proj_min;
	env_ptr->XY_info.X_width = X_proj_max - X_proj_min;
}

void	ft_Y_width(t_env *env_ptr)
{
	double	Y_proj_max;
	double	Y_proj_min;
	int		i;
	int		size;

	Y_proj_max = env_ptr->double_coord_tab[0].Y_proj;
	Y_proj_min = env_ptr->double_coord_tab[0].Y_proj;
	i = 0;
	size = env_ptr->x_size * env_ptr->y_size;

	while (i < env_ptr->x_size * env_ptr->y_size)
	{
		if (Y_proj_max < env_ptr->double_coord_tab[i].Y_proj)
			Y_proj_max = env_ptr->double_coord_tab[i].Y_proj;
		if (Y_proj_min > env_ptr->double_coord_tab[i].Y_proj)
			Y_proj_min = env_ptr->double_coord_tab[i].Y_proj;
		i++;
	}
	env_ptr->XY_info.Y_max = Y_proj_max;
	env_ptr->XY_info.Y_min = Y_proj_min;
	env_ptr->XY_info.Y_width = Y_proj_max - Y_proj_min;
}

void	ft_scale(t_env *env_ptr)
{
	double	X_width;
	double	Y_width;
	double	scale_coef;
	int		win_x;
	int		win_y;


	ft_X_width(env_ptr);
	ft_Y_width(env_ptr);
	X_width = env_ptr->XY_info.X_width;
	Y_width = env_ptr->XY_info.Y_width;
	scale_coef = env_ptr->param.manual_total_scale;
	win_x = env_ptr->param.win_x;
	win_y = env_ptr->param.win_y;

	if (X_width == 0 && Y_width == 0)
		env_ptr->scale = 1;
	else if (X_width == 0)
		env_ptr->scale = (double)win_y / (double)(Y_width) * scale_coef;
	else if (Y_width == 0)
		env_ptr->scale = (double)win_x / (double)(X_width) * scale_coef;
	else if (win_x / X_width < win_y / Y_width)
		env_ptr->scale = (double)win_x / (double)(X_width) * scale_coef;
	else
		env_ptr->scale = (double)win_y / (double)(Y_width) * scale_coef;
}

void	ft_scale_apply(t_env *env_ptr)
{
	int		i;
	double	X_width;
	double	Y_width;
	int		win_x;
	int		win_y;

	ft_scale(env_ptr);
	X_width = env_ptr->XY_info.X_width * env_ptr->scale;
	Y_width = env_ptr->XY_info.Y_width * env_ptr->scale;
	win_x = env_ptr->param.win_x;
	win_y = env_ptr->param.win_y;

	i = 0;
	while (i < env_ptr->x_size * env_ptr->y_size)
	{
		env_ptr->double_coord_tab[i].X_proj = -env_ptr->XY_info.X_min * env_ptr->scale + (win_x - X_width) / 2.0 + (env_ptr->double_coord_tab[i].X_proj)  * env_ptr->scale;
		env_ptr->double_coord_tab[i].Y_proj = -env_ptr->XY_info.Y_min *env_ptr->scale + (win_y - Y_width) / 2.0 + (env_ptr->double_coord_tab[i].Y_proj) * env_ptr->scale;
		i++;
	}
}
