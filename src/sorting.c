/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 02:56:09 by yberries          #+#    #+#             */
/*   Updated: 2020/10/20 07:38:57 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		}
}
