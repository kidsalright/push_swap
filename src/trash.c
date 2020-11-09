/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 15:45:30 by yberries          #+#    #+#             */
/*   Updated: 2020/11/10 01:25:32 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

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
		{
			ra(state);
			ps_output("ra");
		}
	}
	else
	{
		while (state->a.start->num != min)
		{
			rra(state);
			ps_output("rra");
		}
	}
	pb(state);
	ps_output("pb");
	if (state->a.len != 0)
		fucking_sort(state);
	while (state->b.len != 0)
	{
		pa(state);
		ps_output("pa");
	}
}

void	out_arr(int *arr, int len)
{
	int	i;

	i = -1;
	while (len--)
		ft_printf("%d ", arr[++i]);
	ft_printf("\n");
	free(arr);
}
