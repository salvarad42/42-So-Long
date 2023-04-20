#include "so_long.h"

int main(int argc, char **argv)
{
    t_map   map;

    ft_check_args(argc, argv);
    map = ft_make_map(argc, argv);
    ft_check_map(map);
    ft_check_components (map);
    return (0);
}