/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 23:45:44 by yberries          #+#    #+#             */
/*   Updated: 2020/10/11 03:53:39 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_exit()
{
		write(2, "Error\n", 6);
		exit(1);
}

void		out_res(t_pslist *sa, t_pslist *sb, char *instr)
{
		t_psl *ta;

		ta = sa->start;
		//	ft_printf("%s\n", instr);
		ft_printf("  Stack A  |  Stack B\n\n");
		while (ta)
		{
				ft_printf("%s%9d%s\n", CYN, ta->num, RES);
				ta = ta->next;
		}
}

