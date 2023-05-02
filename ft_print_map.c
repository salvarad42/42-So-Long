#include "so_long.h"

void    ft_print_assets(t_map *map, t_assets *assets, t_pos pos, void *mlx, void *mlx_win)
{
    if (map -> map[pos.y][pos.x] == '1')
        mlx_put_image_to_window(mlx, mlx_win, assets -> wall -> img, pos.x * SIZE_W, pos.y * SIZE_H);
    if (map -> map[pos.y][pos.x] == '0')
        mlx_put_image_to_window(mlx, mlx_win, assets -> floor -> img, pos.x * SIZE_W, pos.y * SIZE_H);
    if (map -> map[pos.y][pos.x] == 'P')
        mlx_put_image_to_window(mlx, mlx_win, assets -> player[map -> components -> player -> sprite] -> img, pos.x * SIZE_W, pos.y * SIZE_H);
    if (map -> map[pos.y][pos.x] == 'C')
        mlx_put_image_to_window(mlx, mlx_win, assets -> collectible -> img, pos.x * SIZE_W, pos.y * SIZE_H);
    if (map -> map[pos.y][pos.x] == 'E')
    {
        if (map -> components -> collectible)
            mlx_put_image_to_window(mlx, mlx_win, assets -> exit[0] -> img, pos.x * SIZE_W, pos.y * SIZE_H);
        else
            mlx_put_image_to_window(mlx, mlx_win, assets -> exit[1] -> img, pos.x * SIZE_W, pos.y * SIZE_H);
    }
    if (map -> map[pos.y][pos.x] == 'X')
        mlx_put_image_to_window(mlx, mlx_win, assets -> enemy -> img, pos.x * SIZE_W, pos.y * SIZE_H);
}

void    ft_print_map(t_map *map, t_assets *assets, void *mlx, void *mlx_win)
{
    t_pos pos;

    pos.y = 0;
    while (pos.y < map -> size -> height)
    {
        pos.x = 0;
        while (pos.x < map -> size -> width)
        {
            ft_print_assets(map, assets, pos, mlx, mlx_win);
            pos.x++;
        }
        pos.y++;
    }
}