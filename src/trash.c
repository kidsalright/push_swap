/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 15:45:30 by yberries          #+#    #+#             */
/*   Updated: 2020/11/11 02:05:41 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void    out_info(t_psl *tmp)
{
	ft_printf("numbers          indexes\n");
	while (tmp)
	{
	//	ft_printf("%-11d %4d   %s\n", tmp->num, tmp->index, (tmp->flag) ? "true" : "false");
		ft_printf("%-11d %4d\n", tmp->num, tmp->index, (tmp->flag) ? "true" : "false");
		tmp = tmp->next;
	}
	write(1, "\n", 1);
}

int             min_ind(t_psl *s)
{
	int     min;

	min = s->index;
	while (s)
	{
		if (s->index < min)
			min = s->index;
		s = s->next;
	}
	return (min);
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

void	fucking_sort(t_state *state)
{
	int	min;
	int	side;

	min = find_min(&state->a);
	side = choose_side(&state->a, min);
	if (side == 1)
	{
		while (state->a.start->num != min)
			ra(state);
	}
	else
	{
		while (state->a.start->num != min)
			rra(state);
	}
	pb(state);
	if (state->a.len != 0)
		fucking_sort(state);
	while (state->b.len != 0)
	{
		pa(state);
	}
}
