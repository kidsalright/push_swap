/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 20:05:17 by yberries          #+#    #+#             */
/*   Updated: 2020/11/13 21:29:34 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_state *state)
{
	t_psl	*l;

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

int		main(int ac, char **av)
{
	t_state	state;

	if (ac > 1)
	{
		state.t = 1;
		args_to_stack(&state.a, (ac - 1), &av[1]);
		check_dups(state.a.start);
		start_alg(&state);
		free_ps(&state);
	}
	return (0);
}
