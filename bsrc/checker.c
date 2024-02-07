/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-pae <bryan.vanpaemel@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:35:03 by bvan-pae          #+#    #+#             */
/*   Updated: 2023/12/23 09:54:17 by bvan-pae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

int	check_validity(char *finalstr)
{
	char	*ptr;

	ptr = finalstr;
	while (1)
	{
		if (!ft_strncmp(ptr, "ra\n", 3) || !ft_strncmp(ptr, "rb\n", 3)
			|| !ft_strncmp(ptr, "sa\n", 3) || !ft_strncmp(ptr, "sb\n", 3)
			|| !ft_strncmp(ptr, "ss\n", 3) || !ft_strncmp(ptr, "pa\n", 3)
			|| !ft_strncmp(ptr, "pb\n", 3) || !ft_strncmp(ptr, "rr\n", 3))
			ptr += 3;
		else if (!ft_strncmp(ptr, "rra\n", 4) || !ft_strncmp(ptr, "rrb\n", 4)
			|| !ft_strncmp(ptr, "rrr\n", 4))
			ptr += 4;
		else if (*ptr == 0)
			return (1);
		else
			return (-1);
	}
}

char	*gnl_read(int fd, t_psw *psw)
{
	char	*tmp;
	char	*finalstr;

	finalstr = ft_calloc(1, 1);
	tmp = "";
	while (tmp)
	{
		tmp = get_next_line(fd);
		finalstr = ft_mstrjoin(finalstr, tmp, 1, 1);
		free(tmp);
		if (check_validity(finalstr) == -1)
			print_error2("Error\n", psw, finalstr);
	}
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
	finalstr = gnl_read(STDIN_FILENO, &psw);
	execute_string(&psw, finalstr);
	if (check_sorted(&psw) == 0 || psw.size_b != 0)
	{
		ft_printf("KO\n");
		exit_success(&psw, finalstr);
	}
	else
	{
		ft_printf("OK\n");
		exit_success(&psw, finalstr);
	}
	return (1);
}
