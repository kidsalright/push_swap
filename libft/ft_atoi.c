/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 15:56:13 by yberries          #+#    #+#             */
/*   Updated: 2020/08/03 05:51:40 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	char		sign;
	long int	n;
	long int	buf;

	n = 0;
	sign = 0;
	buf = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		++str;
	if (*str == '-' || *str == '+')
		sign = *str++ == '-';
	while (*str >= '0' && *str <= '9')
	{
		buf = n;
		n = n * 10 + (*str++ - '0');
		if (buf > 0 && buf > n)
			return (sign ? 0 : -1);
	}
	return (sign ? (int)-n : (int)n);
}
