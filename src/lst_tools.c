/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 01:59:52 by yberries          #+#    #+#             */
/*   Updated: 2020/10/11 03:52:04 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    create_stack(t_pslist *s)
{
		s->len = 1;
		s->start = (t_psl *)malloc(sizeof(t_psl));
		s->start->prev = NULL;
		s->start->next = NULL;
		s->end = s->start;
}

void	push_end(t_pslist *s, int i)
{
	t_psl *tmp;

	tmp = (t_psl *)malloc(sizeof(t_psl));
	tmp->num = i;
	tmp->next = NULL;
	tmp->prev = s->end;
	if (s->end)
			s->end->next = tmp;
	s->end = tmp;
	if (s->start == NULL)
			s->start = tmp;
	++s->len;
}

void	pop_end(t_pslist *s)
{
		t_psl	*next;

		next = s->end;
		s->end = s->end->prev;
		if (s->end)
				s->end->next = NULL;
		if (next == s->start)
				s->start = NULL;
		free(next);
		--s->len;
}

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

