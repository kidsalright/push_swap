/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 21:00:33 by yberries          #+#    #+#             */
/*   Updated: 2019/09/16 00:00:42 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nlen(int n)
{
	int len;

	len = 1;
	n = n / 10;
	while (n != 0)
	{
		n = n / 10;
		++len;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	char	*res;
	int		i;
	int		len;
	char	sign;

	sign = 0;
	if (n < 0)
		sign = 1;
	len = ft_nlen(n);
	if (!(res = ft_strnew(len + sign)))
		return (NULL);
	if (sign)
		res[0] = '-';
	i = len + sign - 1;
	while (i >= sign)
	{
		if (sign)
			res[i--] = (n % 10 * -1) + 48;
		else
			res[i--] = n % 10 + 48;
		n /= 10;
	}
	return (res);
}
