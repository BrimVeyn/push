/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-pae <bryan.vanpaemel@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 08:24:17 by bvan-pae          #+#    #+#             */
/*   Updated: 2023/12/20 14:01:29 by bvan-pae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../pf_libft/include/pf_ft_printf.h"
# include <fcntl.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_data
{
	char	**rrr;
	char	**nrrr;
	int		*nn;

}			t_data;

typedef struct s_psw
{
	int		*stack_a;
	int		*stack_b;
	int		size_a;
	int		size_b;
	int		b_min;
	int		b_max;
	t_data	data;

}			t_psw;

typedef struct s_cost
{
	int		cost;
	char	*cmds;

}			t_cost;

typedef struct s_rr
{
	char	*ptr;
	int		ra;
	int		rb;
	int		rra;
	int		rrb;

}			t_rr;

int			*ps_strncmp(const char *s1, const char *s2, int n);
int			get_lowest(int a, int b);
void		free_exit(t_psw *psw, char *finalstr);
int			get_imina(t_psw *psw);
t_cost		maxb_y(t_psw *psw, t_cost *low);
t_cost		minb_y(t_psw *psw, t_cost *low);
t_data		init_data(void);
t_cost		get_cost(t_psw *psw, int index);
t_cost		simplify_cmds(t_cost *tmp);
t_cost		get_lowest_cost(t_psw *psw);
t_cost		neither_y(t_psw *psw, t_cost *low, int el);
t_cost		get_ftotop(t_psw *psw, int index, t_cost *low);
int			is_strdigit(char *s);
int			is_mina(t_psw *psw, int el);
int			is_minb(t_psw *psw, int el);
int			is_maxa(t_psw *psw, int el);
int			is_maxb(t_psw *psw, int el);
int			is_hontopb(t_psw *psw);
int			is_lontopb(t_psw *psw);
int			d_htotopb(t_psw *psw);
int			d_htotopa(t_psw *psw);
int			d_htobtma(t_psw *psw);
int			d_htobtmb(t_psw *psw);
int			d_ctobtmb(t_psw *psw, int i_c);
int			d_ctotopb(int i_c);
int			*get_stacka(int ac, char *av[], t_psw *psw);
int			get_closest(int *stack, int sstack, int el);
int			get_closesth(int *stack, int sstack, int el);
int			get_closestl(int *stack, int sstack, int el);
int			check_duplicates(int *stack_a, size_t size);
int			check_sorted(t_psw *psw);
int			ps_strchr(char *s1, char *s2, int len);
int			ps_strcmp(char *s1, char *s2);
char		*delrn(char *cmds, int opt);
char		*newstr(char *cmds, int opt, int *res);
char		*three_sort(int *stack, t_psw *psw);
char		*get_ltotop(t_psw *psw);
char		*to_b(t_psw *psw, char *finalstr);
char		*ps_strchange(char *cmds, int opt, int nb);
char		*arrange_a(t_psw *psw);
char		*ft_mstrjoin(const char *fstr, char *a_str, int n, int p);
void		sa(t_psw *psw);
void		sb(t_psw *psw);
void		ss(t_psw *psw);
void		pa(t_psw *psw);
void		pb(t_psw *psw);
void		ra(t_psw *psw);
void		rb(t_psw *psw);
void		rr(t_psw *psw);
void		rra(t_psw *psw);
void		rrb(t_psw *psw);
void		rrr(t_psw *psw);
void		get_minmax_b(t_psw *psw);
void		cycle(int *stack, int size);
void		rcycle(int *stack, int size);
void		print_error(char *s, t_psw *psw);
void		exit_success(t_psw *psw);
void		init_stack_b(t_psw *psw);
void		execute_string(t_psw *psw, char *str);
void		execute_helper(t_psw *psw, char *str);

#endif
