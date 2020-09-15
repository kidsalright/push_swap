/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 20:10:57 by yberries          #+#    #+#             */
/*   Updated: 2019/09/16 16:01:29 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*dest;

	dest = dst;
	if (dst < src)
	{
		while (len-- > 0)
		{
			*(unsigned char *)dst = *(unsigned char *)src;
			++dst;
			++src;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dest);
}
