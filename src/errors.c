/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-pae <bryan.vanpaemel@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 08:46:34 by bvan-pae          #+#    #+#             */
/*   Updated: 2023/12/20 13:53:30 by bvan-pae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_error(char *s, t_psw *psw)
{
	ft_putstr_fd(s, STDERR_FILENO);
	free(psw->stack_a);
	exit(EXIT_FAILURE);
}

void	exit_success(t_psw *psw)
{
	free(psw->stack_a);
	free(psw->stack_b);
	exit(EXIT_SUCCESS);
}

void	free_exit(t_psw *psw, char *finalstr)
{
	free(finalstr);
	free(psw->stack_a);
	free(psw->stack_b);
	exit(EXIT_FAILURE);
}
