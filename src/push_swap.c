/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 20:05:17 by yberries          #+#    #+#             */
/*   Updated: 2020/10/11 03:01:11 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
		t_pslist	sa;

		if (ac > 1)
		{
				sa.vis = (av[1][0] == '-' && av[1][1] == 'v') ? 2 : 1;
				args_to_stack(&sa, (ac - (int)sa.vis), &av[(int)sa.vis]);
				pop_front(&sa);
				check_dups(sa.start);
				start_alg(&sa);
				free_ps(sa.start);
		}
		return (0);
}
