/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 09:07:29 by yberries          #+#    #+#             */
/*   Updated: 2020/11/10 22:56:52 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_state *s)
{
	if (s->a.start)
	{
		push_end(&s->a, s->a.start);
		pop_front(&s->a);
		if (s->t)
			put_res(s, RA);
	}
}

void	rb(t_state *s)
{
	if (s->b.start)
	{
		push_end(&s->b, s->b.start);
		pop_front(&s->b);
		if (s->t)
			put_res(s, RB);
	}
}

void	rra(t_state *s)
{
	if (s->a.end)
	{
		push_front(&s->a, s->a.end);
		pop_end(&s->a);
		if (s->t)
			put_res(s, RRA);
	}
}

void	rrb(t_state *s)
{
	if (s->b.end)
	{
		push_front(&s->b, s->b.end);
		pop_end(&s->b);
		if (s->t)
			put_res(s, RRB);
	}
}
