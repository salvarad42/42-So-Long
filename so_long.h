#ifndef SO_LONG_H

# define SO_LONG_H

# include "libft/libft.h"
# include <fcntl.h>

typedef struct s_size_map
{
    int height;
    int width;
}   t_size_map;

typedef struct s_pos
{
    int x;
    int y;
}   t_pos;

typedef struct  s_components
{
    int     collectible;
    t_pos   *player;
    t_pos   *exit;
}   t_components;

typedef struct s_map
{
    char            **map;
    t_size_map      *size;
    t_components    *components;
}   t_map;

t_map   *ft_make_map(int argc, char **argv);
void    ft_check_args(int argc, char **argv);
void    ft_check_map(t_map *map);
void    ft_check_exit(t_map *map);
void    ft_check_width(char *str, int size);

#endif