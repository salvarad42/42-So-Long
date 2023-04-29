#include "so_long.h"
#include <unistd.h>
#include <termios.h>

void    ft_game(t_map *map)
{
    // Configuramos el modo de entrada de la terminal
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);

    while (1)
    {
        ft_print_map(map);
        ft_move_player(map);
    }

}