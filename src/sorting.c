/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 02:56:09 by yberries          #+#    #+#             */
/*   Updated: 2020/11/13 05:40:35 by yberries         ###   ########.fr       */
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

void	push_first(t_state *state)
{
	int	min;
	int	side;
	int	i;

	i = 0;
	while (state->a.start->next)
	{
		min = find_min(&state->a);
		side = choose_side(&state->a, min);
		if (side == 1)
			while (state->a.start->num != min)
				ra(state);
		else
			while (state->a.start->num != min)
				rra(state);
		pb(state);
		++i;
	}
	while (i--)
		pa(state);
}

void	push_last(t_state *state)
{
	int	max;
	int	side;

	while (state->b.start)
	{
		max = find_max(&state->b);
		side = choose_side(&state->b, max);
		if (side == 1)
			while (state->b.start->num != max)
				rb(state);
		else
			while (state->b.start->num != max)
				rrb(state);
		pa(state);
	}
}

void	heh_sort(t_state *state)
{
	int	med;
	int	i;

	set_index(state->a.start, state->a.len);
	med = state->a.len / 2;
	i = med;
	while (i)
	{
		if (state->a.start->index < med)
		{
			pb(state);
			--i;
		}
		else
			ra(state);
	}
	push_first(state);
	push_last(state);
}

int		find_from_bot(t_psl *l, int ind)
{
	int	i;

	i = 1;
	while (l)
	{
		if (l->index < ind)
			return (i);
		++i;
		l = l->prev;
	}
}

int		find_from_top(t_psl *l, int ind)
{
	int	i;

	i = 1;
	while (l)
	{
		if (l->index < ind)
			return (i);
		++i;
		l = l->next;
	}
}

void	put_chunk_tob(t_state *state, int ind, int counts)
{
	t_psl	*tmp;
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
		else
			try_chunks(state, 10);
	}
	new_out(state);
}
