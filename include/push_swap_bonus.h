/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-pae <bryan.vanpaemel@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:48:08 by bvan-pae          #+#    #+#             */
/*   Updated: 2023/12/21 08:42:54 by bvan-pae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../pf_libft/include/pf_ft_printf.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_psw
{
	int	*stack_a;
	int	*stack_b;
	int	size_a;
	int	size_b;
	int	b_min;
	int	b_max;

}		t_psw;

int		ft_notatoi(const char *nptr, t_psw *psw);
int		*get_stacka(int ac, char *av[], t_psw *psw);
int		check_sorted(t_psw *psw);
int		is_strdigit(char *s);
int		ps_strcmp(char *s1, char *s2);
void	execute_string(t_psw *psw, char *str);
void	print_error(char *s, t_psw *psw);
void	print_error2(char *s, t_psw *psw, char *finalstr);
int		check_duplicates(int *stack_a, size_t size);
void	exit_success(t_psw *psw, char *finalstr);
void	init_stack_b(t_psw *psw);
char	*ft_mstrjoin(const char *fstr, char *a_str, int n, int p);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	free_starstar(char **tab);
void	sa(t_psw *psw);
void	sb(t_psw *psw);
void	ss(t_psw *psw);
void	pa(t_psw *psw);
void	pb(t_psw *psw);
void	ra(t_psw *psw);
void	rb(t_psw *psw);
void	rr(t_psw *psw);
void	rra(t_psw *psw);
void	rrb(t_psw *psw);
void	rrr(t_psw *psw);
void	cycle(int *stack, int size);
void	rcycle(int *stack, int size);

#endif
