#include "Includes/ft_fdf.h"


int		*ft_convert_int(char **char_tab, int *line_size)
{
	int		i;
	int		*int_tab;

	*line_size = 0;
	while (char_tab[*line_size] != 0)
		(*line_size)++;

	if (!(int_tab = (int *)malloc(sizeof(int) * *line_size)))
		return (NULL);

	i = 0;
	while (char_tab[i] != 0)
	{
		int_tab[i] = ft_atoi(char_tab[i]);
		free(char_tab[i]);
		i++;
	}
	free(char_tab[i]);
	free(char_tab);
	return (int_tab);
}

int		**ft_int_tab_realloc(int **tab, int tab_lines)
{
	int		**new_tab;
	int		i;
	
	if(!(new_tab = (int **)malloc(sizeof(int *) * (tab_lines + 1))))
		return (NULL);
	
	i = 0;
	while (i < tab_lines)
	{
		new_tab[i] = tab[i];
		i++;
	}

	free(tab);
	return (new_tab);
}

int		**get_table(int fd, t_env *env_ptr)
{
	int		**tab;
	char	*line;
	int		i;
	int		ret;
	int		line_size;

	i = 0;
	tab = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (!(tab = ft_int_tab_realloc(tab, i)))
			return (NULL);
		tab[i] = ft_convert_int(ft_strsplit(line, ' '), &line_size);
		free(line);
		if (i == 0)
			env_ptr->x_size = line_size;
		if (env_ptr->x_size != line_size)
		{
			ft_error();
			return (NULL);
		}
		i++;
	}
	env_ptr->y_size = i;
	return (tab);
}

t_coord		*get_coord_table(t_env env)
{
	int		i;
	int		size;
	t_coord	*coord_tab;

	size = env.x_size * env.y_size;
	if (!(coord_tab = (t_coord *)malloc(sizeof(t_coord) * size)))
		exit(0);
	i = 0;
	while (i < size)
	{
		coord_tab[i].x = i%env.x_size;
		coord_tab[i].y = i/env.x_size;
		coord_tab[i].z = env.tab[coord_tab[i].y][coord_tab[i].x];
	}
	return (coord_tab);
}
