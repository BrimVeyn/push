/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-pae <bryan.vanpaemel@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:25:13 by bvan-pae          #+#    #+#             */
/*   Updated: 2023/12/20 13:33:28 by bvan-pae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_cost	get_ftotop(t_psw *psw, int index, t_cost *low)
{
	if (index <= psw->size_a - index)
	{
		low->cmds = ft_mstrjoin(low->cmds, "ra\n", index, 1);
		low->cost = index;
	}
	else
	{
		low->cmds = ft_mstrjoin(low->cmds, "rra\n", psw->size_a - index, 1);
		low->cost = psw->size_a - index;
	}
	return (*low);
}

t_cost	get_cost(t_psw *psw, int index)
{
	t_cost	low;

	low.cost = 0;
	low.cmds = ft_calloc(1, 1);
	if (index > 0)
		low = get_ftotop(psw, index, &low);
	low = neither_y(psw, &low, psw->stack_a[index]);
	return (low);
}

int	get_lowest(int a, int b)
{
	if (a >= b)
		return (b);
	else
		return (a);
}

t_cost	get_lowest_cost(t_psw *psw)
{
	int		i;
	t_cost	low;
	t_cost	tmp;

	i = 0;
	low.cost = INT_MAX;
	low.cmds = NULL;
	while (i < psw->size_a)
	{
		tmp = get_cost(psw, i);
		tmp = simplify_cmds(&tmp);
		if (tmp.cost < low.cost)
		{
			if (low.cmds != NULL)
				free(low.cmds);
			low.cost = tmp.cost;
			low.cmds = ft_strdup(tmp.cmds);
		}
		free(tmp.cmds);
		i++;
	}
	return (low);
}
