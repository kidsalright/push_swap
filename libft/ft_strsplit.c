/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 22:22:03 by yberries          #+#    #+#             */
/*   Updated: 2019/09/18 05:28:53 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_arrlen(char const *s, char c)
{
	int		words;

	words = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == 0))
			++words;
		++s;
	}
	return (words);
}

static size_t	ft_wordlen(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s != c && *s)
	{
		++s;
		++len;
	}
	return (len);
}

static char		*ft_wordalloc(char const *s, char c)
{
	char	*res;
	size_t	len;
	int		i;

	i = 0;
	len = ft_wordlen(s, c);
	if (!(res = (char *)ft_memalloc(len + 1)))
		return (NULL);
	while (len-- > 0)
	{
		res[i] = *s;
		++i;
		++s;
	}
	return (res);
}

static char		**ft_arrfree(char **res, int n)
{
	while (n-- > 0)
		free(res[n]);
	free(res);
	res = NULL;
	return (res);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**res;
	size_t	i;
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_arrlen(s, c);
	if (!(res = (char **)malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		while (*s == c)
			++s;
		if (!(res[i] = ft_wordalloc(s, c)))
			return (ft_arrfree(res, i));
		s = (s + (ft_wordlen(s, c) + 1));
		++i;
	}
	res[len] = NULL;
	return (res);
}
