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

/*
1) obtenir zmax et zmin au debut (en double)
parcourir tableau double_coord
--> ca on peut le faire avec  fonction void ds ft_colour.c

2) determiner hauteur z (attention c avec Xproj et Yproj)
ds plot line ac X0 X1 Y0 Y1 noter z0 et z1 
if x0 == x1 then z = z0 + (z1 - z0) * (y - y0) / (y1 - y0)
else  z = z0 + (z1 - z0) * (x - x0) / (x1 - x0)
--> on utilise coord x et y pour faire ca donc on fait correspondance ac X_proj et Y_proj
ft_height(x, y, t_double_coord double_init0, t_double_coord double_init1)
--> arranger Bresenheim en fonction ds ft_drawlines

3) Determiner couleur en fonction z

ABSOLUE
--> a voir si on laisse la personne mettre les couleurs ou si on a une sorte de zscale qui change les seuils des couleurs:
= bleu nuit inferieur a -1000 --> -1000 = bleu nuit
= vert degrade entre - 100 et 500 --> 300 = vert
= rouge/marrron degrade entre 500 et 3500 --> 2000 = Rouge
= blanc superieur a 3500 --> 3500 = Blanc

et on fait %

exp si z = 3000 
colour = rouge * (1 - (3000 - 2000) / (3500 - 2000)) + blanc * (1 - (3500 - 3000)/(3500 - 2000)) = rouge * 33% + blanc * 66%
--> utiliser val absolue 

exp si z = -500
colour = blue (1 - (-500 - -1000) / (300 - -1000) + vert (1 - (300 - -500) / (300 - -1000) = blue * 60% + vert * 40 %

RELATIF
entre -100 % et 100 % on fait positif et negatif ou entre 0 et 100%

z max
z min
comparer 1 si zmax != zmin sinon dire que tout est Blanc
voir si 

si entre 0 et 100%
(z - zmin) / (z max - z min)
0% = BLUE 
33% GREEN
66% RED
100% = Blanc

Si entre -100% et 100%
si z = 0 GREEN
si z < 0
(z) / (zmin)
si z > 0
z / zmax


- 100% = BLUE
0 % = GREEN
50% = RED
100% = BLANC



*/
	z = 0;
    return (0xFFFFFF);
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
