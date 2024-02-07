/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-pae <bryan.vanpaemel@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 08:57:29 by bvan-pae          #+#    #+#             */
/*   Updated: 2023/12/20 17:22:34 by bvan-pae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

void	sa(t_psw *psw)
{
	int	tmp;

	if (psw->size_a >= 2)
	{
		tmp = psw->stack_a[1];
		psw->stack_a[1] = psw->stack_a[0];
		psw->stack_a[0] = tmp;
	}
}

void	sb(t_psw *psw)
{
	int	tmp;

	if (psw->size_b >= 2)
	{
		tmp = psw->stack_b[1];
		psw->stack_b[1] = psw->stack_b[0];
		psw->stack_b[0] = tmp;
	}
}

void	ss(t_psw *psw)
{
	sa(psw);
	sb(psw);
}

void	pa(t_psw *psw)
{
	if (psw->size_b > 0)
	{
		psw->size_a += 1;
		cycle(psw->stack_a, psw->size_a);
		psw->stack_a[0] = psw->stack_b[0];
		rcycle(psw->stack_b, psw->size_b);
		psw->size_b -= 1;
	}
}

void	pb(t_psw *psw)
{
	if (psw->size_a > 0)
	{
		psw->size_b += 1;
		cycle(psw->stack_b, psw->size_b);
		psw->stack_b[0] = psw->stack_a[0];
		rcycle(psw->stack_a, psw->size_a);
		psw->size_a -= 1;
	}
}
