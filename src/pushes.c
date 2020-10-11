/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 03:22:55 by yberries          #+#    #+#             */
/*   Updated: 2020/10/11 03:34:16 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push_a(t_pslist *sa, t_pslist *sb)
{
		push_end(sb, sa->start->num);
		pop_front(sa);
}

void    push_b(t_pslist *sb, t_pslist *sa)
{
		push_end(sa, sb->start->num);
		pop_front(sb);
}

void	push_push(t_pslist *sa, t_pslist *sb)
{
		push_a(sa, sb);
		push_b(sb, sa);
}
