/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 17:37:25 by yberries          #+#    #+#             */
/*   Updated: 2020/10/30 17:38:40 by yberries         ###   ########.fr       */
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
