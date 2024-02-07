/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-pae <bryan.vanpaemel@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:13:06 by bvan-pae          #+#    #+#             */
/*   Updated: 2023/12/20 17:16:01 by bvan-pae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

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
