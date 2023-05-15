/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_game_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salvarad <salvarad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 08:12:02 by salvarad          #+#    #+#             */
/*   Updated: 2023/05/15 10:36:42 by salvarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_check_walls(t_map *map)
{
	int	i;

	i = 0;
	while (i < map -> size -> width)
	{
		if (map -> map[0][i] != '1'
			|| map -> map[map -> size -> height - 1][i] != '1')
		{
			ft_putstr_fd("Error\nThe map is not delimited by walls\n", 1);
			exit (0);
		}
		i++;
	}
	i = 0;
	while (i < map -> size -> height)
	{
		if (map -> map[i][0] != '1'
			|| map -> map[i][map -> size -> width - 1] != '1')
		{
			ft_putstr_fd("Error\nThe map is not delimited by walls\n", 1);
			exit (0);
		}
		i++;
	}
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

int	ft_check_components(t_map *map, t_components *components)
{
	int	i;
	int	j;

	i = 0;
	while (i < map -> size -> height)
	{
		j = 0;
		while (j < map -> size -> width)
		{
			if (map -> map[i][j] == 'P')
				ft_make_position(&components -> player -> pos, j, i);
			if (map -> map[i][j] == 'E')
				ft_make_position(&components -> exit, j, i);
			if (map -> map[i][j] == 'C')
				components -> collectible++;
			else if (map -> map[i][j] != '0' && map -> map[i][j] != '1' && map -> map[i][j] != 'X')
			{
				ft_putstr_fd("Error\nInvalid component\n", 1);
				exit (0);
			}
			j++;
		}
		i++;
	}
	if (components -> player -> pos == NULL
		|| components -> exit == NULL
		|| components -> collectible < 1)
		return (0);
	return (1);
}

void	ft_check_width(char *str, int size)
{
	if ((int) ft_strlen(str) != size):q
	{
		ft_putstr_fd("Error\nInvalid width\n", 1);
		exit (0);
	}
}

void	ft_check_map(t_map *map)
{
	if (map -> size -> height <= 2 || map -> size -> width <= 2)
	{
		ft_putstr_fd("Error\nWidth and height must be > 2", 1);
		exit (0);
	}
	if (map -> size -> height == map -> size -> width)
	{
		ft_putstr_fd("Error\nThe map must be rectangular\n", 1);
		exit (0);
	}
	ft_check_walls(map);
	ft_get_components(map);
	ft_check_exit(map);
}
