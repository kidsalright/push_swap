/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 19:06:54 by yberries          #+#    #+#             */
/*   Updated: 2019/09/16 20:17:29 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_lstfree(void *content, size_t content_size)
{
	(void)content_size;
	if (!content)
		return ;
	ft_memdel(content);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;

	if (!lst || !f)
		return (NULL);
	tmp = (*f)(lst);
	if (tmp)
	{
		tmp->next = ft_lstmap(lst->next, f);
		if (!tmp->next && lst->next)
		{
			ft_lstdelone(&tmp, &ft_lstfree);
			return (NULL);
		}
	}
	return (tmp);
}
