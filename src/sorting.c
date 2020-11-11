/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 02:56:09 by yberries          #+#    #+#             */
/*   Updated: 2020/11/12 00:48:06 by yberries         ###   ########.fr       */
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

t_psl	*partition_list(t_psl *l, t_psl *r)
{
	int		pivot;
	t_psl	*start;
	t_psl	*end;

	pivot = r->num;
	start = l->prev;
	end = l;
	while (end != r)
	{
		if (end->num <= pivot)
		{
			if (start == NULL)
				start = l;
			else
				start = start->next;
			swap(&(start->num), &(end->num));
		}
		end = end->next;
	}
	if (start == NULL)
		start = l;
	else
		start = start->next;
	swap(&(start->num), &(end->num));
	return (start);
}

void	quicksort_list(t_psl *l, t_psl *r, t_state *state)
{
	t_psl	*p;

	if (r != NULL && l != r && l != r->next)
	{
		out_res(state, "heh");
		p = partition_list(l, r);
		quicksort_list(l, p->prev, state);
		quicksort_list(p->next, r, state);
	}
}

void	quick_try(t_state *state, t_stack *curr, t_stack *other, int first, int last, char fin)
{
	int		med;
	int		len_curr;
	int		i;

	med = (first + last) / 2;
	i = med;
	while (i)
	{
		if (curr->start->index < med)
		{
			push(curr, other);
			--i;
		}
		rotate(curr);
		out_res(state, "heh");
	}
	quick_try(state, curr, other, med + 1, last, 1);
	quick_try(state, other, curr, first, med, 0);
}

void	sorting_algo(t_state *state)
{
	set_index(state->a.start, state->a.len);
	//	choose_best_head(state);
	quick_try(state, &state->a, &state->b, 0, state->a.len, 0);
	out_info(state->a.start);
//	quicksort_list(state->a.start, state->a.end, state);
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
		//		else if (state->a.len > 15)
		//			fucking_sort(state);
		else
			sorting_algo(state);
	}
	new_out(state);
}
