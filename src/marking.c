/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   marking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:56:34 by yberries          #+#    #+#             */
/*   Updated: 2020/11/09 17:54:27 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		mark_increase(t_stack *s, int head)
{
	t_psl	*tmp;
	char	start;
	int		i;
	int		n;

	i = 0;
	start = 0;
	tmp = s->start;
	while (tmp)
	{
		tmp->flag = 0;
		if (start && tmp->num > n)
		{
			n = tmp->num;
			++i;
			tmp->flag = 1;
		}
		if (tmp->num == head)
		{
			n = head;
			tmp->flag = 1;
			++i;
			start = 1;
		}
		tmp = tmp->next;
	}
	return (i);
}
