/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 20:05:17 by yberries          #+#    #+#             */
/*   Updated: 2020/10/09 04:31:32 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	output_stack(t_pslist *sa, t_pslist *sb)
{
		t_psl *ta;

		ta = sa->start;
		ft_printf("stack A:  |  stack B:\n\n");
		while (ta)
		{
				ft_printf("%10d|\n", ta->num);
				ta = ta->next;
		}
}

int		main(int ac, char **av)
{
		t_pslist	sa;
		int			i;

		if (ac > 1)
		{
				args_to_stack(&sa, ac, &av[1]);
				pop_front(&sa);
				check_dups(sa.start);
				start_alg(&sa);
				while (1)
				{
						i = sa.len + 3;
						output_stack(&sa, NULL);
						system("sleep 0.2");
						push_end(&sa, rand());
						pop_front(&sa);
						while (--i)
						{
								ft_printf("\033[A\33[2K\r");
								//	ft_printf("\033[A\33[2K\r");
						}
				}
				free_ps(sa.start);
		}
		else
				ft_exit();
		return (0);
}
