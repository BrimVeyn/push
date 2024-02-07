/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-pae <bryan.vanpaemel@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 09:32:40 by bvan-pae          #+#    #+#             */
/*   Updated: 2023/12/20 17:22:48 by bvan-pae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

void	ra(t_psw *psw)
{
	int	tmp;

	if (psw->size_a <= 1)
		return ;
	tmp = psw->stack_a[0];
	rcycle(psw->stack_a, psw->size_a);
	psw->stack_a[psw->size_a - 1] = tmp;
}

void	rb(t_psw *psw)
{
	int	tmp;

	if (psw->size_b <= 1)
		return ;
	tmp = psw->stack_b[0];
	rcycle(psw->stack_b, psw->size_b);
	psw->stack_b[psw->size_b - 1] = tmp;
}

void	rra(t_psw *psw)
{
	int	tmp;

	if (psw->size_a <= 1)
		return ;
	tmp = psw->stack_a[psw->size_a - 1];
	cycle(psw->stack_a, psw->size_a);
	psw->stack_a[0] = tmp;
}

void	rrb(t_psw *psw)
{
	int	tmp;

	if (psw->size_b <= 1)
		return ;
	tmp = psw->stack_b[psw->size_b - 1];
	cycle(psw->stack_b, psw->size_b);
	psw->stack_b[0] = tmp;
}
