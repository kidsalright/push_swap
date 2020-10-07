/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 20:05:17 by yberries          #+#    #+#             */
/*   Updated: 2020/10/07 03:51:41 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	output_stack(t_psl *s)
{
		ft_printf("stack A:\n");
		while (s)
		{
				ft_printf("%d\n", s->num);
				s = s->next;
		}
}

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

int		main(int ac, char **av)
{
		t_pslist	sa;

		if (ac > 1)
		{
				sa.len = ac - 1;
				args_read(&sa, sa.len, &av[1]);
				start_alg(&sa);
				output_stack(sa.start);
				free_ps(sa.start);
		}
		else
				ft_exit();
		return (0);
}
