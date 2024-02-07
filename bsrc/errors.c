/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-pae <bryan.vanpaemel@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:51:43 by bvan-pae          #+#    #+#             */
/*   Updated: 2023/12/21 08:43:24 by bvan-pae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

void	print_error(char *s, t_psw *psw)
{
	ft_putstr_fd(s, STDERR_FILENO);
	free(psw->stack_a);
	exit(EXIT_FAILURE);
}

void	print_error2(char *s, t_psw *psw, char *finalstr)
{
	ft_putstr_fd(s, STDERR_FILENO);
	free(psw->stack_a);
	free(psw->stack_b);
	free(finalstr);
	exit(EXIT_FAILURE);
}

void	exit_success(t_psw *psw, char *finalstr)
{
	free(finalstr);
	free(psw->stack_a);
	free(psw->stack_b);
	exit(EXIT_SUCCESS);
}

void	free_starstar(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
