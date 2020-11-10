/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 02:56:09 by yberries          #+#    #+#             */
/*   Updated: 2020/11/11 02:36:59 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_state *state)
{
	t_psl *l;

	l = state->a.start;
	if (l->num > l->next->num && l->next->num < l->next->next->num && \
			l->next->next->num > l->num)
		put_res(state, SA);
	if (l->num > l->next->num && l->next->num > l->next->next->num && \
			l->next->next->num < l->num)
	{
		put_res(state, SA);
		put_res(state, RRA);
	}
	if (l->num > l->next->num && l->next->num < l->next->next->num && \
			l->next->next->num < l->num)
		put_res(state, RA);
	if (l->num < l->next->num && l->next->num > l->next->next->num && \
			l->next->next->num > l->num)
	{
		put_res(state, SA);
		put_res(state, RA);
	}
	if (l->num < l->next->num && l->next->num > l->next->next->num && \
			l->next->next->num < l->num)
		put_res(state, RRA);
}

void    choose_best_head(t_state *state)
{
	int             count;
	int             best;
	int             head;
	t_psl   *tmp;

	best = 0;
	tmp = state->a.start;
	while (tmp && (count = mark_increase(&state->a ,tmp->num)))
	{
		if (count > best)
		{
			best = count;
			head = tmp->num;
		}
		tmp = tmp->next;
	}
	mark_increase(&state->a, head);
	count = state->a.len - best;
	while (count)
	{
		tmp = state->a.start;
		if (tmp->flag == 0)
		{
			pb(state);
			--count;
		}
		else
		{
			ra(state);
		}
	}
}

void	sorting_algo(t_state *state)
{
	set_index(state->a.start, state->a.len);
//	choose_best_head(state);
	out_info(state->a.start);
//	try_qsort(&state->a, &state->b, 0, state->a.len, 0);
	out_res(state, "heh");
}

void	start_alg(t_state *state)
{
	state->res = NULL;
	state->b.start = NULL;
	state->b.end = NULL;
	state->b.len = 0;
	if (!is_sorted(state->a.start))
	{
		if (state->a.len < 3)
			ps_output("sa");
		else if (state->a.len == 3)
			sort_three(state);
		else if (state->a.len > 15)
			fucking_sort(state);
		else
			sorting_algo(state);
	}
	new_out(state);
}
