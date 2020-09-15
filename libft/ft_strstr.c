/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 21:51:28 by yberries          #+#    #+#             */
/*   Updated: 2019/09/12 22:59:14 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t pos;
	size_t res;
	size_t i;

	if (*needle == '\0')
		return ((char *)haystack);
	pos = 0;
	while (*(haystack + pos))
	{
		res = pos;
		i = 0;
		while (*(needle + i) == *(haystack + res) && *(needle + i))
		{
			++res;
			++i;
		}
		if (*(needle + i) == '\0')
			return ((char *)(haystack + pos));
		++pos;
	}
	return (NULL);
}
