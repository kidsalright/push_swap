/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 20:05:17 by yberries          #+#    #+#             */
/*   Updated: 2020/10/11 00:03:30 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
		t_pslist	sa;
		int		vis;

		if (ac > 1)
		{
				vis = (av[1][0] == '-' && av[1][1] == 'v') ? 2 : 1;
				args_to_stack(&sa, (ac - vis), &av[vis]);
				pop_front(&sa);
				check_dups(sa.start);
				start_alg(&sa);
				ft_output(&sa, NULL, vis);
				free_ps(sa.start);
		}
		else
				ft_exit();
		return (0);
}
