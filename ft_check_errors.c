#include "so_long.h"

void    ft_check_args(int argc, char **argv)
{
    int fd;

    if (argc != 2)
    {
        ft_putstr_fd("Error\nInvalid number of arguments\n", 1);
        exit (0); 
    }
     if (ft_strncmp(ft_strrchr(argv[1], "."), ".ber", 4))
    {
        ft_putstr_fd("Error\nInvalid file type. Please, use a .ber\n", 1);
        exit (0);
    }
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        ft_putstr_fd("Error\nFile not found\n", 1);
        exit (0);
    }
    close (fd);
}

int ft_has_walls(t_map *map)
{
    int i;

    i = 0;
    while (i < map -> height)
    {
        if (map -> map[0][i] != '1' || map -> map[map -> height - 1][i] != '1')
            return (0);
        i++;
    }
    i = 0;
    while (i < map -> width)
    {
        if (map -> map[i][0] != '1' || map -> map[i][map -> width - 1] != '1')
            return (0);
        i++;
    }
    return (1);
}

void    ft_check_map(t_map *map)
{
    
    if (!ft_has_walls(map))
    {
        ft_putstr_fd("Error\nThe map is not delimited by walls\n", 1);
        exit (0);
    }
    if (map -> height == map -> width)
    {
        ft_putstr_fd("Error\nThe map must be rectangular\n");
        exit (0);
    }
}