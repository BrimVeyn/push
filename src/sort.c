/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-pae <bryan.vanpaemel@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:57:17 by bvan-pae          #+#    #+#             */
/*   Updated: 2023/12/20 13:57:36 by bvan-pae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	*three_sort_h(int *stack, t_psw *psw, char *finalstr)
{
	if (stack[0] > stack[1] && stack[1] < stack[2] && !is_maxa(psw, stack[0]))
	{
		finalstr = ft_strdup("sa\n");
		sa(psw);
	}
	else if (stack[0] > stack[1] && stack[1] > stack[2])
	{
		finalstr = ft_strdup("sa\nrra\n");
		sa(psw);
		rra(psw);
	}
	else if (stack[0] > stack[1] && stack[1] < stack[2] && is_maxa(psw,
			stack[0]))
	{
		finalstr = ft_strdup("ra\n");
		ra(psw);
	}
	else
		finalstr = ft_strdup("");
	return (finalstr);
}

char	*three_sort(int *stack, t_psw *psw)
{
	char	*finalstr;

	finalstr = NULL;
	if (stack[0] < stack[1] && stack[1] > stack[2] && is_maxa(psw, stack[1])
		&& !is_mina(psw, stack[0]))
	{
		finalstr = ft_strdup("rra\n");
		rra(psw);
	}
	else if (stack[0] < stack[1] && stack[1] > stack[2] && is_mina(psw,
			stack[0]))
	{
		finalstr = ft_strdup("sa\nra\n");
		sa(psw);
		ra(psw);
	}
	else
		finalstr = three_sort_h(stack, psw, finalstr);
	return (finalstr);
}
