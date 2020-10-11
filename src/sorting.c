/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 02:56:09 by yberries          #+#    #+#             */
/*   Updated: 2020/10/11 04:37:35 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	short_sort(t_pslist *sa)
{
		out_res(sa, NULL, "sa");
}

void	start_sort(t_pslist *sa, t_pslist *sb)
{

}

void	start_alg(t_pslist *sa)
{
		t_pslist sb;

		if (!is_sorted(sa->start))
		{
				if (sa->len < 3)
				{
						swap_stack(sa);
						ft_printf("sa\n");
				}

				else if(sa->len < 100)
				{
						create_stack(&sb);
						start_sort(sa, &sb);
				}
		}
}
