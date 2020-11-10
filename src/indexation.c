/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 17:37:25 by yberries          #+#    #+#             */
/*   Updated: 2020/11/11 02:03:43 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

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
			swap(&arr[++i], &arr[j]);
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

void	set_index(t_psl *list, int len)
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
		i = 0;
		while (tmp->num != tab[i])
			++i;
		tmp->index = i;
		tmp = tmp->next;
	}
	free(tab);
}
