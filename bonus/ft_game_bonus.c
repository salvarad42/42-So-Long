/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salvarad <salvarad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 08:29:26 by salvarad          #+#    #+#             */
/*   Updated: 2023/05/08 19:52:41 by salvarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_end_game(t_game *game)
{
	t_player_sprite	sprite;

	sprite = game -> map -> components -> player -> sprite;
	if (sprite == right_dead || sprite == left_dead)
		mlx_string_put(game -> mlx, game -> mlx_win,
			game -> map -> size -> width * SIZE_W / 2 - 4 * FONT_WIDTH,
			game -> map -> size -> height * SIZE_H / 2 - FONT_HEIGHT / 2,
			ft_create_rgb(1, 255, 255, 255), "You lose");
	if (sprite == right_exit || sprite == left_exit)
		mlx_string_put(game -> mlx, game -> mlx_win,
			game -> map -> size -> width * SIZE_W / 2 - 4 * FONT_WIDTH,
			game -> map -> size -> height * SIZE_H / 2 - FONT_HEIGHT / 2,
			ft_create_rgb(1, 255, 255, 255), "You win");
}

int	ft_on_key(int key, t_game *game)
{
	t_player_sprite	player_sprite;

	player_sprite = game -> map -> components -> player -> sprite;
	if (key == KEY_SCAPE)
		ft_close_game(game);
	if (player_sprite == right_alive || player_sprite == left_alive
		|| player_sprite == right_jump || player_sprite == left_jump)
		ft_move_player(key, game);
	return (0);
}

int	ft_close_game(t_game *game)
{
	mlx_destroy_window(game -> mlx, game -> mlx_win);
	exit(0);
	return (0);
}

int	ft_sprite_motion(t_game *game)
{
	t_player	*player;

	player = game -> map -> components -> player;
	if (player -> frames < PLAYER_ANIMATION)
	{
		player -> frames++;
		return (0);
	}
	if (player -> sprite == left_alive || player -> sprite == right_alive)
		player -> sprite++;
	else if (player -> sprite == left_jump || player -> sprite == right_jump)
		player -> sprite--;
	ft_print_player(game, *player -> pos, player -> sprite);
	return (1);
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
	mlx_loop_hook(game -> mlx, ft_sprite_motion, game);
	mlx_loop(game -> mlx);
	free(game);
}
