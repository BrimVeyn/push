/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-pae <bryan.vanpaemel@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:50:57 by bvan-pae          #+#    #+#             */
/*   Updated: 2023/12/21 14:59:56 by bvan-pae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_cost	*neither_helper(t_psw *psw, t_cost *low, int closest)
{
	if (psw->size_b == 2)
	{
		low->cmds = ft_strjoinfree(low->cmds, "sb\n");
		low->cost += 1;
	}
	else
	{
		if (closest <= psw->size_b - closest)
		{
			low->cmds = ft_mstrjoin(low->cmds, "rb\n", closest, 1);
			low->cost += closest;
		}
		else
		{
			low->cmds = ft_mstrjoin(low->cmds, "rrb\n", psw->size_b - closest,
					1);
			low->cost += psw->size_b - closest;
		}
		low->cmds = ft_strjoinfree(low->cmds, "pb\n");
		low->cost += 1;
	}
	return (low);
}

t_cost	neither_y(t_psw *psw, t_cost *low, int el)
{
	int	closest;

	closest = get_closestl(psw->stack_b, psw->size_b, el);
	if (!closest)
	{
		low->cmds = ft_strjoinfree(low->cmds, "pb\n");
		low->cost += 2;
	}
	else if (closest)
		neither_helper(psw, low, closest);
	return (*low);
}

char	*arrange_a(t_psw *psw)
{
	char	*finalstr;
	int		clo;

	finalstr = NULL;
	clo = get_closesth(psw->stack_a, psw->size_a, psw->stack_b[0]);
	if (clo == 0)
	{
		pa(psw);
		return (ft_strdup("pa\n"));
	}
	if (clo <= psw->size_a - clo)
	{
		finalstr = ft_mstrjoin(ft_strdup(""), "ra\n", clo, 1);
		while (clo--)
			ra(psw);
	}
	else
	{
		finalstr = ft_mstrjoin(ft_strdup(""), "rra\n", psw->size_a - clo, 1);
		while (psw->size_a - clo++)
			rra(psw);
	}
	finalstr = ft_mstrjoin(finalstr, "pa\n", 1, 1);
	pa(psw);
	return (finalstr);
}

char	*get_ltotop(t_psw *psw)
{
	int		imin;
	char	*finalstr;

	imin = get_imina(psw);
	if (imin == 0)
		return (ft_strdup(""));
	if (imin <= psw->size_a - imin)
	{
		finalstr = ft_mstrjoin(ft_strdup(""), "ra\n", imin, 1);
		while (imin--)
			ra(psw);
	}
	else
	{
		finalstr = ft_mstrjoin(ft_strdup(""), "rra\n", psw->size_a - imin, 1);
		while (psw->size_a - imin++)
			rra(psw);
	}
	return (finalstr);
}

char	*to_b(t_psw *psw, char *finalstr)
{
	t_cost	lowest;

	lowest.cost = -1;
	lowest.cmds = NULL;
	while (psw->size_a > 3)
	{
		get_minmax_b(psw);
		lowest = get_lowest_cost(psw);
		finalstr = ft_strjoinfree(finalstr, lowest.cmds);
		execute_string(psw, lowest.cmds);
		free(lowest.cmds);
	}
	return (finalstr);
}
