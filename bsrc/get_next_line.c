/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-pae <bryan.vanpaemel@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 06:46:12 by bvan-pae          #+#    #+#             */
/*   Updated: 2023/12/20 18:40:03 by bvan-pae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*left;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	left = gnl_get(fd, left);
	if (!left)
		return (NULL);
	line = gnl_line(left);
	left = gnl_mod(left);
	return (line);
}

char	*gnl_get(int fd, char *left)
{
	char	*buf;
	int		read_bytes;

	buf = gnl_calloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	read_bytes = 1;
	while (!gnl_chr(buf, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[read_bytes] = '\0';
		left = gnl_join(left, buf);
	}
	free(buf);
	return (left);
}

char	*gnl_line(char *left)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!*left)
		return (NULL);
	while (left[i])
		if (left[i++] == '\n')
			break ;
	line = gnl_calloc(i + 1);
	if (!line)
		return (NULL);
	i ^= i;
	while (left[i] && left[i] != '\n')
	{
		line[i] = left[i];
		i++;
	}
	if (left[i] == '\n')
		line[i] = left[i];
	return (line);
}

char	*gnl_mod(char *left)
{
	char	*mod;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (left[i] && left[i] != '\n')
		i++;
	if (!left[i])
	{
		free(left);
		return (NULL);
	}
	mod = gnl_calloc(ft_strlen(left) - i + 1);
	if (!mod)
		return (NULL);
	while (left[++i])
		mod[j++] = left[i];
	free(left);
	return (mod);
}
