#include "so_long.h"

int ft_map_size(char **argv, int aux)
{
    int     height;
    int     width;
    char    *line;
    int     fd;

    fd = open(argv[1], O_RDONLY);
    line = get_next_line(fd);
    width = (int) ft_strlen(line);
    height = 0;
    while (line)
    {
        line = get_next_line(fd);
        height++;
    }
    close (fd);
    if (aux == 1)
        return (width); 
    if (aux == 0)  
        return (height);
}

t_map    *ft_make_map(int argc, char **argv)
{
    t_map   *map;
    int     fd;
    int     i;

    map -> height = ft_map_size(argv, 0);
    map -> width = ft_map_size(argv, 1);
    map -> map = (char **) ft_calloc(map -> height, sizeof(char *));
    if (!map)
        return (NULL);
    fd = open(argv[1], O_RDONLY);
    i = 0;
    while (i < map -> height)
    {
        map -> map[i] = get_next_line(fd);
        i++;
    }
    close (fd);
    return (map);
}