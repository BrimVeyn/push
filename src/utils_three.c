/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-pae <bryan.vanpaemel@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:39:29 by bvan-pae          #+#    #+#             */
/*   Updated: 2023/12/18 17:12:47 by bvan-pae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_hontopb(t_psw *psw)
{
	int	i;

	i = 0;
	while (i < psw->size_b)
	{
		if (psw->stack_b[0] < psw->stack_b[i])
			return (0);
		i++;
	}
	return (1);
}

int	is_lontopb(t_psw *psw)
{
	int	i;

	i = 0;
	while (i < psw->size_b)
	{
		if (psw->stack_b[0] > psw->stack_b[i])
			return (0);
		i++;
	}
	return (1);
}

int	d_ctotopb(int i_c)
{
	return (i_c);
}

int	d_ctobtmb(t_psw *psw, int i_c)
{
	return (psw->size_b - i_c);
}
