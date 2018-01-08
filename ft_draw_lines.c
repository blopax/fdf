#include "Includes/ft_fdf.h"

int     max(int a, int b)
{
    if (a <= b)
        return (b);
    else
        return (a);
}

int     min(int a, int b)
{
    if (a <= b)
        return (a);
    else
        return (b);
}

//verifier sortie de colour int (yes) ? idem que printf faire un tableau et dire si z compris entre a et b alors return couleur correspondante ds tableau
int     ft_colour(int z)
{
    z = 0;
    return (0xFFFFFF);
}

void	draw_lines(t_env env, int x1, int y1, int z1, int x2, int y2, int z2)
{
    int     x;
	int     y;

if (x1 == x2 && y1 == y2)
	exit (0);


    if (x2 == x1)
    {
        y = min(y1, y2);
        while (y <= max(y1, y2))
        {
            mlx_pixel_put(env.mlx, env.win, x1, y, ft_colour(z1 + (y - min(y1, y2))/max(y2 - y1, y1 - y2) * (z2 - z1)));
            y++;
        }

    }
    
    else if (y2 == y1)
    {
        x = min(x1, x2);
        while (x <= max(x1, x2))
        {
            mlx_pixel_put(env.mlx, env.win, x, y1, ft_colour(z1 + (x - min(x1, x2))/max(x2 - x1, x1 - x2) * (z2 - z1)));
            x++;
        }

    }
    
    else if (max(x2 - x1, x1 - x2) > max(y2 - y1, y1 - y2))
    {
        
        x = min(x1, x2);
        while (x <= max(x1, x2))
        {
            mlx_pixel_put(env.mlx, env.win, x, y1 + (x - min(x1, x2))/max(x2 - x1, x1 - x2) * (y2 - y1) , ft_colour(z1 + (x - min(x1, x2))/max(x2 - x1, x1 - x2) * (z2 - z1)));
            x++;
        }
    }
    
    else if (max(x2 - x1, x1 - x2) <= max(y2 - y1, y1 - y2))
    {
        y = min(y1, y2);
        while (y <= max(y1, y2))
        {
            mlx_pixel_put(env.mlx, env.win, x1 + (y - min(y1, y2))/max(y2 - y1, y1 - y2) * (x2 - x1), y, ft_colour(z1 + (y - min(y1, y2))/max(y2 - y1, y1 - y2) * (z2 - z1)));
            y++;
        }
    }
}

void
plot_line (t_env env, int x0, int y0, int x1, int y1)
{
	int dx =  abs (x1 - x0), sx = x0 < x1 ? 1 : -1;
	int dy = -abs (y1 - y0), sy = y0 < y1 ? 1 : -1; 
	int err = dx + dy, e2; /* error value e_xy */

	mlx_pixel_put(env.mlx, env.win, x0, y0, 0xFFFFFF);
	while (x0 != x1 || y0 != y1) 
	{  
		mlx_pixel_put(env.mlx, env.win, x0, y0, 0xFFFFFF);
		e2 = 2 * err;
		if (e2 >= dy) { err += dy; x0 += sx; } /* e_xy+e_x > 0 */
		if (e2 <= dx) { err += dx; y0 += sy; } /* e_xy+e_y < 0 */
	}
}

void	draw(t_env *env_ptr)
{
    int     i;

	i = 0;
    while (i < env_ptr->x_size * env_ptr->y_size)
    {
        if ((i % env_ptr->x_size) + 1 < env_ptr->x_size)
		{
			plot_line(*env_ptr, env_ptr->coord_tab[i].X_proj, env_ptr->coord_tab[i].Y_proj,
				env_ptr->coord_tab[i + 1].X_proj, env_ptr->coord_tab[i + 1].Y_proj);
		}
        if ((i / env_ptr->x_size) + 1 < env_ptr->y_size)
		{
			plot_line(*env_ptr, env_ptr->coord_tab[i].X_proj, env_ptr->coord_tab[i].Y_proj,
				env_ptr->coord_tab[i + env_ptr->x_size].X_proj, env_ptr->coord_tab[i + env_ptr->x_size].Y_proj);
		}
        i++;
    }
}





/*if (env_ptr->coord_tab[i].X_proj != env_ptr->coord_tab[i + 1].X_proj || env_ptr->coord_tab[i].Y_proj != env_ptr->coord_tab[i + 1].Y_proj)
			{
				draw_lines(*env_ptr, env_ptr->coord_tab[i].X_proj, env_ptr->coord_tab[i].Y_proj, env_ptr->coord_tab
					    [i].z, env_ptr->coord_tab[i + 1].X_proj, env_ptr->coord_tab[i + 1].Y_proj, env_ptr->coord_tab[i+1].z);
			}
        }
        if ((i / env_ptr->x_size) + 1 < env_ptr->y_size)
        {



			if (env_ptr->coord_tab[i].X_proj != env_ptr->coord_tab[i + env_ptr->x_size].X_proj || env_ptr->coord_tab[i].Y_proj != env_ptr->coord_tab[i + env_ptr->x_size].Y_proj)
			{
				draw_lines(*env_ptr, env_ptr->coord_tab[i].X_proj, env_ptr->coord_tab[i].Y_proj, env_ptr->coord_tab[i].z, env_ptr->coord_tab[i + env_ptr->x_size].X_proj, env_ptr->coord_tab[i + env_ptr->x_size].Y_proj, env_ptr->coord_tab[i + env_ptr->x_size].z);
			}*/
