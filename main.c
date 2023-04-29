#include "so_long.h"

int main(int argc, char **argv)
{
    t_map   *map;

    ft_check_args(argc, argv);
    map = ft_make_map(argv);
    ft_check_map(map);
    ft_game(map);
    return (0);
}