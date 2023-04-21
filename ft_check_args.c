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