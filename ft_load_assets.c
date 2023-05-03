/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_assets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salvarad <salvarad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 08:34:11 by salvarad          #+#    #+#             */
/*   Updated: 2023/05/03 13:09:50 by salvarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	*ft_load_img(void *mlx, char *img)
{
	t_img	*asset;

	asset = (t_img *) malloc(sizeof(t_img));
	asset -> size = (t_size *) malloc(sizeof(t_size));
	asset -> img = mlx_xpm_file_to_image(mlx, img,
			&asset -> size -> width, &asset -> size -> height);
	return (asset);
}

void	ft_load_player_assets(void *mlx, t_assets *assets)
{
	assets -> player = (t_img **) malloc(8 * sizeof(t_img *));
	assets -> player[left_alive] = ft_load_img(mlx,
			"./assets/player01-left.xpm");
	assets -> player[left_jump] = ft_load_img(mlx,
			"./assets/player02-left.xpm");
	assets -> player[left_dead] = ft_load_img(mlx,
			"./assets/player03-left.xpm");
	assets -> player[left_exit] = ft_load_img(mlx,
			"./assets/exit-left.xpm");
	assets -> player[right_alive] = ft_load_img(mlx,
			"./assets/player01-right.xpm");
	assets -> player[right_jump] = ft_load_img(mlx,
			"./assets/player02-right.xpm");
	assets -> player[right_dead] = ft_load_img(mlx,
			"./assets/player03-right.xpm");
	assets -> player[right_exit] = ft_load_img(mlx,
			"./assets/exit-right.xpm");
}

t_assets	*ft_load_assets(void *mlx)
{
	t_assets	*assets;

	assets = (t_assets *) malloc(sizeof(t_assets));
	assets -> collectible = ft_load_img(mlx, "./assets/collectible.xpm");
	assets -> enemy = ft_load_img(mlx, "./assets/enemy.xpm");
	assets -> floor = ft_load_img(mlx, "./assets/floor.xpm");
	assets -> wall = ft_load_img(mlx, "./assets/wall.xpm");
	assets -> exit = (t_img **) malloc(2 * sizeof(t_img *));
	assets -> exit[0] = ft_load_img(mlx, "./assets/exit-close.xpm");
	assets -> exit[1] = ft_load_img(mlx, "./assets/exit-open.xpm");
	ft_load_player_assets(mlx, assets);
	return (assets);
}
