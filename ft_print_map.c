/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salvarad <salvarad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 08:40:04 by salvarad          #+#    #+#             */
/*   Updated: 2023/05/08 20:03:38 by salvarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_assets_exit(t_game *game, t_pos pos)
{
	if (game -> map -> components -> collectible)
		mlx_put_image_to_window(game -> mlx, game -> mlx_win,
			game -> assets -> exit[0]-> img,
			pos.x * SIZE_W, pos.y * SIZE_H);
	else
		mlx_put_image_to_window(game -> mlx, game -> mlx_win,
			game -> assets -> exit[1]-> img,
			pos.x * SIZE_W, pos.y * SIZE_H);
}

void	ft_print_player(t_game *game, t_pos pos, t_player_sprite sprite)
{
	mlx_put_image_to_window(game -> mlx, game -> mlx_win,
		game -> assets -> player[sprite]-> img,
		pos.x * SIZE_W, pos.y * SIZE_H);
}

void	ft_print_assets(t_game *game, t_pos pos)
{
	if (game -> map -> map[pos.y][pos.x] == '1')
		mlx_put_image_to_window(game -> mlx, game -> mlx_win,
			game -> assets -> wall -> img, pos.x * SIZE_W, pos.y * SIZE_H);
	if (game -> map -> map[pos.y][pos.x] == '0')
		mlx_put_image_to_window(game -> mlx, game -> mlx_win,
			game -> assets -> floor -> img, pos.x * SIZE_W, pos.y * SIZE_H);
	if (game -> map -> map[pos.y][pos.x] == 'P')
		ft_print_player(game, pos,
			game -> map -> components -> player -> sprite);
	if (game -> map -> map[pos.y][pos.x] == 'C')
		mlx_put_image_to_window(game -> mlx, game -> mlx_win,
			game -> assets -> collectible -> img,
			pos.x * SIZE_W, pos.y * SIZE_H);
	if (game -> map -> map[pos.y][pos.x] == 'E')
		ft_print_assets_exit(game, pos);
}

void	ft_print_map(t_game *game)
{
	t_pos	pos;

	pos.y = 0;
	while (pos.y < game -> map -> size -> height)
	{
		pos.x = 0;
		while (pos.x < game -> map -> size -> width)
		{
			ft_print_assets(game, pos);
			pos.x++;
		}
		pos.y++;
	}
}
