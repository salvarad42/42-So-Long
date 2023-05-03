/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salvarad <salvarad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 08:12:02 by salvarad          #+#    #+#             */
/*   Updated: 2023/05/03 08:29:11 by salvarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
