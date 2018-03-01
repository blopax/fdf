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

void	mlx_put_pxl_to_img(t_env env, int x, int y, int colour)
{
	int		r;

	if (y >= 0 && y < env.param.win_y && x >= 0 && x < env.param.win_x)
	{
		r = ((y * env.param.win_x + x)* 4);
		env.img_addr[r] = colour / (256 * 256) % 256; // BLUE
		env.img_addr[r + 1] = (colour / 256) % 256; // GREEN
		env.img_addr[r + 2] = colour % 256; // RED
		env.img_addr[r + 3] = 0;
	}
}


/*void	plot_line(t_env env, int x0, int y0, int x1, int y1)
{
	int dx =  abs (x1 - x0), sx = x0 < x1 ? 1 : -1;
	int dy = -abs (y1 - y0), sy = y0 < y1 ? 1 : -1; 
	int err = dx + dy, e2; // error value e_xy

	mlx_pixel_put(env.mlx, env.win, x0, y0, 0xFFFFFF);
//	mlx_put_pxl_to_img(env, x0, y0, 0xFFFFFF);
	while (x0 != x1 || y0 != y1) 
	{  
		mlx_pixel_put(env.mlx, env.win, x0, y0, 0xFFFFFF);
//		mlx_put_pxl_to_img(env, x0, y0, 0xFFFFFF);
		e2 = 2 * err;
		if (e2 >= dy) { err += dy; x0 += sx; } // e_xy+e_x > 0 
		if (e2 <= dx) { err += dx; y0 += sy; } // e_xy+e_y < 0 
	}
}

void	draw(t_env *env_ptr)
{
    int     i;

	i = 0;
	ft_putnbr(env_ptr->x_size * env_ptr->y_size);
    if (i < env_ptr->x_size * env_ptr->y_size)
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
*/




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


void plot_line (t_env env, int x0, int y0, int x1, int y1)
{
	
	int dx =  abs (x1 - x0), sx = x0 < x1 ? 1 : -1;
	int dy = -abs (y1 - y0), sy = y0 < y1 ? 1 : -1; 
	int err = dx + dy, e2; /* error value e_xy */

//	mlx_pixel_put(env.mlx, env.win, x0, y0, 0xFFFFFF);
	mlx_put_pxl_to_img(env, x0, y0, 0xFFFFFF);

	while (x0 != x1 || y0 != y1) 
	{  
//		mlx_pixel_put(env.mlx, env.win, x0, y0, 0xFFFFFF);
		mlx_put_pxl_to_img(env, x0, y0, 0xFFFFFF);
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
