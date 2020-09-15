/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 20:57:55 by yberries          #+#    #+#             */
/*   Updated: 2019/09/13 21:30:26 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*res;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (!(res = ft_strnew(len)))
		return (NULL);
	while (len-- > 0)
	{
		res[i] = s[start];
		++i;
		++start;
	}
	return (res);
}
