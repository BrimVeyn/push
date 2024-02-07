/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-pae <bryan.vanpaemel@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 07:06:18 by bvan-pae          #+#    #+#             */
/*   Updated: 2023/12/20 18:40:10 by bvan-pae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*gnl_chr(char *str, int c)
{
	size_t	i;
	char	*s;

	i = 0;
	s = (char *)str;
	if (!s)
		return (NULL);
	if (c == 0)
		return (s + ft_strlen(s));
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (&s[i]);
		i++;
	}
	return (0);
}

char	*gnl_calloc(size_t size)
{
	size_t	i;
	char	*str;

	i = 0;
	str = malloc(size * sizeof(char));
	if (!str)
		return (NULL);
	while (i < size)
		str[i++] = 0;
	return (str);
}

char	*gnl_join(char *left, char *buf)
{
	char	*new;
	size_t	i;
	size_t	j;

	i = -1;
	j = -1;
	if (!left)
		left = gnl_calloc(1);
	if (!left || !buf)
		return (NULL);
	new = (char *)malloc(ft_strlen(left) + ft_strlen(buf) + 1 * sizeof(char));
	if (!new)
		return (NULL);
	while (left[++i])
		new[i] = left[i];
	while (buf[++j])
		new[i + j] = buf[j];
	new[i + j] = '\0';
	free(left);
	return (new);
}
