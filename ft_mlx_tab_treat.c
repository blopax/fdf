#include "Includes/ft_fdf.h"



// zoom qui augmente diminue window size
// touche qui change couleurs (tableau ou degrade proportionnel)
// touche qui redessinne fenetre
// touche qui change transfo // ou iso

//changer valeurs keycode quand on voit

int		key_hook(int keycode, t_env *env_ptr)
{
	ft_putstr("\nkeycode=\t");
	ft_putnbr(keycode);
	ft_putstr("\n\n");
	if (keycode == 53)
		exit(0);
    if (keycode == 95)
        env_ptr->transfo = 1 - env_ptr->transfo;
        
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
    if (x == 9)
        env_ptr->transfo = 1 - env_ptr->transfo;
	return (0);
}


int		expose_hook(t_env *env_ptr)
{
    if (env_ptr->transfo == 0)
        ft_transfo(*env_ptr, &ft_transfo_para);
    if (env_ptr->transfo == 1)
        ft_transfo(*env_ptr, &ft_transfo_iso);


    draw(env_ptr);
	return (0);
}

int		ft_mlx_tab_treat(t_env env)
{

	if (!(env.mlx = mlx_init()))
		return (1);

    env.transfo = 0;
	if (!(env.win = mlx_new_window(env.mlx, WIN_X, WIN_Y, "FDF window")))
		return (1);

	mlx_key_hook(env.win, key_hook, &env);
    mlx_mouse_hook(env.win, mouse_hook, &env);
    mlx_expose_hook(env.win, expose_hook, &env);

	mlx_loop(env.mlx);

	return (0);

}
