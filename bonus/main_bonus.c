/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salvarad <salvarad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:46:54 by salvarad          #+#    #+#             */
/*   Updated: 2023/05/08 19:51:18 by salvarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	int		fd;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nInvalid number of arguments\n", 1);
		return (0);
	}
	if (ft_strncmp(ft_strrchr(argv[1], '.'), ".ber", 4))
	{
		ft_putstr_fd("Error\nInvalid file type. Please, use a .ber\n", 1);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nFile not found\n", 1);
		return (0);
	}
	close (fd);
	map = ft_make_map(argv);
	ft_check_map(map);
	ft_game(map);
	return (0);
}
