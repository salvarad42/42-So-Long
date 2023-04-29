#ifndef SO_LONG_H

# define SO_LONG_H

# include "libft/libft.h"
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_dfs
{
    int **visited;
    int exit;
    int collectible;
} t_dfs;

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

typedef struct s_player
{
    int     movements;
    t_pos   *pos;
}   t_player;

typedef struct  s_components
{
    int        collectible;
    t_player   *player;
    t_pos      *exit;
}   t_components;

typedef struct s_map
{
    char            **map;
    t_size_map      *size;
    t_components    *components;
}   t_map;

t_map   *ft_make_map(char **argv);
void    ft_check_args(int argc, char **argv);
void    ft_check_map(t_map *map);
void    ft_check_exit(t_map *map);
void    ft_check_width(char *str, int size);
char	*get_next_line(int fd);
void    ft_print_map(t_map *map);
void    ft_game(t_map *map);
void    ft_move_player(t_map *map);

#endif