/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-pae <bryan.vanpaemel@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:46:14 by bvan-pae          #+#    #+#             */
/*   Updated: 2023/12/20 14:52:06 by bvan-pae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

int	ft_notatoi(const char *nptr, t_psw *psw)
{
	int			i;
	int			neg;
	long long	res;

	i = 0;
	res = 0;
	neg = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg = -neg;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + nptr[i] - '0';
		i++;
	}
	if (res > INT_MAX || res < INT_MIN)
		print_error("Error\n", psw);
	return (res * neg);
}

int	*get_stacka(int ac, char *av[], t_psw *psw)
{
	int	i;
	int	*stack_a;

	i = 1;
	stack_a = ft_calloc(ac, sizeof(int));
	while (i < ac)
	{
		if (is_strdigit(av[i]))
		{
			stack_a[i - 1] = ft_notatoi(av[i], psw);
		}
		else
		{
			free(stack_a);
			ft_putstr_fd("Erorr\n", STDERR_FILENO);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (stack_a);
}

int	check_sorted(t_psw *psw)
{
	int	i;

	i = 0;
	while (i < psw->size_a - 1)
	{
		if (psw->stack_a[i] > psw->stack_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	is_strdigit(char *s)
{
	size_t	i;

	i = -1;
	while (s[++i])
	{
		if (i != 0 && s[i] == '-')
			return (0);
		else if ((s[i] < '0' || s[i] > '9') && s[i] != '-')
			return (0);
		if (i == 0 && s[i] == '-' && !s[i + 1])
			return (0);
	}
	return (1);
}
