/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 02:56:09 by yberries          #+#    #+#             */
/*   Updated: 2020/10/30 18:15:16 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	out_info(t_psl *tmp)
{
	while (tmp)
	{
		ft_printf("%-5d %d   %s\n", tmp->num, tmp->index, (tmp->flag) ? "true" : "false");
		tmp = tmp->next;
	}
}

void	set_index(t_psl *list, int len)
{
	int		i;
	int		*tab;
	t_psl	*tmp;

	tmp = list;
	tab = (int *)malloc(sizeof(int) * len);
	i = -1;
	while (++i < len)
	{
		tab[i] = tmp->num;
		tmp = tmp->next;
	}
	ft_quicksort(tab, 0, len - 1);
	tmp = list;
	while (tmp)
	{
		i = -1;
		while (tmp->num != tab[i])
			++i;
		tmp->index = i;
		tmp = tmp->next;
	}
}

void	maybe_do_this_fucking_algo_dude(t_state *state)
{
	t_psl *tmp;

	set_index(state->a.start, state->a.len);
	tmp = state->a.start;
	marking(&state->a);
	out_info(state->a.start);
}

void	start_alg(t_state *state)
{
	state->b.start = NULL;
	state->b.end = NULL;
	state->b.len = 0;
	if (!is_sorted(state->a.start))
	{
		if (state->a.len < 3)
		{
			sa(state);
			ps_output("sa");
		}
		if (state->a.len > 15)
			fucker_sort(state);
		else
			maybe_do_this_fucking_algo_dude(state);
	}
}
