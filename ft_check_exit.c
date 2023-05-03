/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salvarad <salvarad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 08:07:37 by salvarad          #+#    #+#             */
/*   Updated: 2023/05/03 08:11:52 by salvarad         ###   ########.fr       */
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
	if (map -> map[row][col] == '1' || dfs_args -> visited[row][col] == 1)
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

void	ft_check_exit(t_map *map)
{
	t_dfs	*dfs_args;
	int		i;

	i = 0;
	dfs_args = (t_dfs *) malloc(sizeof(t_dfs));
	dfs_args -> visited = (int **)
		ft_calloc(map -> size -> height, sizeof(int *));
	while (i < map -> size -> height)
	{
		dfs_args -> visited[i] = (int *)
			ft_calloc(map -> size -> width, sizeof(int));
		i++;
	}
	dfs_args -> exit = 0;
	dfs_args -> collectible = 0;
	ft_dfs_exit(map -> components -> player -> pos -> y,
		map -> components -> player -> pos -> x, map, dfs_args);
	if (dfs_args -> exit != 1
		|| dfs_args -> collectible != map -> components ->collectible)
	{
		ft_putstr_fd("Error\nNo exit\n", 1);
		exit (0);
	}
	free(dfs_args);
}
