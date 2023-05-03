/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salvarad <salvarad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 08:01:55 by salvarad          #+#    #+#             */
/*   Updated: 2023/05/03 08:06:37 by salvarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_width(char *str, int size)
{
	if ((int) ft_strlen(str) != size)
	{
		ft_putstr_fd("Error\nInvalid width\n", 1);
		exit (0);
	}
}
