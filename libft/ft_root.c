/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_root.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 09:15:54 by yberries          #+#    #+#             */
/*   Updated: 2020/01/22 16:57:34 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_power(int nbr, int power)
{
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	return (nbr * ft_power(nbr, power - 1));
}

int				ft_root(int root, int nbr)
{
	int res;

	res = 0;
	while (ft_power(res, root) <= nbr)
		++res;
	return (res - 1);
}
