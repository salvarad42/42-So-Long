/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salvarad <salvarad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 08:29:26 by salvarad          #+#    #+#             */
/*   Updated: 2023/05/03 11:27:15 by salvarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_create_rgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	ft_end_game(t_game *game)
{
	t_player_sprite	sprite;

	sprite = game -> map -> components -> player -> sprite;
	if (sprite == right_dead || sprite == left_dead)
		mlx_string_put(game -> mlx, game -> mlx_win,
			game -> map -> size -> width * SIZE_W / 2 - 4 * FONT_WIDTH,
			game -> map -> size -> height * SIZE_H / 2 - FONT_HEIGHT / 2,
			ft_create_rgb(1, 255, 255, 255), "You lose");
}

int	ft_close_game(t_game *game)
{
	mlx_destroy_window(game -> mlx, game -> mlx_win);
	exit(0);
	return (0);
}

void	ft_game(t_map *map)
{
	t_game	*game;

	game = (t_game *) malloc(sizeof(t_game));
	game -> mlx = mlx_init();
	game -> mlx_win = mlx_new_window(game -> mlx, map -> size -> width * SIZE_W,
			map -> size -> height * SIZE_H, "So_Long");
	game -> assets = ft_load_assets(game -> mlx);
	game -> map = map;
	ft_print_map(game);
	mlx_key_hook(game -> mlx_win, ft_move_player, game);
	mlx_hook(game -> mlx_win, 17, 0, ft_close_game, game);
	mlx_loop(game -> mlx);
	free(game);
}
