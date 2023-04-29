#include "so_long.h"

void    ft_print_map(t_map *map)
{
    int i;

    i = 0;
    ft_putstr_fd("\033[2J\033[H", 1);
    while (i < map -> size -> height)
    {
        ft_putstr_fd(map -> map[i], 1);
        ft_putchar_fd('\n', 1);
        i++;
    }
}