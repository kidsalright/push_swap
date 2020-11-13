/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 02:56:09 by yberries          #+#    #+#             */
/*   Updated: 2020/11/13 17:57:00 by yberries         ###   ########.fr       */
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

void	put_chunk_tob(t_state *state, int ind, int counts)
{
	int		takebot;
	int		taketop;

	while (counts && state->a.start)
	{
		takebot = find_from_bot(state->a.end, ind);
		taketop = find_from_top(state->a.start, ind);
		if (taketop <= takebot)
			while ((state->a.start->index + 1) > ind)
				ra(state);
		else
			while ((state->a.start->index + 1) > ind)
				rra(state);
		pb(state);
		--counts;
	}
}

void	back_to_a(t_state *state)
{
	int	max;
	int	side;

	max = find_max(&state->b);
	while (state->b.start)
	{
		max = find_max(&state->b);
		side = (choose_side(&state->b, max));
		if (side)
			while (state->b.start->num != max)
				rb(state);
		else
			while (state->b.start->num != max)
				rrb(state);
		pa(state);
	}
}

void	try_chunks(t_state *state, int ver)
{
	int	chunk;
	int	part;
	int	rem;

	part = 1;
	set_index(state->a.start, state->a.len);
	chunk = state->a.len / ver + 1;
	rem = chunk;
	while (part <= ver)
	{
		chunk = rem;
		chunk *= part;
		put_chunk_tob(state, chunk, rem);
		++part;
	}
	back_to_a(state);
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
			put_res(state, SA);
		else if (state->a.len == 3)
			sort_three(state);
		else if (state->a.len < 150)
			try_chunks(state, 5);
		else if (state->a.len < 450)
			try_chunks(state, 10);
		else
			try_chunks(state, 14);
	}
	new_out(state);
}
