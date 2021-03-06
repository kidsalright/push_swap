/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 16:44:42 by yberries          #+#    #+#             */
/*   Updated: 2020/10/30 18:40:07 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbrlen(int n)
{
	int len;

	len = 1;
	if (n < 0)
	{
		++len;
		n = -n;
	}
	while (n /= 10)
		++len;
	return (len);
}
