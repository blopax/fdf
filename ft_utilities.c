#include "Includes/ft_fdf.h"

int		ft_error()
{
	write(2, "Error\n", 6);
	return (1);
}

void	free_tab(int **tab, int tab_lines)
{
	int		i;

	i = 0;

	if (tab)
	{
		while (i < tab_lines)
		{
			if (tab[i])
				free(tab[i]);
			i++;
		}
		free(tab);
	}
}


void	ft_show_tab(int **tab, int x_size, int y_size)
{
	int		i;
	int		j;

	j = 0;
	while (j < y_size)
	{
		i = 0;
		while (i < x_size)
		{
			ft_putnbr(tab[j][i]);
			ft_putstr("\t");
			i++;
		}
		j++;
		ft_putstr("\n");
	}
}

void	ft_show_coord_tab(t_coord *coord_tab, int x_size, int y_size)
{
    int		i;
    
    i = 0;
    while (i < x_size * y_size)
    {
        ft_putnbr(coord_tab[i].X_proj);
        ft_putstr("/");
        ft_putnbr(coord_tab[i].Y_proj);
        ft_putstr("\t");
        i++;
    }
}
