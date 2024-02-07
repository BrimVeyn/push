/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-pae <bryan.vanpaemel@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:27:49 by bvan-pae          #+#    #+#             */
/*   Updated: 2023/12/20 12:23:29 by bvan-pae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_mina(t_psw *psw, int el)
{
	int	i;

	i = 0;
	while (i < psw->size_a)
	{
		if (el > psw->stack_a[i])
			return (0);
		i++;
	}
	return (1);
}

int	is_maxa(t_psw *psw, int el)
{
	int	i;

	i = 0;
	while (i < psw->size_a)
	{
		if (el < psw->stack_a[i])
			return (0);
		i++;
	}
	return (1);
}

int	is_minb(t_psw *psw, int el)
{
	int	i;

	i = 0;
	while (i < psw->size_b)
	{
		if (el > psw->stack_b[i])
			return (0);
		i++;
	}
	return (1);
}

int	is_maxb(t_psw *psw, int el)
{
	int	i;

	i = 0;
	while (i < psw->size_b)
	{
		if (el < psw->stack_b[i])
			return (0);
		i++;
	}
	return (1);
}
