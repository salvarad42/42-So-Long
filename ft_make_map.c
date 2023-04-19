#include "so_long.h"

int ft_map_size(char **argv)
{
    int     size;
    char    *line;
    int     fd;

    fd = open(argv[1], O_RDONLY);
    size = 0;
    while (line = get_next_line(fd))
        size++;
    return (size);
}

char    **ft_make_map(int argc, char **argv)
{
    char    **map;
    int     map_size;
    int     i;
    int     fd;

    map_size = ft_map_size(argv);
    map = calloc(map_size, sizeof(char*));
    if (!map)
        return (NULL);
    fd = open(argv[1], O_RDONLY);
    i = 0;
    while (i < map_size)
    {
        map[i] = get_next_line(fd);
        i++;
    }
    return (map);
}