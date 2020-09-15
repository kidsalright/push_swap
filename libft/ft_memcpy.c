/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 15:55:00 by yberries          #+#    #+#             */
/*   Updated: 2019/09/10 17:57:59 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	if (dst != src)
	{
		dst += n;
		src += n;
		while (n-- > 0)
			*(unsigned char *)--dst = *(unsigned char *)--src;
	}
	return (dst);
}
