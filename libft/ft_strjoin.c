/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salvarad <salvarad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 09:53:18 by salvarad          #+#    #+#             */
/*   Updated: 2022/09/30 11:24:32 by salvarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{	
	char	*str;
	size_t	size_s1;
	size_t	size_s2;
	size_t	i;

	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	str = (char *) ft_calloc((size_s1 + size_s2 + 1), sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < size_s1)
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < size_s2)
	{
		str[size_s1 + i] = s2[i];
		i++;
	}
	free((char *) s1);
	return (str);
}
