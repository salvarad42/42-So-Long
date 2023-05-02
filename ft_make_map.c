#include "so_long.h"

t_size *ft_map_size(char **argv)
{
    t_size  *size;
    char        *line;
    int         fd;

    fd = open(argv[1], O_RDONLY);
    line = get_next_line(fd);
    size = (t_size *) malloc(sizeof(t_size));
    size -> width = (int) ft_strlen(line);
    size -> height = 0;
    while (line)
    {
        ft_check_width(line, size -> width);
        size -> height++;
        line = get_next_line(fd);
    }
    close (fd);
    return (size);
}

t_map    *ft_make_map(char **argv)
{
    t_map   *map;
    int     fd;
    int     i;

    map = (t_map *) malloc(sizeof(t_map));
    map -> size = ft_map_size(argv);
    map -> components = NULL;
    map -> map = (char **) ft_calloc(map -> size -> height, sizeof(char *));
    if (!map -> map)
        return (NULL);
    fd = open(argv[1], O_RDONLY);
    i = 0;
    while (i < map -> size -> height)
    {
        map -> map[i] = get_next_line(fd);
        i++;
    }
    close (fd);
    return (map);
}