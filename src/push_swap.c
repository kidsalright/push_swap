/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 20:05:17 by yberries          #+#    #+#             */
/*   Updated: 2020/10/06 17:21:36 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	args_read(t_pslist *sa, int ac, char **av)
{
		t_psl	*head;
		t_psl	*s;
		t_psl	*tmp;
		int		i;

		i = -1;
		head = (t_psl *)malloc(sizeof(t_psl));
		head->prev = NULL;
		sa->start = head;
		s = head;
		while (--ac)
		{
				tmp = s;
				s->num = ps_atoi(av[++i]);
				s->next = (t_psl *)malloc(sizeof(t_psl));
				s = s->next;
				s->prev = tmp;
		}
		s->num = ps_atoi(av[++i]);
		sa->end = s;
		s->next = NULL;
		check_dups(head);
}

void	output_stack(t_psl *s)
{
		ft_printf("from start\n");
		while (s)
		{
				ft_printf("%d\n", s->num);
				s = s->next;
		}
}

void	out_reverse(t_psl *s)
{
		ft_printf("from end\n");
		while (s->prev)
		{
				ft_printf("%d\n", s->num);
				s = s->prev;
		}
		ft_printf("%d\n", s->num);
}

int		main(int ac, char **av)
{
		t_pslist	sa;

		if (ac > 2)
		{
				args_read(&sa, ac - 1, &av[1]);
				output_stack(sa.start);
				out_reverse(sa.end);
		}
		return (0);
}
