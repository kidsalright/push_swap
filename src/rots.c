/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rots.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 03:22:02 by yberries          #+#    #+#             */
/*   Updated: 2020/10/11 03:33:33 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rotate_stack(t_pslist *s)
{
		push_end(s, s->start->num);
		pop_front(s);
}

void	rot_rot(t_pslist *sa, t_pslist *sb)
{
	rotate_stack(sa);
	rotate_stack(sb);
}
