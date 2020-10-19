/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 23:45:44 by yberries          #+#    #+#             */
/*   Updated: 2020/10/19 02:59:21 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_exit()
{
		write(2, "Error\n", 6);
		exit(1);
}

void		clean_term(t_state *state)
{
		int	i;

		i = (state->a.len > state->b.len) ? state->a.len : state->b.len;
		i += 3;
		system("sleep 0.1");
		while (--i)
				ft_printf("\033[A\033[2K\r");
}

void		out_res(t_state *state, char *instr)
{
		t_psl	*tmpa;
		t_psl	*tmpb;

		ft_printf("     Option: %s%s%s\n", CYN, instr, RES);
		tmpa = (state->a.start) ? state->a.start : NULL;
		tmpb = (state->b.start) ? state->b.start : NULL;
		ft_printf("  Stack A  |  Stack B\n");
		while (tmpa && tmpb)
		{
				ft_printf("%s%9d%6d%s\n", CYN, tmpa->num, tmpb->num, RES);
				tmpa = tmpa->next;
				tmpb = tmpb->next;
		}
		while (tmpa)
		{
				ft_printf("%s%9d%s\n", CYN, tmpa->num, RES);
				tmpa = tmpa->next;
		}
		while (tmpb)
		{
				ft_printf("%s%15d%s\n", CYN, tmpb->num, RES);
				tmpb = tmpb->next;
		}
	//	clean_term(state);
}

void		output(t_state *state, char *instr)
{
		ft_printf("%s\n", instr);
}
