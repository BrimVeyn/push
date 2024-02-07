/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_three.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-pae <bryan.vanpaemel@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:34:00 by bvan-pae          #+#    #+#             */
/*   Updated: 2023/12/20 17:23:03 by bvan-pae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

void	cycle(int *stack, int size)
{
	if (size <= 1)
		return ;
	while (size - 1)
	{
		stack[size - 1] = stack[size - 2];
		size--;
	}
}

void	rcycle(int *stack, int size)
{
	int	i;

	i = 0;
	if (size <= 1)
		return ;
	while (i < size)
	{
		stack[i] = stack[i + 1];
		i++;
	}
}

void	rr(t_psw *psw)
{
	ra(psw);
	rb(psw);
}

void	rrr(t_psw *psw)
{
	rra(psw);
	rrb(psw);
}
