#include "so_long.h"

void    ft_dfs_exit(int row, int col, t_map *map, int *exit, int *collectible)
{
    if (row < 0 || col < 0 || row >= map -> size -> width || col >= map -> size -> height)
        return;
    if (map -> map[row][col] == '1' || visited[row][col] == 1)
        return;
    if (map -> map[row][col] == 'E')
        exit = 1;
    if (map -> map[row][col] == 'C')
        collectible++;
    visited[row][col] = 1;
    if (exit == 1 && collectible == map -> components -> collectible)
        return;
    ft_dfs_exit(row - 1, col, map, exit, collectible);
    ft_dfs_exit(row + 1, col, map, exit, collectible);
    ft_dfs_exit(row, col - 1, map, exit, collectible);
    ft_dfs_exit(row, col + 1, map, exit, collectible);
}

void    ft_check_exit(t_map *map)
{
    int **visited;
    int exit;
    int collectible;
    int i;

    i = 0;
    visited = (int **) ft_calloc(map -> size -> height,  sizeof(int *));
    while (i < map -> size -> height)
    {
        visited[i] = (int *) ft_calloc(map -> size -> width, sizeof(int));
        i++;
    }
    exit = 0;
    collectible = 0;
    ft_dsf_exit(map -> components -> player -> x, map -> components -> player -> y, map, &exit, &collectible);
    if (exit != 1 || collectible != map -> components ->collectible)
    {
        ft_putstr_fd("Error\nNo exit\n");
        exit (0);
    }
}