#include "so_long.h"

int	ft_strr_search(char *s1, char *s2, int n)
{
	int	len;

	len = (int) ft_strlen(s1);
    if (len < n)
        return (0);
	while (n > 0)
	{
        if (s1[len - 1] != s2[n - 1])
            return (0);
        len--;
        n--;
	}
	return (1);
}

void    ft_check_args(int argc, char **argv)
{
    int fd;

    if (argc != 2)
    {
        ft_putstr_fd("Invalid number of arguments.\n", 1);
        exit (0); 
    }
     if (!ft_strr_search(argv[1], ".ber", 4))
    {
        ft_putstr_fd("Invalid file type. Please, use a .ber.\n", 1);
        exit (0);
    }
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        ft_putstr_fd("File not found.\n", 1);
        exit (0);
    }
    close (fd);
}

int ft_iswall(char *str)
{
    if (ft_strchr(str, "1"))
        return (1);
    return (0);
}

void    ft_check_map(t_map *map)
{
    int i;

    i = 0;
    while (i < map -> height)
    {
        if (!ft_iswall(map -> map[0][i]) || !ft_iswall(map -> map[map -> height -1][i]))
        {
            ft_putstr_fd("The map is not delimited by walls.\n", 1);
            exit (0);
        }
        i++;
    }
    i = 0;
    while (i < map -> width)
    {
        if (!ft_iswall(map -> map[i][0]) || !ft_iswall(map -> map[0][map -> width - 1]))
        {
            ft_putstr_fd("The map is not delimited by walls.\n", 1);
            exit (0);
        }
        i++;
    }
}