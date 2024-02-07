/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-pae <bryan.vanpaemel@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:29:55 by bvan-pae          #+#    #+#             */
/*   Updated: 2023/12/21 08:29:46 by bvan-pae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ps_strchr(char *s1, char *s2, int len)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (s1[i] == s2[j] && j < len)
		{
			if (j == 0 && i > 0 && s1[i - 1])
				if (s1[i - 1] != '\n')
					break ;
			j++;
			i++;
		}
		if (j == len)
			return (i - j);
		i = i + 1 - j;
	}
	return (-1);
}

int	*ps_strncmp(const char *s1, const char *s2, int n)
{
	int	i;
	int	j;
	int	*res;

	res = ft_calloc(2, sizeof(int));
	i = 0;
	while (s1[i])
	{
		j = 0;
		while (s1[i] && s1[i] == s2[j])
		{
			j++;
			i++;
			if (s1[i] == s2[j] && j == n - 1)
			{
				res[0] = i - j;
				res[1] = i;
			}
		}
		i += 1 - j;
	}
	return (res);
}

char	*newstr(char *cmds, int opt, int *res)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = ft_calloc(ft_strlen(cmds) - (res[1] - res[0]) + 1, sizeof(char));
	if (opt == 0 || opt == 1)
	{
		while (cmds[i])
		{
			if (i < res[0] || i > res[1])
			{
				new[j] = cmds[i];
				j++;
			}
			i++;
		}
	}
	free(cmds);
	return (new);
}

char	*delrn(char *cmds, int opt)
{
	int		*res;
	char	*rr;

	if (opt == 0)
		rr = "ra\nrb\n";
	else
		rr = "rra\nrrb\n";
	while (1)
	{
		res = ps_strncmp(cmds, rr, ft_strlen(rr));
		if (res[0] == 0 && res[1] == 0)
		{
			free(res);
			break ;
		}
		cmds = newstr(cmds, 0, res);
		free(res);
	}
	return (cmds);
}
