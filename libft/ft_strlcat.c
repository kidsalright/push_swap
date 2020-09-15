/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 18:45:51 by yberries          #+#    #+#             */
/*   Updated: 2019/09/20 14:42:54 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t slen;
	size_t dlen;
	size_t i;

	slen = ft_strlen(src);
	dlen = ft_strlen(dst);
	if (dlen >= size)
		return (size + slen);
	i = 0;
	while (dlen + i < size - 1 && i < slen)
	{
		dst[dlen + i] = src[i];
		++i;
	}
	dst[dlen + i] = '\0';
	return (dlen + slen);
}
