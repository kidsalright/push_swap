/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 16:39:30 by yberries          #+#    #+#             */
/*   Updated: 2020/10/07 07:29:15 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int             is_sorted(t_psl *s)
{
		while (s->next)
		{
				if (s->num > s->next->num)
						return (0);
				s = s->next;
		}
		return (1);
}

void    ft_exit()
{
		write(2, "Error\n", 6);
		exit(1);
}

int             ps_atoi(const char *str)
{
		char            sign;
		long int        n;

		n = 0;
		sign = 0;
		if (*str == '-' || *str == '+')
				sign = *str++ == '-';
		while (*str >= '0' && *str <= '9')
		{
				n = n * 10 + (*str++ - '0');
				if ((n > INT_MAX && !sign) || (sign && -n < INT_MIN))
						ft_exit();
		}
		return (sign ? (int)-n : (int)n);
}

void    check_dups(t_psl *head)
{
		t_psl *i;
		t_psl *j;

		i = head;
		while (i->next)
		{
				j = i->next;
				while (j)
				{
						if (i->num == j->num)
								ft_exit();
						j = j->next;
				}
				i = i->next;
		}
}
