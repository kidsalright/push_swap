/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 03:21:57 by yberries          #+#    #+#             */
/*   Updated: 2020/10/11 03:32:09 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap_stack(t_pslist *s)
{
		int     tmp;

		tmp = s->start->next->num;
		s->start->next->num = s->start->num;
		s->start->num = tmp;
}

void	swap_swap(t_pslist *sa, t_pslist *sb)
{
		swap_stack(sa);
		swap_stack(sb);
}
