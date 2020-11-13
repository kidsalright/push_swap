/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 23:45:44 by yberries          #+#    #+#             */
/*   Updated: 2020/11/13 06:45:41 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void		put_res(t_state *state, int i)
{
	t_inst	*tmp;
	t_inst	*head;

	head = state->res;
	if (!head)
	{
		if (!(head = (t_inst *)malloc(sizeof(t_inst))))
			ft_exit();
		head->opt = i;
		head->next = NULL;
	}
	else
	{
		tmp = head;
		while (tmp->next)
			tmp = tmp->next;
		if (!(tmp->next = (t_inst *)malloc(sizeof(t_inst))))
			ft_exit();
		tmp->next->opt = i;
		tmp->next->next = NULL;
	}
	state->res = head;
}

void		printer(int i)
{
	if (i == SA)
		write(1, "sa\n", 3);
	else if (i == SB)
		write(1, "sb\n", 3);
	else if (i == SS)
		write(1, "ss\n", 3);
	else if (i == PA)
		write(1, "pa\n", 3);
	else if (i == PB)
		write(1, "pb\n", 3);
	else if (i == RA)
		write(1, "ra\n", 3);
	else if (i == RB)
		write(1, "rb\n", 3);
	else if (i == RR)
		write(1, "rr\n", 3);
	else if (i == RRA)
		write(1, "rra\n", 4);
	else if (i == RRB)
		write(1, "rrb\n", 4);
	else if (i == RRR)
		write(1, "rrr\n", 4);
}

void		new_out(t_state *state)
{
	t_inst	*tmp;

	while (state->res)
	{
		tmp = state->res->next;
		printer(state->res->opt);
		free(state->res);
		state->res = tmp;
	}
}
