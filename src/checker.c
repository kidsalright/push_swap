/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 22:34:10 by yberries          #+#    #+#             */
/*   Updated: 2020/10/07 07:26:39 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
		t_pslist        sa;

		if (ac > 1)
		{
				args_to_stack(&sa, ac, &av[1]);
				pop_front(&sa);
				check_dups(sa.start);
				if (is_sorted(sa.start))
						ft_printf("OK\n");
				else
						ft_printf("KO\n");
				free_ps(sa.start);
		}
		else
				ft_exit();
		return (0);
}
