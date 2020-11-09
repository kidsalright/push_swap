/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 02:56:09 by yberries          #+#    #+#             */
/*   Updated: 2020/11/09 17:49:54 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	out_info(t_psl *tmp)
{
	while (tmp)
	{
		ft_printf("%-11d %d   %s\n", tmp->num, tmp->index, (tmp->flag) ? "true" : "false");
		tmp = tmp->next;
	}
	write(1, "\n", 1);
}

void	choose_best_head(t_state *state)
{
	int		count;
	int		best;
	int		head;
	t_psl	*tmp;

	best = 0;
	tmp = state->a.start;
	while (tmp && (count = mark_increase(&state->a ,tmp->num)))
	{
		if (count > best)
		{
			best = count;
			head = tmp->num;
		}
		ft_printf("marking by head - %d\n", tmp->num);
		out_info(state->a.start);
		tmp = tmp->next;
	}
	ft_printf("so we've chosen %d head with %d numbers to keep in stack A, here it is\n", head, best);
	mark_increase(&state->a, head);
	out_info(state->a.start);
}

void	maybe_do_this_fucking_algo_dude(t_state *state)
{
	set_index(state->a.start, state->a.len);
	choose_best_head(state);
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
