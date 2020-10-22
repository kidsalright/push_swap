/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 09:07:29 by yberries          #+#    #+#             */
/*   Updated: 2020/10/21 18:23:52 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_state *s)
{
	if (s->a.start)
	{
		push_end(&s->a, s->a.start->num);
		pop_front(&s->a);
	}
}

void	rb(t_state *s)
{
	if (s->b.start)
	{
		push_end(&s->b, s->b.start->num);
		pop_front(&s->b);
	}
}

void	rra(t_state *s)
{
	if (s->a.end)
	{
		push_front(&s->a, s->a.end->num);
		pop_end(&s->a);
	}
}

void	rrb(t_state *s)
{
	if (s->b.end)
	{
		push_front(&s->b, s->b.end->num);
		pop_end(&s->b);
	}
}
