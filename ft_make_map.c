#include "so_long.h"

t_size_map ft_map_size(char **argv)
{
    t_size_map  size;
    char        *line;
    int         fd;

    fd = open(argv[1], O_RDONLY);
    line = get_next_line(fd);
    size.width = (int) ft_strlen(line);
    size.height = 0;
    while (line)
    {
        line = get_next_line(fd);
        size.height++;
    }
    close (fd);
    return (size);
}

t_map    ft_make_map(int argc, char **argv)
{
    t_map   map;
    int     fd;
    int     i;

    map.size = ft_map_size(argv);
    map.map = (char **) ft_calloc(map.size.height, sizeof(char *));
    if (!map -> map)
        return (NULL);
    fd = open(argv[1], O_RDONLY);
    i = 0;
    while (i < map.size.height)
    {
        map.map[i] = get_next_line(fd);
        i++;
    }
    close (fd);
    return (map);
}