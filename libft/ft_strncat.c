/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 16:54:04 by yberries          #+#    #+#             */
/*   Updated: 2019/09/12 17:24:25 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t len;

	len = 0;
	i = 0;
	while (s1[i])
		++i;
	while (s2[len] && n-- > 0)
	{
		s1[i] = s2[len];
		++len;
		++i;
	}
	s1[i] = '\0';
	return (s1);
}
