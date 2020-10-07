/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 20:05:17 by yberries          #+#    #+#             */
/*   Updated: 2020/10/07 07:20:08 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	out_reverse(t_psl *s)
{
		ft_printf("from end\n");
		while (s->prev)
		{
				ft_printf("%d\n", s->num);
				s = s->prev;
		}
		ft_printf("%d\n", s->num);
}

void	output_stack(t_psl *s)
{
		ft_printf("stack A:\n");
		while (s)
		{
				ft_printf("%d\n", s->num);
				s = s->next;
		}
}

int		main(int ac, char **av)
{
		t_pslist	sa;

		if (ac > 1)
		{
				args_to_stack(&sa, ac, &av[1]);
				pop_front(&sa);
				check_dups(sa.start);
				start_alg(&sa);
				output_stack(sa.start);
				free_ps(sa.start);
		}
		else
				ft_exit();
		return (0);
}
