/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 20:05:17 by yberries          #+#    #+#             */
/*   Updated: 2020/09/23 00:00:24 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_sorted(int *s, int l)
{
		while (--l)
				if (s[l] <= s[l - 1])
						return (0);
		return (1);
}

void	ft_exit()
{
		write(2, "Error\n", 6);
		exit(1);
}

int		ps_atoi(const char *str)
{
		char		sign;
		long int	n;

		n = 0;
		sign = 0;
		if (*str == '-' || *str == '+')
				sign = *str++ == '-';
		if (*str < '0' || *str > '9')
				ft_exit();
		while (*str >= '0' && *str <= '9')
		{
				n = n * 10 + (*str++ - '0');
				if ((n > INT_MAX && !sign) || (sign && -n < INT_MIN))
						ft_exit();
		}
		if (*str)
				ft_exit();
		return (sign ? (int)-n : (int)n);
}

void	check_dups(t_psl *head)
{
		t_psl *i;
		t_psl *j;

		i = head;
		while (i->next)
		{
				j = i->next;
				while (j)
				{
						if (i->num == j->num)
								ft_exit();
						j = j->next;
				}
				i = i->next;
		}
}

t_psl	*args_read(int ac, char **av)
{
		t_psl	*head;
		t_psl	*s;
		int	i;

		i = -1;
		head = (t_psl *)malloc(sizeof(t_psl));
		s = head;
		while (--ac)
		{
				s->num = ps_atoi(av[++i]);
				if (ac != 1)
				{
						s->next = (t_psl *)malloc(sizeof(t_psl));
						s = s->next;
				}
		}
		s->next = NULL;
		check_dups(head);
		return (head);
}

void	output_stack(t_psl *s)
{
		while (s)
		{
				ft_printf("%d ", s->num);
				s = s->next;
		}
}

void	free_ps(t_psl *s)
{
		t_psl	*tmp;

		while (s)
		{
			tmp = s->next;
			free(s);
			s = tmp;
		}
}

int		main(int ac, char **av)
{
		t_psl		*sa;

		if (ac > 2)
		{
				sa = args_read(ac, &av[1]);
				output_stack(sa);
				free_ps(sa);
		}
		return (0);
}
