/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplify.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-pae <bryan.vanpaemel@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:24:49 by bvan-pae          #+#    #+#             */
/*   Updated: 2023/12/21 08:27:41 by bvan-pae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	*ps_strchange(char *cmds, int opt, int nb)
{
	char	*new;
	char	*nr;
	char	*p2;
	int		nbnr;
	int		i;

	if (!nb)
		return (cmds);
	if (opt == 0)
		nr = "rr\n";
	else
		nr = "rrr\n";
	nbnr = ft_strlen(nr) * nb;
	new = ft_calloc(nbnr + (ft_strlen(cmds) - (ft_strlen(nr) * nb * 2)) + 1,
			sizeof(char));
	i = -1;
	while (nbnr-- && ++i >= 0)
		new[i] = nr[i % ft_strlen(nr)];
	p2 = delrn(cmds, opt);
	new = ft_mstrjoin(new, p2, 1, 1);
	free(p2);
	return (new);
}

t_rr	init_rr(char *cmds)
{
	t_rr	data;

	data.ra = 0;
	data.rb = 0;
	data.rra = 0;
	data.rrb = 0;
	data.ptr = cmds;
	return (data);
}

char	*simplify_h2(t_rr *data)
{
	while (1)
	{
		if (ft_strncmp(data->ptr, "rra\n", 4) == 0)
		{
			data->ptr += 4;
			data->rra += 1;
			return ("");
		}
		else if (ft_strncmp(data->ptr, "rrb\n", 4) == 0)
		{
			data->ptr += 4;
			data->rrb += 1;
			return ("");
		}
		else
			break ;
	}
	return (NULL);
}

t_rr	simplify_h(t_rr *data)
{
	while (1)
	{
		if (ft_strncmp(data->ptr, "ra\n", 3) == 0)
		{
			data->ptr += 3;
			data->ra += 1;
		}
		else if (ft_strncmp(data->ptr, "rb\n", 3) == 0)
		{
			data->ptr += 3;
			data->rb += 1;
		}
		else if (simplify_h2(data) == NULL)
			break ;
	}
	return (*data);
}

t_cost	simplify_cmds(t_cost *tmp)
{
	t_rr	data;

	data = init_rr(tmp->cmds);
	data = simplify_h(&data);
	data.ra = get_lowest(data.ra, data.rb);
	data.rra = get_lowest(data.rra, data.rrb);
	tmp->cmds = ps_strchange(tmp->cmds, 0, data.ra);
	tmp->cmds = ps_strchange(tmp->cmds, 1, data.rra);
	tmp->cost = tmp->cost - data.ra - data.rra;
	return (*tmp);
}
