/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salvarad <salvarad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:08:19 by salvarad          #+#    #+#             */
/*   Updated: 2023/05/08 19:46:08 by salvarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_dfs_exit(int row, int col, t_map *map, t_dfs *dfs_args)
{
	if (row < 0
		|| col < 0
		|| col >= map -> size -> width
		|| row >= map -> size -> height)
		return ;
	if (map -> map[row][col] == '1'
		|| dfs_args -> visited[row][col] == 1)
		return ;
	if (map -> map[row][col] == 'E')
		dfs_args -> exit = 1;
	if (map -> map[row][col] == 'C')
		dfs_args -> collectible += 1;
	dfs_args -> visited[row][col] = 1;
	if (dfs_args -> exit == 1
		&& dfs_args -> collectible == map -> components -> collectible)
		return ;
	ft_dfs_exit(row - 1, col, map, dfs_args);
	ft_dfs_exit(row + 1, col, map, dfs_args);
	ft_dfs_exit(row, col - 1, map, dfs_args);
	ft_dfs_exit(row, col + 1, map, dfs_args);
}

void	ft_get_components(t_map *map)
{
	t_components	*components;

	components = (t_components *) malloc (sizeof(t_components));
	components -> player = (t_player *) malloc (sizeof(t_player));
	components -> player -> pos = NULL;
	components -> player -> movements = 0;
	components -> player -> sprite = left_alive;
	components -> exit = NULL;
	components -> collectible = 0;
	if (!ft_check_components(map, components))
	{
		ft_putstr_fd("Error\nWrong number of player, exit or collectible\n", 1);
		exit (0);
	}
	map -> components = components;
}

void	ft_make_position(t_pos **pos, int x, int y)
{
	if (!*pos)
	{
		*pos = (t_pos *) malloc(sizeof(t_pos));
		(*pos)-> x = x;
		(*pos)-> y = y;
	}
	else
	{
		ft_putstr_fd("Error\nWrong number of player or exit\n", 1);
		exit (0);
	}
}

int	ft_create_rgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
