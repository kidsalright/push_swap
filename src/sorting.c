/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 02:56:09 by yberries          #+#    #+#             */
/*   Updated: 2020/10/30 14:14:54 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	go(t_state *state)
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
		go(state);
	while (state->b.len != 0)
	{
		pa(state);
		ps_output("pa");
	}
}

void	out_arr(int	*arr, int len)
{
	int	i;

	i = -1;
	while (len--)
		ft_printf("%d ", arr[++i]);
	ft_printf("\n");
	free(arr);
}

void	swap(int *a, int *b)
{
	if (a != b)
	{
		*a ^= *b;
		*b ^= *a;
		*a ^= *b;
	}
}

int		partition(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	i = (low - 1);
	pivot = arr[high];
	j = low;
	while (j <= high - 1)
	{
		if (arr[j] < pivot)
		{
			++i;
			swap(&arr[i], &arr[j]);
		}
		++j;
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void	ft_quicksort(int *arr, int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = partition(arr, low, high);
		ft_quicksort(arr, low, pi - 1);
		ft_quicksort(arr, pi + 1, high);
	}
}

void	sort_arr(t_psl *list, int len)
{
	int		i;
	int		*tab;
	t_psl	*tmp;

	tmp = list;
	tab = (int *)malloc(sizeof(int) * len);
	i = -1;
	while (++i < len)
	{
		tab[i] = tmp->num;
		tmp = tmp->next;
	}
	ft_quicksort(tab, 0, len - 1);
	tmp = list;
	while (tmp)
	{
		i = -1;
		while (tmp->num != tab[++i]);
		tmp->index = i;
		tmp = tmp->next;
	}
//	out_arr(tab, len);
}

void	maybe_do_this_fucking_algo_dude(t_state *state)
{
	t_psl *tmp;

	sort_arr(state->a.start, state->a.len);
	tmp = state->a.start;
	while (tmp)
	{
		ft_printf("%-5d %d\n", tmp->num, tmp->index);
		tmp = tmp->next;
	}
}

void	start_alg(t_state *state)
{	
	state->b.start = NULL;
	state->b.end = NULL;
	state->b.len = 0;
	if (!is_sorted(state->a.start))
	{
		if (state->a.len < 3)
		{
			sa(state);
			ps_output("sa");
		}
		else if (state->a.len == 10)
			go(state);
		else
			maybe_do_this_fucking_algo_dude(state);
	}
}
