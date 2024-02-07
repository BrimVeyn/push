/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-pae <bryan.vanpaemel@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:52:23 by bvan-pae          #+#    #+#             */
/*   Updated: 2023/12/21 08:35:48 by bvan-pae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

int	check_duplicates(int *stack_a, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (stack_a[i] == stack_a[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

void	init_stack_b(t_psw *psw)
{
	psw->stack_b = ft_calloc(psw->size_a + 1, sizeof(int));
	if (!psw->stack_b)
		print_error("Error\n", psw);
	psw->size_b = 0;
}

char	*ft_mstrjoin(const char *fstr, char *a_str, int n, int p)
{
	char		*tmp;
	char		*result;
	int			i;
	int const	size = ft_strlen(a_str);

	if (n < 0)
		return ((char *)fstr);
	tmp = (char *)ft_calloc((size * n) + 1, sizeof(char));
	if (!tmp)
		return (NULL);
	i = -1;
	while (++i < (n * size))
		tmp[i] = a_str[i % size];
	if (p == 0)
		result = ft_strjoin(tmp, fstr);
	if (p == 1)
		result = ft_strjoin(fstr, tmp);
	free(tmp);
	free((void *)fstr);
	return (result);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ss1;
	unsigned char	*ss2;

	i = 0;
	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	while ((ss1[i] || ss2[i]) && i < n)
	{
		if (ss1[i] > ss2[i])
			return (1);
		if (ss1[i] < ss2[i])
			return (-1);
		i++;
	}
	return (0);
}

int	ps_strcmp(char *s1, char *s2)
{
	int	i;

	i = -1;
	while (s1[++i] || s2[i])
		if (s1[i] != s2[i])
			return (0);
	return (1);
}
