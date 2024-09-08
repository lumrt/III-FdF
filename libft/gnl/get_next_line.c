/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumaret <lumaret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:43:06 by lumaret           #+#    #+#             */
/*   Updated: 2024/08/21 17:43:56 by lumaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t dstsize)
{
	size_t	srcsize;
	size_t	i;

	srcsize = ft_strlen(src);
	i = 0;
	if (dstsize > 0)
	{
		while (i < srcsize && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (srcsize);
}

char	*ft_strrchr_gnl(char *s, int c)
{
	int		i;
	char	*res;

	res = NULL;
	i = 0;
	while (s && s[i])
	{
		if (s[i] == (char)c)
		{
			res = (char *)&s[i];
			break ;
		}
		i++;
	}
	if (s[i] == c)
		res = (char *)&s[i + 1];
	return (res);
}

int	get_final_size(char *s1, char *s2, char *buffer)
{
	int	size;

	size = 0;
	if (s1)
	{
		size = s1 - s2;
		ft_strlcpy_gnl(buffer, s1, BUFFER_SIZE + 1);
	}
	else
	{
		size = ft_strlen(s2);
		ft_strlcpy_gnl(buffer, "", BUFFER_SIZE + 1);
	}
	return (size);
}

char	*get_line(int fd, int amount, int final_size)
{
	static char	buffer[FD_SIZE][BUFFER_SIZE + 1];
	char		*line;
	char		*tmp;
	char		*new_line;

	line = ft_strdup(buffer[fd]);
	if (!line)
		return (NULL);
	amount = BUFFER_SIZE;
	while (!isnewline(buffer[fd]) && (amount == BUFFER_SIZE || amount > 0))
	{
		amount = read(fd, buffer[fd], BUFFER_SIZE);
		buffer[fd][amount] = '\0';
		tmp = line;
		line = ft_strjoin(line, buffer[fd]);
		free(tmp);
		if (!line)
			return (NULL);
	}
	if (!ft_strlen(line))
		return (free(line), NULL);
	new_line = ft_strrchr_gnl(line, '\n');
	final_size = get_final_size(new_line, line, buffer[fd]);
	line[final_size] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	char	*line;
	int		amount;
	int		final_size;

	amount = 0;
	final_size = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	line = get_line(fd, amount, final_size);
	if (!line || line[0] == '\0')
		return (NULL);
	return (line);
}
