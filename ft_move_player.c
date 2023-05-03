/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salvarad <salvarad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:44:35 by salvarad          #+#    #+#             */
/*   Updated: 2023/05/03 13:10:04 by salvarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_update_pos(t_player *player, int x, int y)
{
	if (player -> pos -> x != x || player -> pos -> y != y)
		player -> movements += 1;
	player -> pos -> x = x;
	player -> pos -> y = y;
}

void	ft_update_exit(t_game *game, t_player *player, int x, int y)
{
	if (game -> map -> components -> collectible == 0)
	{
		game -> map -> map[player -> pos -> y][player -> pos -> x] = '0';
		game -> map -> map[y][x] = 'P';
		if (player -> sprite <= left_jump)
			player -> sprite = left_exit;
		else
			player -> sprite = right_exit;
		ft_update_pos(game -> map -> components -> player, x, y);
		ft_print_map(game);
		ft_end_game(game);
	}
}

void	ft_update_enemy(t_game *game, t_player *player, int x, int y)
{
	game -> map -> map[player -> pos -> y][player -> pos -> x] = '0';
	game -> map -> map[y][x] = 'P';
	if (player -> sprite <= left_jump)
		player -> sprite = left_dead;
	else
		player -> sprite = right_dead;
	ft_update_pos(game -> map -> components -> player, x, y);
	ft_print_map(game);
	ft_end_game(game);
}

void	ft_update_map(t_game *game, int x, int y)
{
	t_player	*player;

	player = game -> map -> components -> player;
	if (game -> map -> map[y][x] == 'E')
		ft_update_exit(game, player, x, y);
	else if (game -> map -> map[y][x] == 'X')
		ft_update_enemy(game, player, x, y);
	else if (game -> map -> map[y][x] != '1')
	{
		if (game -> map -> map[y][x] == 'C')
			game -> map -> components -> collectible -= 1;
		game -> map -> map[player -> pos -> y][player -> pos -> x] = '0';
		game -> map -> map[y][x] = 'P';
		ft_update_pos(game -> map -> components -> player, x, y);
		ft_print_map(game);
	}
}

void	ft_move_player(int key, t_game *game)
{
	int	x;
	int	y;

	x = game -> map -> components -> player -> pos -> x;
	y = game -> map -> components -> player -> pos -> y;
	if (key == KEY_UP)
		y -= 1;
	else if (key == KEY_DOWN)
		y += 1;
	else if (key == KEY_LEFT)
	{
		x -= 1;
		game -> map -> components -> player -> sprite = left_alive;
	}
	else if (key == KEY_RIGHT)
	{
		x += 1;
		game -> map -> components -> player -> sprite = right_alive;
	}
	ft_update_map(game, x, y);
}
