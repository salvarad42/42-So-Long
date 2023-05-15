/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salvarad <salvarad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 08:29:26 by salvarad          #+#    #+#             */
/*   Updated: 2023/05/15 10:23:41 by salvarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_on_key(int key, t_game *game)
{
	t_player_sprite	player_sprite;

	player_sprite = game -> map -> components -> player -> sprite;
	if (key == KEY_SCAPE)
		ft_close_game(game);
	ft_move_player(key, game);
	return (0);
}

int	ft_close_game(t_game *game)
{
	mlx_destroy_window(game -> mlx, game -> mlx_win);
	exit(0);
	return (0);
}

void	ft_game(t_map *map)
{
	t_game			*game;

	game = (t_game *) malloc(sizeof(t_game));
	game -> mlx = mlx_init();
	game -> mlx_win = mlx_new_window(game -> mlx, map -> size -> width * SIZE_W,
			map -> size -> height * SIZE_H, "So_Long");
	game -> assets = ft_load_assets(game -> mlx);
	game -> map = map;
	ft_print_map(game);
	mlx_hook(game -> mlx_win, 17, 0, ft_close_game, game);
	mlx_key_hook(game -> mlx_win, ft_on_key, game);
	mlx_loop(game -> mlx);
	free(game);
}
