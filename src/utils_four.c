/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_four.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-pae <bryan.vanpaemel@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:40:31 by bvan-pae          #+#    #+#             */
/*   Updated: 2023/12/20 12:13:01 by bvan-pae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	find_min(int *stack, int sstack)
{
	int	tmp_c;
	int	i;
	int	index_c;

	tmp_c = INT_MAX;
	i = 0;
	while (i < sstack)
	{
		if (stack[i] < tmp_c)
		{
			tmp_c = stack[i];
			index_c = i;
		}
		i++;
	}
	return (index_c);
}

int	find_max(int *stack, int sstack)
{
	int	tmp_c;
	int	i;
	int	index_c;

	tmp_c = INT_MIN;
	i = 0;
	index_c = 0;
	while (i < sstack)
	{
		if (stack[i] > tmp_c)
		{
			tmp_c = stack[i];
			index_c = i;
		}
		i++;
	}
	return (index_c);
}

int	get_closesth(int *stack, int sstack, int el)
{
	int	i;
	int	tmp_c;
	int	index_c;
	int	delta;

	i = 0;
	index_c = -1;
	delta = INT_MAX;
	tmp_c = INT_MAX;
	while (i < sstack)
	{
		if (stack[i] <= tmp_c && stack[i] > el && stack[i] - el < delta)
		{
			delta = stack[i] - el;
			tmp_c = stack[i];
			index_c = i;
		}
		i++;
	}
	if (index_c == -1)
		index_c = find_min(stack, sstack);
	return (index_c);
}

int	get_closestl(int *stack, int sstack, int el)
{
	int	i;
	int	tmp_c;
	int	index_c;
	int	delta;

	i = 0;
	index_c = -1;
	delta = INT_MAX;
	tmp_c = INT_MIN;
	while (i < sstack)
	{
		if (stack[i] >= tmp_c && stack[i] < el && el - stack[i] < delta)
		{
			delta = el - stack[i];
			tmp_c = stack[i];
			index_c = i;
		}
		i++;
	}
	if (index_c == -1)
		index_c = find_max(stack, sstack);
	return (index_c);
}
