/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 20:43:46 by yberries          #+#    #+#             */
/*   Updated: 2019/09/13 20:55:48 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
				temp[i] = (*f)(i, temp[i]);
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
