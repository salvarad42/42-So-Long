/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salvarad <salvarad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:50:21 by salvarad          #+#    #+#             */
/*   Updated: 2023/05/08 19:49:48 by salvarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*ft_update(char *save)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free (save);
		return (NULL);
	}
	str = (char *) ft_calloc((ft_strlen(save) - i + 1), sizeof (char));
	if (!str)
		return (NULL);
	j = 0;
	i++;
	while (save[i])
	{
		str[j] = save[i];
		i++;
		j++;
	}
	free (save);
	return (str);
}

char	*ft_read_line(char	*save)
{
	int		i;
	char	*line;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	line = (char *) ft_calloc((i + 1), sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	return (line);
}

char	*ft_read_fd(int fd, char *save)
{
	char	*buff;
	int		bytes_read;

	buff = (char *) ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buff)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(save, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buff);
			free(save);
			return (NULL);
		}
		buff[bytes_read] = '\0';
		save = ft_strjoin(save, buff);
	}
	free(buff);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = ft_read_fd(fd, save);
	if (!save)
		return (NULL);
	line = ft_read_line(save);
	save = ft_update(save);
	return (line);
}
