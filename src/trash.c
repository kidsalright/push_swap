/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 15:45:30 by yberries          #+#    #+#             */
/*   Updated: 2020/11/10 22:41:10 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void    out_info(t_psl *tmp)
{
	while (tmp)
	{
		ft_printf("%-11d %4d   %s\n", tmp->num, tmp->index, (tmp->flag) ? "true" : "false");
		tmp = tmp->next;
	}
	write(1, "\n", 1);
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
		ft_printf("marking by head - %d\n", tmp->num);
		out_info(state->a.start);
		tmp = tmp->next;
	}
	ft_printf("so we've chosen %d head with %d numbers to keep in stack A, here it is\n", head, best);
	mark_increase(&state->a, head);
	out_info(state->a.start);
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
	out_res(state, "hah");
}

int             min_ind(t_psl *s)
{
	int     min;

	min = s->index;
	while (s)
	{
		if (s->index < min)
			min = s->index;
		s = s->next;
	}
	return (min);
}

void    try_algo(t_state *state)
{
	int     min;

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

	out_res(state, "hah");
}

int		find_min(t_stack *a)
{
	t_psl	*tmp;
	int		num;

	tmp = a->start;
	num = tmp->num;
	while (tmp->next)
	{
		if (tmp->next->num < num)
			num = tmp->next->num;
		tmp = tmp->next;
	}
	return (num);
}

int		choose_side(t_stack *a, int n)
{
	int		i;
	int		half;
	t_psl	*tmp;

	i = 0;
	tmp = a->start;
	half = a->len / 2;
	while (i <= half)
	{
		if (tmp->num == n)
			return (1);
		++i;
		tmp = tmp->next;
	}
	return (0);
}

void	fucking_sort(t_state *state)
{
	int	min;
	int	side;

	min = find_min(&state->a);
	side = choose_side(&state->a, min);
	if (side == 1)
	{
		while (state->a.start->num != min)
			ra(state);
	}
	else
	{
		while (state->a.start->num != min)
			rra(state);
	}
	pb(state);
	if (state->a.len != 0)
		fucking_sort(state);
	while (state->b.len != 0)
	{
		pa(state);
	}
}
