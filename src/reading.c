/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 07:03:06 by yberries          #+#    #+#             */
/*   Updated: 2020/10/07 07:19:05 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    find_each_num(t_pslist *sa, char *str, int count)
{
		int     i;
		int     num;

		i = 0;
		while (str[i] && count)
		{
				if (ft_isdigit(str[i]) || str[i] == '-' || str[i] == '+')
				{
						num = ps_atoi(&str[i]);
						push_end(sa, num);
						i += ft_nbrlen(num);
						--count;
				}
				++i;
		}
}

int             find_nums(char *str)
{
		char    nbrlen;
		int             count;

		nbrlen = 0;
		count = 0;
		while (*str)
		{
				while (*str == 32 || (*str >= 9 && *str <= 13))
						++str;
				if (*str == '-' || *str == '+')
						++str;
				if ((*str < '0' || *str > '9') && *str != '\0')
						ft_exit();
				while (*str >= '0' && *str <= '9')
				{
						++nbrlen;
						++str;
				}
				if (nbrlen)
				{
						++count;
						nbrlen = 0;
				}
		}
		return (count);
}

void    args_to_stack(t_pslist *sa, int ac, char **av)
{
		int             i;
		int             count;

		i = -1;
		create_stack(sa);
		while (--ac)
		{
				count = find_nums(av[++i]);
				find_each_num(sa, av[i], count);
		}
}
