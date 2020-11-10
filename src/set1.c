/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 09:07:29 by yberries          #+#    #+#             */
/*   Updated: 2020/11/10 22:56:32 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_state *s)
{
	int	tmp;

	if (s->a.start)
	{
		if (s->a.start->next)
		{
			tmp = s->a.start->next->num;
			s->a.start->next->num = s->a.start->num;
			s->a.start->num = tmp;
			if (s->t)
				put_res(s, SA);
		}
	}
}

void	sb(t_state *s)
{
	int	tmp;

	if (s->b.start)
	{
		if (s->b.start->next)
		{
			tmp = s->b.start->next->num;
			s->b.start->next->num = s->b.start->num;
			s->b.start->num = tmp;
			if (s->t)
				put_res(s, SB);
		}
	}
}

void	pa(t_state *s)
{
	if (s->b.start)
	{
		push_front(&s->a, s->b.start);
		pop_front(&s->b);
		if (s->t)
			put_res(s, PA);
	}
}

void	pb(t_state *s)
{
	if (s->a.start)
	{
		push_front(&s->b, s->a.start);
		pop_front(&s->a);
		if (s->t)
			put_res(s, PB);
	}
}
