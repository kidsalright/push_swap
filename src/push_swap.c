/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 20:05:17 by yberries          #+#    #+#             */
/*   Updated: 2020/09/23 00:00:24 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int		is_sorted(int *s, int l)
{
		while (--l)
				if (s[l] <= s[l - 1])
						return (0);
		return (1);
}

void	ft_exit()
{
		write(2, "Error\n", 6);
		exit(1);
}

int		pw_atoi(const char *str)
{
		char		sign;
		long int	n;

		n = 0;
		sign = 0;
		while (*str == 32 || (*str >= 9 && *str <= 13))
				++str;
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

int main(int ac, char **av)
{
		int i;
		int	j;
		int	*sa;
		int	*sb;
		char *str;

		i = 0;
		j = -1;
		sa = (int *)malloc(sizeof(int) * (ac - 1));
		while (av[++i])
				sa[++j] = pw_atoi(av[i]);
		if (is_sorted(sa, ac - 1))
				ft_printf("\n");
		str = "-2147483649";
		i = pw_atoi(str);
		return (0);
}
