/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 16:39:30 by yberries          #+#    #+#             */
/*   Updated: 2020/10/20 07:31:57 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int             is_sorted(t_psl *s)
{
		if (s)
		{
				while (s->next)
				{
						if (s->num > s->next->num)
								return (0);
						s = s->next;
				}
				return (1);
		}
		return (0);
}

int             ps_atoi(char **str, char sign)
{
		long int        n;

		n = 0;
		while (**str >= '0' && **str <= '9')
		{
				n = n * 10 + (**str - '0');
				if ((n > INT_MAX && !sign) || (sign && -n < INT_MIN))
						ft_exit();
				++(*str);
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

void    free_ps(t_state *s)
{
		t_psl *tmp1;
		t_psl *tmp2;

		if (s->a.start)
		{
				tmp1 = s->a.start;
				while (tmp1)
				{
						tmp2 = tmp1->next;
						free(tmp1);
						tmp1 = tmp2;
				}
		}
		if (s->b.start)
		{
				tmp1 = s->b.start;
				while (tmp1)
				{
						tmp2 = tmp1->next;
						free(tmp1);
						tmp1 = tmp2;
				}
		}
}
