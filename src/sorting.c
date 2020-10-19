/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 02:56:09 by yberries          #+#    #+#             */
/*   Updated: 2020/10/18 21:42:03 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	start_alg(t_state *state)
{
		state->b.start = NULL;
		state->b.end = NULL;
		state->b.len = 0;
		pb(state);
		output(state, "pb");
		pb(state);
		output(state, "pb");
		pb(state);
		output(state, "pb");
		pb(state);
		output(state, "pb");
		pb(state);
		output(state, "pb");
		pb(state);
		output(state, "pb");
		ra(state);
		output(state, "ra");
		ra(state);
		output(state, "ra");
		ra(state);
		output(state, "ra");
		pa(state);
		output(state, "pa");
		pa(state);
		output(state, "pa");
		pa(state);
		output(state, "pa");
		pa(state);
		output(state, "pa");
		pa(state);
		output(state, "pa");
		pa(state);
		output(state, "pa");
		rra(state);
		output(state, "rra");
		rra(state);
		output(state, "rra");
}
