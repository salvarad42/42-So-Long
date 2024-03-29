/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salvarad <salvarad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 10:25:01 by salvarad          #+#    #+#             */
/*   Updated: 2022/09/29 11:36:18 by salvarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{	
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && s[i] != (char) c)
		i++;
	if (s[i] == (char) c)
	{
		return ((char *) &s[i]);
	}
	return (NULL);
}
