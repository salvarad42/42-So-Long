#include "so_long.h"

void    ft_get_key(char *key)
{
    read(STDIN_FILENO, key, 1);
}

void    ft_update_pos(t_player *player, int x, int y)
{
    int movements;

    movements = player -> movements;
    if (player -> pos -> x != x || player -> pos -> y != y)
        movements += 1;
    player -> pos -> x = x;
    player -> pos -> y = y;    
}

void    ft_update_map(t_map *map, int x, int y)
{
    t_player *player;

    player = map -> components -> player;
    
   if (map -> map[y][x] == 'E')
    {
        if (map -> components -> collectible == 0)
        {
            map -> map[player -> pos -> y][player -> pos -> x] = '0';
            map -> map[y][x] = 'P';
            ft_print_map(map);
            exit (0);
        }  
        else
            return ;       
    } 
    if (map -> map[y][x] != '1')
    {
        
        if (map -> map[y][x] == 'C')
            map -> components -> collectible -= 1;
        map -> map[player -> pos -> y][player -> pos -> x] = '0';
        map -> map[y][x] = 'P';
        ft_update_pos(map -> components -> player, x, y);
    }  
}

void    ft_move_player(t_map *map)
{
    char    key;
    int     x;
    int     y;

    x = map -> components -> player -> pos -> x;
    y = map -> components -> player -> pos -> y;
    key = '\0';
    ft_get_key(&key);
    if (key == 'w' || key == 'W')
        y -= 1;
    else if (key == 's' || key == 'S')
        y += 1;
    else if (key == 'a' || key == 'A')
        x -= 1;
    else if (key == 'd' || key == 'D')
        x += 1;
    ft_update_map(map, x, y);
}