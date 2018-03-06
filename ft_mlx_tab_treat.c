#include "Includes/ft_fdf.h"

int		key_hook(int keycode, t_env *env_ptr)
{
	if (keycode == 53)
		exit(0);
	if (!(keycode == 35 || keycode == 41 || keycode == 15 || keycode == 17 || keycode == 8))
	{
		ft_previous_key(keycode, env_ptr);
		return (0);
	}
	if (keycode == 35)
		ft_keycode_plus(env_ptr);
	if (keycode == 41)
		ft_keycode_minus(env_ptr);
	if (keycode == 15)
		ft_reset(env_ptr);
	if (keycode == 8)
		(env_ptr->param).colour_mode = ((env_ptr->param).colour_mode + 1) % 3;
	if (keycode == 17)
		(env_ptr->param).applied_transfo = 1 - (env_ptr->param).applied_transfo;
	if ((env_ptr->previous_key == 'h' || env_ptr->previous_key == 'v') && (keycode == 35 || keycode == 41))
	{
		mlx_destroy_window(env_ptr->mlx, env_ptr->win);
		env_ptr->flag = 1;
		ft_mlx_tab_treat(*env_ptr);
		return (0);
	}
	ft_previous_key(keycode, env_ptr);
	expose_hook(env_ptr);
	return (0);
}
//clic qui centre tableau ds fenetre ou cliqué

int		mouse_hook(int button, int x, int y, t_env *env_ptr)
{
	ft_putstr("\nbutton=\t");
	ft_putnbr(button);
	ft_putstr("\n");
	ft_putstr("\nx=\t");
	ft_putnbr(x);
	ft_putstr("\n");
	ft_putstr("\ny=\t");
	ft_putnbr(y);
	ft_putstr("\n\n");

	if (button == 4)
		(env_ptr->param).manual_total_scale /= 1.1;
	if (button == 5)
		(env_ptr->param).manual_total_scale *= 1.1;
	expose_hook(env_ptr);
	return (0);
}

int		expose_hook(t_env *env_ptr)
{
	if (env_ptr->img)
		mlx_destroy_image(env_ptr->mlx, env_ptr->img);
	ft_manipulate_data(env_ptr);

	env_ptr->img = mlx_new_image(env_ptr->mlx, env_ptr->param.win_x, env_ptr->param.win_y);

	env_ptr->img_addr = mlx_get_data_addr(env_ptr->img, &(env_ptr->bit_pxl), &(env_ptr->size_line), &(env_ptr->endian));
	draw(env_ptr);
	mlx_clear_window(env_ptr->mlx, env_ptr->win);
	mlx_put_image_to_window(env_ptr->mlx, env_ptr->win, env_ptr->img, 0, 0);

//	mlx_clear_window(env_ptr->mlx, env_ptr->win);
//	draw(env_ptr);

return (0);
}

int		ft_mlx_tab_treat(t_env env)
{
	if (!env.mlx)
	{
		if (!(env.mlx = mlx_init()))
			return (1);
	}
	if (!(env.win = mlx_new_window(env.mlx, env.param.win_x, env.param.win_y, "FDF window")))
		return (1);

	if (env.flag == 1)
		expose_hook(&env);
	mlx_key_hook(env.win, key_hook, &env);
	mlx_mouse_hook(env.win, mouse_hook, &env);
	mlx_expose_hook(env.win, expose_hook, &env);

	mlx_loop(env.mlx);
	return (0);
}

