/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 09:07:29 by yberries          #+#    #+#             */
/*   Updated: 2020/11/10 22:57:13 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_state *s)
{
	rra(s);
	rrb(s);
	if (s->t)
		put_res(s, RRR);
}

void	ss(t_state *s)
{
	sa(s);
	sb(s);
	if (s->t)
		put_res(s, SS);
}

void	rr(t_state *s)
{
	ra(s);
	rb(s);
	if (s->t)
		put_res(s, RR);
}
