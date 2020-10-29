/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 20:05:17 by yberries          #+#    #+#             */
/*   Updated: 2020/10/24 13:42:35 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	t_state	state;

	if (ac > 1)
	{
		args_to_stack(&state.a, (ac - 1), &av[1]);
		check_dups(state.a.start);
		start_alg(&state);
		free_ps(&state);
	}
	return (0);
}
