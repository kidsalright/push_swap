/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:23:47 by yberries          #+#    #+#             */
/*   Updated: 2019/09/12 16:02:22 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*temp;
	int		i;

	i = 0;
	if (s && f)
	{
		if (!(temp = ft_strnew(ft_strlen(s))))
			return (NULL);
		ft_strcpy(temp, s);
		if (temp)
		{
			while (temp[i])
			{
				temp[i] = (*f)(temp[i]);
				++i;
			}
			return (temp);
		}
		else
			return (NULL);
	}
	else
		return (NULL);
}
