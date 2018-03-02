# include "Includes/ft_fdf.h"


//besoin square ? sinon prendre le square entier ?

int		ft_power_n(int x, int n)
{
	int		i;
	int		result;
	
	i = 0;
	result = 1;
	while (i < n)
	{
		result = result * x;
		i++;
	}
	return (result);
}

double		ft_2D_distance(int x0, int y0, int x1, int y1)
{
	return (sqrt((((double)ft_power_n(x1 - x0, 2) + ft_power_n(y1 - y0, 2)))));
}
