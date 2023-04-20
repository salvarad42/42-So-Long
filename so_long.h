#ifndef SO_LONG_H

# define SO_LONG_H

# include "libft/libft.h"
# include <fcntl.h>

typedef struct s_map
{
    int     height;
    int     width;
    char    **map;

}   t_map;

t_map   *ft_make_map(int argc, char **argv);
void    ft_check_args(int argc, char **argv);
void    ft_check_map(t_map *map);

#endif