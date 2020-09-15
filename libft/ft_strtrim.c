/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 22:33:19 by yberries          #+#    #+#             */
/*   Updated: 2019/09/15 18:42:24 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*res;
	int		start;
	int		len;

	if (!s)
		return (NULL);
	start = 0;
	len = ft_strlen(s) - 1;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		++start;
	if (len > start)
		while (s[len] == ' ' || s[len] == '\n' || s[len] == '\t')
			--len;
	if (!(res = ft_strsub(s, start, (len - start + 1))))
		return (NULL);
	return (res);
}
