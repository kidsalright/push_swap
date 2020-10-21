/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 02:56:09 by yberries          #+#    #+#             */
/*   Updated: 2020/10/21 05:39:51 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	go(t_state *state)
{
	int	min;

	min = find_min(&state->a);
	while (state->a.start->num != min)
	{
		ra(state);
		ps_output("ra");
	}
	pb(state);
	ps_output("pb");
	if (state->a.len != 0)
			go(state);
	while (state->b.len != 0)
	{
		pa(state);
		ps_output("pa");
	}
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
				else
						go(state);
		}
}
