/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 01:59:52 by yberries          #+#    #+#             */
/*   Updated: 2020/10/07 04:13:54 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push_front(t_pslist *s, int i)
{
		t_psl *tmp;

		tmp = (t_psl *)malloc(sizeof(t_psl));
		tmp->num = i;
		tmp->next = s->start;
		tmp->prev = NULL;
		if (s->start)
				s->start->prev = tmp;
		s->start = tmp;
		if (s->end == NULL)
				s->end = tmp;
		++s->len;
}

void    pop_front(t_pslist *s)
{
		t_psl   *tmp;
		t_psl   *prev;

		prev = s->start;
		s->start = s->start->next;
		if (s->start)
				s->start->prev = NULL;
		if (prev == s->end)
				s->end = NULL;
		free(prev);
		--s->len;
}

void    free_ps(t_psl *s)
{
		t_psl   *tmp;

		while (s)
		{
				tmp = s->next;
				free(s);
				s = tmp;
		}
}
