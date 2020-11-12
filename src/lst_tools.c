/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 01:59:52 by yberries          #+#    #+#             */
/*   Updated: 2020/11/12 08:53:56 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_read(t_stack *s, int i)
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

void	push_end(t_stack *s, t_psl *push)
{
	t_psl *tmp;

	tmp = (t_psl *)malloc(sizeof(t_psl));
	tmp->num = push->num;
	tmp->index = push->index;
	tmp->next = NULL;
	tmp->prev = s->end;
	if (s->end)
		s->end->next = tmp;
	s->end = tmp;
	if (s->start == NULL)
		s->start = tmp;
	++s->len;
}

void	pop_end(t_stack *s)
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

void	push_front(t_stack *s, t_psl *push)
{
	t_psl *tmp;

	tmp = (t_psl *)malloc(sizeof(t_psl));
	tmp->num = push->num;
	tmp->index = push->index;
	tmp->next = s->start;
	tmp->prev = NULL;
	if (s->start)
		s->start->prev = tmp;
	s->start = tmp;
	if (s->end == NULL)
		s->end = tmp;
	++s->len;
}

void	pop_front(t_stack *s)
{
	t_psl	*prev;

	prev = s->start;
	s->start = s->start->next;
	if (s->start)
		s->start->prev = NULL;
	if (prev == s->end)
		s->end = NULL;
	free(prev);
	--s->len;
}
