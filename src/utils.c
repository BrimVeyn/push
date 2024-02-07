/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-pae <bryan.vanpaemel@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:57:27 by bvan-pae          #+#    #+#             */
/*   Updated: 2023/12/19 10:36:58 by bvan-pae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_sorted(t_psw *psw)
{
	int	i;

	i = 0;
	while (i < psw->size_a - 1)
	{
		if (psw->stack_a[i] > psw->stack_a[i + 1])
			return (0);
		i++;
	}
	return (1);
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

void	init_stack_b(t_psw *psw)
{
	psw->stack_b = ft_calloc(psw->size_a + 1, sizeof(int));
	if (!psw->stack_b)
		print_error("Error\n", psw);
	psw->size_b = 0;
}

void	get_minmax_b(t_psw *psw)
{
	int	i;

	i = 0;
	psw->b_min = INT_MAX;
	psw->b_max = INT_MIN;
	while (i < psw->size_b)
	{
		if (psw->stack_b[i] < psw->b_min)
			psw->b_min = psw->stack_b[i];
		if (psw->stack_b[i] > psw->b_max)
			psw->b_max = psw->stack_b[i];
		i++;
	}
}
