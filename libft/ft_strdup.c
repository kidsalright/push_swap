/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 05:01:28 by yberries          #+#    #+#             */
/*   Updated: 2019/09/11 20:00:31 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*tmp;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s1);
	tmp = (char *)malloc(sizeof(*s1) * (len + 1));
	if (tmp == NULL)
		return (0);
	else
	{
		while (s1[i])
		{
			tmp[i] = s1[i];
			++i;
		}
		tmp[len] = '\0';
	}
	return (tmp);
}
