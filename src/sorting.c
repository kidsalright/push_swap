/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 02:56:09 by yberries          #+#    #+#             */
/*   Updated: 2020/10/07 04:22:08 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	start_sort(t_pslist *sa)
{
	t_pslist sb;

	sb.len = 0;
	sb.start = (t_psl *)malloc(sizeof(t_psl));
	sb.start->prev = NULL;
	sb.start->next = NULL;
	sb.end = NULL;
	free(sb.start);
}

void	start_alg(t_pslist *sa)
{
	if (sa->len == 3)
			start_sort(sa);
	else
			start_sort(sa);
}
