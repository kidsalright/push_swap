/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 23:45:44 by yberries          #+#    #+#             */
/*   Updated: 2020/10/21 18:22:01 by yberries         ###   ########.fr       */
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
	i += 4;
	usleep(70000);
	while (--i)
		ft_printf("\033[A\033[K\r");
}

void		out_res(t_state *state, char *instr)
{
	t_psl	*tmpa;
	t_psl	*tmpb;

	ft_printf("       Option : %s%s%s\n", YEL, instr, RES);
	tmpa = (state->a.start) ? state->a.start : NULL;
	tmpb = (state->b.start) ? state->b.start : NULL;
	ft_printf("     Stack A  |  Stack B\n");
	while (tmpa && tmpb)
	{
		ft_printf("%s%12d%5s%d%s\n", CYN, tmpa->num, " ", tmpb->num, RES);
		tmpa = tmpa->next;
		tmpb = tmpb->next;
	}
	while (tmpa)
	{
		ft_printf("%s%12d%s\n", CYN, tmpa->num, RES);
		tmpa = tmpa->next;
	}
	while (tmpb)
	{
		ft_printf("%s%17s%d%s\n", CYN, " ", tmpb->num, RES);
		tmpb = tmpb->next;
	}
	ft_printf("%14s\033[32m%d%s\n", " ", state->counter++, RES);
}

void		ps_output(char *instr)
{
	ft_printf("%s\n", instr);
}
