/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_tools2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 15:45:30 by yberries          #+#    #+#             */
/*   Updated: 2020/11/13 05:47:40 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		find_from_bot(t_psl *l, int ind)
{
	int	i;

	i = 1;
	while (l)
	{
		if (l->index < ind)
			return (i);
		++i;
		l = l->prev;
	}
	return (0);
}

int		find_from_top(t_psl *l, int ind)
{
	int	i;

	i = 1;
	while (l)
	{
		if (l->index < ind)
			return (i);
		++i;
		l = l->next;
	}
	return (0);
}

int		find_max(t_stack *a)
{
	t_psl	*tmp;
	int		num;

	tmp = a->start;
	num = tmp->num;
	while (tmp->next)
	{
		if (tmp->next->num > num)
			num = tmp->next->num;
		tmp = tmp->next;
	}
	return (num);
}

int		find_min(t_stack *a)
{
	t_psl	*tmp;
	int		num;

	tmp = a->start;
	num = tmp->num;
	while (tmp->next)
	{
		if (tmp->next->num < num)
			num = tmp->next->num;
		tmp = tmp->next;
	}
	return (num);
}

int		choose_side(t_stack *a, int n)
{
	int		i;
	int		half;
	t_psl	*tmp;

	i = 0;
	tmp = a->start;
	half = a->len / 2;
	while (i <= half)
	{
		if (tmp->num == n)
			return (1);
		++i;
		tmp = tmp->next;
	}
	return (0);
}
