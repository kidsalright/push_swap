/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 07:03:06 by yberries          #+#    #+#             */
/*   Updated: 2020/11/13 20:54:22 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	protect_arg(t_state *state, char *av)
{
	state->vis = (av[0] == '-' && av[1] == 'v') ? 2 : 1;
	if (state->vis == 2 && ft_strlen(av) > 2)
		ft_exit();
}

void	find_nums(t_stack *a, char *av)
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
			push_read(a, ps_atoi(&av, sign));
		sign = 0;
	}
}

void	args_to_stack(t_stack *a, int ac, char **av)
{
	int	i;

	i = -1;
	a->start = NULL;
	a->end = NULL;
	a->len = 0;
	while (ac--)
		find_nums(a, av[++i]);
}
