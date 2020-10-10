/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 23:45:44 by yberries          #+#    #+#             */
/*   Updated: 2020/10/11 00:12:22 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_exit()
{
		write(2, "Error\n", 6);
		exit(1);
}

void    output_visual(t_pslist *sa, t_pslist *sb, char *instr)
{
		t_psl *ta;

		ta = sa->start;
		ft_printf("  Stack A  |  Stack B\n\n");
		while (ta)
		{
				ft_printf("%s%9d%s\n", CYN, ta->num, RES);
				ta = ta->next;
		}
}

void	out_res(char *instr)
{
	ft_printf("%s\n", instr);
}

void		ft_output(t_pslist *sa, t_pslist *sb, char vis)
{
		int                     i;
		int                     stop;
		char            *str = "sa";
		char            *str2 = "sb";
		char            *tmp;
		int                     n;

		n = 1;
		stop = 2;
		if (vis == 2)
		{
				while (stop)
				{
						i = rand();
						i /= 10000000;
						if (n == 1)
						{
								tmp = str;
								++n;
						}
						else
						{
								tmp = str2;
								--n;
						}
						ft_printf("   Instruction: %s%s%s\n", CYN, tmp, RES);
						output_visual(sa, NULL, "sa");
						system("sleep 0.1");
						push_end(sa, i);
						pop_front(sa);
						i = sa->len + 4;
						if (stop == 1)
								break;
						if (is_sorted(sa->start))
								--stop;
						while (--i)
								ft_printf("\033[A\33[2K\r");

				}
		}
		else
		{
				out_res("sa");
		}
		return (0);
}
