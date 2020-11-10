/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 02:56:09 by yberries          #+#    #+#             */
/*   Updated: 2020/11/10 19:19:05 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_psl *l)
{
	if (l->num > l->next->num && l->next->num < l->next->next->num && \
			l->next->next->num > l->num)
		ps_output("sa");
	if (l->num > l->next->num && l->next->num > l->next->next->num && \
			l->next->next->num < l->num)
	{
		ps_output("sa");
		ps_output("rra");
	}
	if (l->num > l->next->num && l->next->num < l->next->next->num && \
			l->next->next->num < l->num)
		ps_output("ra");
	if (l->num < l->next->num && l->next->num > l->next->next->num && \
			l->next->next->num > l->num)
	{
		ps_output("sa");
		ps_output("ra");
	}
	if (l->num < l->next->num && l->next->num > l->next->next->num && \
			l->next->next->num < l->num)
		ps_output("rra");
}

void	out_info(t_psl *tmp)
{
	while (tmp)
	{
		ft_printf("%-11d %4d   %s\n", tmp->num, tmp->index, (tmp->flag) ? "true" : "false");
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
		//		ft_printf("marking by head - %d\n", tmp->num);
		//		out_info(state->a.start);
		tmp = tmp->next;
	}
	//	ft_printf("so we've chosen %d head with %d numbers to keep in stack A, here it is\n", head, best);
	mark_increase(&state->a, head);
	//	out_info(state->a.start);
	count = state->a.len - best;
	while (count)
	{
		tmp = state->a.start;
		if (tmp->flag == 0)
		{
			pb(state);
			ps_output("pb");
			--count;
		}
		else
		{
			ra(state);
			ps_output("ra");
		}
	}
	//	out_res(state, "hah");
}

int		min_ind(t_psl *s)
{
	int	min;

	min = s->index;
	while (s)
	{
		if (s->index < min)
			min = s->index;
		s = s->next;
	}
	return (min);
}

void	try_algo(t_state *state)
{
	int	min;

	while (state->b.len != 1)
	{
		min = min_ind(state->b.start);
		while (state->b.start->index != min)
		{
			rb(state);
			ps_output("rb");
		}
		min = min_ind(state->a.start);
		while (state->a.start->index != min)
		{
			ra(state);
			ps_output("ra");
		}
		pa(state);
		ps_output("pa");
		sa(state);
		ps_output("sa");
	}
	while (!is_sorted(state->a.start))
	{
		ra(state);
		ps_output("ra");
	}
	rra(state);
	ps_output("rra");
	pa(state);
	ps_output("pa");
	ra(state);
	ps_output("ra");
	ra(state);
	ps_output("ra");

	//	out_res(state, "hah");
}

void	sorting_algo(t_state *state)
{
	set_index(state->a.start, state->a.len);
	choose_best_head(state);
	try_algo(state);
}

void	start_alg(t_state *state)
{
	state->b.start = NULL;
	state->b.end = NULL;
	state->b.len = 0;
	if (!is_sorted(state->a.start))
	{
		if (state->a.len < 3)
			ps_output("sa");
		else if (state->a.len == 3)
			sort_three(state->a.start);
		else if (state->a.len > 40)
			fucking_sort(state);
		else
			sorting_algo(state);
	}
}
