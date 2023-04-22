#include "so_long.h"

void    ft_check_width(char *str, int size)
{
    if ((int) ft_strlen(str) != size)
    {
        ft_putstr_fd("Error\nInvalid width\n", 1);
        exit (0);
    }
}