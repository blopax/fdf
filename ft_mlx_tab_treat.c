#include "ft_fdf.h"


void	draw(t_env env)
{
	int		x;
	int		y;

	y = 0;
	while (y < env.y_size)
	{
		x = 0;
		while (x < env.x_size)
		{
			mlx_pixel_put(env.mlx, env.win, x, y, 0xFFFFFF);
			x++;
		}
		y++;
	}
}

int		key_hook(int keycode, t_env *env_ptr)
{
	ft_putstr("\nkeycode=\t");
	ft_putnbr(keycode);
	ft_putstr("\n\n");
	if (keycode == 53)
		exit(0);
	(void) env_ptr;
	return (0);
}

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
	(void) env_ptr;
	return (0);
}


int		expose_hook(t_env *env_ptr)
{
	draw(*env_ptr);
	return (0);
}

int		ft_mlx_tab_treat(t_env env)
{

	if (!(env.mlx = mlx_init()))
		return (1);

	if (!(env.win = mlx_new_window(env.mlx, WIN_X, WIN_Y, "FDF window")))
		return (1);

	mlx_key_hook(env.win, key_hook, &env);
	mlx_mouse_hook(env.win, mouse_hook, &env);
	mlx_expose_hook(env.win, expose_hook, &env);

	draw(env);


	mlx_loop(env.mlx);

	return (0);

}
