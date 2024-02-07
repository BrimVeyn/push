/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-pae <bryan.vanpaemel@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:01:07 by bvan-pae          #+#    #+#             */
/*   Updated: 2023/12/20 11:54:52 by bvan-pae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	execute_helper(t_psw *psw, char *str)
{
	if (ps_strcmp(str, "sa"))
		sa(psw);
	else if (ps_strcmp(str, "sb"))
		sb(psw);
	else if (ps_strcmp(str, "ss"))
		ss(psw);
	else if (ps_strcmp(str, "pa"))
		pa(psw);
	else if (ps_strcmp(str, "pb"))
		pb(psw);
	else if (ps_strcmp(str, "ra"))
		ra(psw);
	else if (ps_strcmp(str, "rb"))
		rb(psw);
	else if (ps_strcmp(str, "rr"))
		rr(psw);
	else if (ps_strcmp(str, "rra"))
		rra(psw);
	else if (ps_strcmp(str, "rrb"))
		rrb(psw);
	else if (ps_strcmp(str, "rrr"))
		rrr(psw);
}

void	free_starstar(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	execute_string(t_psw *psw, char *str)
{
	char	**res;
	int		i;

	i = 0;
	res = ft_split(str, '\n');
	while (res[i])
	{
		execute_helper(psw, res[i]);
		i++;
	}
	free_starstar(res);
}

char	*ft_strjoinfree(char const *s1, char const *s2)
{
	char	*cat;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	cat = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (cat == NULL)
		return (NULL);
	while (s1[i])
	{
		cat[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		cat[i + j] = s2[j];
		j++;
	}
	cat[i + j] = 0;
	free((void *)s1);
	return (cat);
}
