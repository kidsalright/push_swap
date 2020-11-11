/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 00:33:28 by yberries          #+#    #+#             */
/*   Updated: 2020/11/12 00:46:55 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *src, t_stack *dst)
{
	if (src->start)
	{
		push_front(dst, src->start);
		pop_front(src);
	}
}

void	revrot(t_stack *s)
{
	if (s->end)
	{
		push_front(s, s->end);
		pop_end(s);
	}
}

void	rotate(t_stack *s)
{
	if (s->start)
	{
		push_end(s, s->start);
		pop_front(s);
	}
}
