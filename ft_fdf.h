#ifndef FT_FDF_H

#include "minilibx_macos/mlx.h"
//#include "minilibx_macos/mlx_int.h"
//#include "minilibx_macos/mlx_new_window.h"
#include "libft/includes/libft.h"
#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

# define FT_FDF_H
# define WIN_X 840
# define WIN_Y 840
# define BASE_COLOR 0xFFFFFF


typedef struct	s_env
{
	void	*mlx;
	void	*win;
	int		**tab;
	int		x_size;
	int		y_size;
}				t_env;


int		ft_error();
//retourne 1 et ecrit qqc sur sortie d'erreur (peut aussi eventuellement prendre param si on ecrit plusieurs choses


void	ft_show_tab(int **tab, int x_size, int y_size);

int		**get_table(int fd, t_env *env_ptr);
//ac GNL et split remplit un tableau (en checkant erreurs) a voir si on finit chaque linge par 0 (fait partie du split? )

void	free_tab(int **tab, int tab_lines);
//free toutes les lignes de tab jusqu a tablines a voir si on balance la size de tab ou pasi

int		ft_mlx_tab_treat(t_env env);
//fction qui fait tout le mlx
//renvoie 0 si OK et 1 si error

//GNL
int	get_next_line(int fd, char **line);

//FCT LIBFT UTILISEES
//char	**ft_split(char *line, char c);


#endif
