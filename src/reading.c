/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 07:03:06 by yberries          #+#    #+#             */
/*   Updated: 2020/10/09 01:39:51 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void             find_nums(t_pslist *sa, char *av)
{
		char	sign;

		sign = 0;
		while (*av != '\0')
		{
				while (*av == 32 || (*av >= 9 && *av <= 13))
						++av;
				if ((*av == '+' || *av == '-') && ft_isdigit(*(av + 1)))
						sign = *av++ == '-';
				if ((*av < '0' || *av > '9') && *av != '\0')
						ft_exit();
				if (*av >= '0' && *av <= '9')
						push_end(sa, ps_atoi(&av, sign));
				sign = 0;
		}
}

void    args_to_stack(t_pslist *sa, int ac, char **av)
{
		int             i;

		i = -1;
		create_stack(sa);
		while (--ac)
				find_nums(sa, av[++i]);
}
