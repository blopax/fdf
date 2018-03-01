#include "Includes/ft_fdf.h"

void	ft_previous_key(int k, t_env *env_ptr)
{
	if (k == 7)
		env_ptr->previous_key = 'x';
	else if (k == 16)
		env_ptr->previous_key = 'y';
	else if (k == 13)
		env_ptr->previous_key = 'z';
	else if (k == 0)
		env_ptr->previous_key = 'q';//para cte 1
	else if (k == 6)
		env_ptr->previous_key = 'w';//iso cte 1
	else if (k == 14)
		env_ptr->previous_key = 'e';//iso cte 2
	else if (k == 1)
		env_ptr->previous_key = 's';//scale manual total scale
	else if (k == 2)
		env_ptr->previous_key = 'd';//depth z-scale
	else if (k == 4)
		env_ptr->previous_key = 'h';//horizontal win_x 
	else if (k == 9)
		env_ptr->previous_key = 'v';//vertical win_y
	else if (k == 12)
		env_ptr->previous_key = 'a';//all si reset (touche suivante ou all si a)
	else if (k == 8)
		env_ptr->previous_key = 'c';//colour
	else
	{
		if (!(k == 35 || k == 41))
			env_ptr->previous_key = '0';
	}
}


void	ft_keycode_plus(t_env *env_ptr)
{
	if (env_ptr->previous_key == 'x')
		(env_ptr->param).x_rotation += 5;
	if (env_ptr->previous_key == 'y')
		(env_ptr->param).y_rotation += 5;
	if (env_ptr->previous_key == 'z')
		(env_ptr->param).z_rotation += 5;
	if (env_ptr->previous_key == 'q' && (env_ptr->param).para_cte <= 1)
		(env_ptr->param).para_cte += 0.1;
	if (env_ptr->previous_key == 'w' && (env_ptr->param).iso_cte1 <= 1)
		(env_ptr->param).iso_cte1 += 0.1;
	if (env_ptr->previous_key == 'e' && (env_ptr->param).iso_cte2 <= 1)
		(env_ptr->param).iso_cte2 += 0.1;
	if (env_ptr->previous_key == 's')
		(env_ptr->param).manual_total_scale *= 1.5;
	if (env_ptr->previous_key == 'd')
		(env_ptr->param).manual_z_scale *= 2.0;
	if (env_ptr->previous_key == 'h')
		(env_ptr->param).win_x *= 1.25;
	if (env_ptr->previous_key == 'v')
		(env_ptr->param).win_y *= 1.25;
}

void	ft_keycode_minus(t_env *env_ptr)
{
	if (env_ptr->previous_key == 'x')
		(env_ptr->param).x_rotation -= 5;
	if (env_ptr->previous_key == 'y')
		(env_ptr->param).y_rotation -= 5;
	if (env_ptr->previous_key == 'z')
		(env_ptr->param).z_rotation -= 5;
	if (env_ptr->previous_key == 'q' && (env_ptr->param).para_cte >= 0)
		(env_ptr->param).para_cte -= 0.1;
	if (env_ptr->previous_key == 'w' && (env_ptr->param).iso_cte1 >= 0)
		(env_ptr->param).iso_cte1 -= 0.1;
	if (env_ptr->previous_key == 'e' && (env_ptr->param).iso_cte2 >= 0)
		(env_ptr->param).iso_cte2 -= 0.1;
	if (env_ptr->previous_key == 's')
		(env_ptr->param).manual_total_scale /= 1.5;
	if (env_ptr->previous_key == 'd')
		(env_ptr->param).manual_z_scale /= 2.0;
	if (env_ptr->previous_key == 'h')
		(env_ptr->param).win_x /= 1.25;
	if (env_ptr->previous_key == 'v')
		(env_ptr->param).win_y /= 1.25;
}

void	ft_reset(t_env *env_ptr)
{
	if (env_ptr->previous_key == 'a')
		ft_init_param(&(env_ptr->param));
	if (env_ptr->previous_key == 'x')
		(&(env_ptr->param))->x_rotation = 30;
	if (env_ptr->previous_key == 'y')
		(&(env_ptr->param))->y_rotation = 0;
	if (env_ptr->previous_key == 'z')
		(&(env_ptr->param))->z_rotation = 0;
	if (env_ptr->previous_key == 'q')
		(&(env_ptr->param))->para_cte = 1;
	if (env_ptr->previous_key == 'w')
		(&(env_ptr->param))->iso_cte1 = 0.5;
	if (env_ptr->previous_key == 'e')
		(&(env_ptr->param))->iso_cte2 = 0.5;
	if (env_ptr->previous_key == 's')
		(&(env_ptr->param))->manual_total_scale = 0.9;
	if (env_ptr->previous_key == 'd')
		env_ptr->param.manual_z_scale = 1;
	if (env_ptr->previous_key == 'h')
		(&(env_ptr->param))->win_x = WIN_X;
	if (env_ptr->previous_key == 'v')
		(&(env_ptr->param))->win_y = WIN_Y;
	if (env_ptr->previous_key == 'v')
		(&(env_ptr->param))->colour_mode = 0;
}

