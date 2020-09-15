/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 22:13:02 by yberries          #+#    #+#             */
/*   Updated: 2019/09/20 16:04:44 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	char	*res;

	if (ptr && !size)
	{
		if (!(res = (char *)malloc(1)))
			return (NULL);
		ft_memdel(ptr);
		return (res);
	}
	if (!(res = (char *)malloc(size)))
		return (NULL);
	if (ptr)
	{
		ft_memcpy(res, ptr, size);
		ft_memdel(ptr);
	}
	return (res);
}
