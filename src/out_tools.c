/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 23:45:44 by yberries          #+#    #+#             */
/*   Updated: 2020/11/12 09:19:55 by yberries         ###   ########.fr       */
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
		head = malloc(sizeof(t_inst));
		head->opt = i;
		head->next = NULL;
	}
	else
	{
		tmp = head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = malloc(sizeof(t_inst));
		tmp->next->opt = i;
		tmp->next->next = NULL;
	}
	state->res = head;
}

void		printer(int i)
{
	if (i == SA)
		ft_printf("sa\n");
	else if (i == SB)
		ft_printf("sb\n");
	else if (i == SS)
		ft_printf("ss\n");
	else if (i == PA)
		ft_printf("pa\n");
	else if (i == PB)
		ft_printf("pb\n");
	else if (i == RA)
		ft_printf("ra\n");
	else if (i == RB)
		ft_printf("rb\n");
	else if (i == RR)
		ft_printf("rr\n");
	else if (i == RRA)
		ft_printf("rra\n");
	else if (i == RRB)
		ft_printf("rrb\n");
	else if (i == RRR)
		ft_printf("rrr\n");
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
