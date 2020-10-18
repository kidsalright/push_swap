/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 20:05:17 by yberries          #+#    #+#             */
/*   Updated: 2020/10/18 09:44:35 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
		t_state	state;

		if (ac > 1)
		{
				state.vis = (av[1][0] == '-' && av[1][1] == 'v') ? 2 : 1;
				args_to_stack(&state.a, (ac - (int)state.vis), &av[(int)state.vis]);
				check_dups(state.a.start);
				start_alg(&state);
				out_res(&state);
				free_ps(&state);
		}
		return (0);
}
