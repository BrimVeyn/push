/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-pae <bryan.vanpaemel@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 08:23:07 by bvan-pae          #+#    #+#             */
/*   Updated: 2023/12/21 15:00:03 by bvan-pae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_imina(t_psw *psw)
{
	int	i;
	int	tmp;
	int	i_tmp;

	i = 0;
	i_tmp = 0;
	tmp = INT_MAX;
	while (i < psw->size_a)
	{
		if (psw->stack_a[i] <= tmp)
		{
			i_tmp = i;
			tmp = psw->stack_a[i];
		}
		i++;
	}
	return (i_tmp);
}

char	*turkish_h(t_psw *psw)
{
	char	*finalstr;

	if (psw->size_a == 4)
	{
		pb(psw);
		finalstr = ft_strdup("pb\n");
	}
	else
	{
		pb(psw);
		pb(psw);
		finalstr = ft_strdup("pb\npb\n");
	}
	return (finalstr);
}

char	*turkish(t_psw *psw)
{
	char	*finalstr;
	char	*threestr;
	char	*arranged;
	char	*get;

	finalstr = turkish_h(psw);
	finalstr = to_b(psw, finalstr);
	if (check_sorted(psw) == 0)
	{
		threestr = three_sort(psw->stack_a, psw);
		finalstr = ft_strjoinfree(finalstr, threestr);
		free(threestr);
	}
	while (psw->size_b)
	{
		arranged = arrange_a(psw);
		finalstr = ft_strjoinfree(finalstr, arranged);
		free(arranged);
	}
	get = get_ltotop(psw);
	finalstr = ft_mstrjoin(finalstr, get, 1, 1);
	free(get);
	return (finalstr);
}

char	*sort(t_psw *psw)
{
	char	*finalstr;

	if (psw->size_a == 2)
	{
		finalstr = ft_strdup("sa\n");
		sa(psw);
	}
	else if (psw->size_a == 3)
		finalstr = three_sort(psw->stack_a, psw);
	else
		finalstr = turkish(psw);
	return (finalstr);
}

int	main(int ac, char *av[])
{
	t_psw	psw;
	char	*finalstr;

	psw.size_a = ac - 1;
	if (ac < 2)
		exit(EXIT_FAILURE);
	psw.stack_a = get_stacka(ac, av, &psw);
	if (check_duplicates(psw.stack_a, psw.size_a) == -1)
		print_error("Error\n", &psw);
	init_stack_b(&psw);
	if (check_sorted(&psw) == 0)
	{
		finalstr = sort(&psw);
		ft_printf("%s", finalstr);
		free_exit(&psw, finalstr);
	}
	else
		exit_success(&psw);
	return (1);
}
