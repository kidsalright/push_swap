/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sosort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 15:41:49 by yberries          #+#    #+#             */
/*   Updated: 2020/10/30 15:59:09 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	marking(t_stack *s)
{
	t_psl	*tmp;
	int		i;

	i = 0;
	tmp = s->start;
	while (tmp)
	{
		tmp->flag = 0;
		if (tmp->index == 0)
		{
			tmp->flag = 1;
			++i;
		}
		if (tmp->index == i)
		{
			tmp->flag = 1;
			++i;
		}
		tmp = tmp->next;
	}
}
