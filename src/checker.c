/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 22:34:10 by yberries          #+#    #+#             */
/*   Updated: 2020/10/11 06:55:43 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	complete_instructs(t_pslist *sa, t_inst *inst)
{
		
}

void	start_checking(t_pslist *sa, t_inst *inst)
{
		if (sa->vis == 1)
		{
				complete_instructs(sa, inst);
				if (is_sorted(sa->start))
						ft_printf("OK\n");
				else
						ft_printf("KO\n");
		}
		else
		{
				ft_printf("visualized))\n");
		}
}

char	*get_instr(char *line)
{
		if (ft_strequ(line, "sa"))
				return ("sa");
		else if (ft_strequ(line, "sb"))
				return ("sb");
		else if (ft_strequ(line, "ss"))
				return ("ss");
		else if (ft_strequ(line, "pa"))
				return ("pa");
		else if (ft_strequ(line, "pb"))
				return ("pb");
		else if (ft_strequ(line, "ra"))
				return ("ra");
		else if (ft_strequ(line, "rb"))
				return ("rb");
		else if (ft_strequ(line, "rr"))
				return ("rr");
		else if (ft_strequ(line, "rra"))
				return ("rra");
		else if (ft_strequ(line, "rrb"))
				return ("rrb");
		else if (ft_strequ(line, "rrr"))
				return ("rrr");
		else
				ft_exit();
}

void	out_in(t_inst *head)
{
		while (head->next)
		{
				ft_printf("wow :%s\n", head->s);
				head = head->next;
		}
}

t_inst	*get_instructs(void)
{
		t_inst	*head;
		t_inst	*tmp;
		char	*line;

		head = (t_inst *)malloc(sizeof(t_inst));
		head->next = NULL;
		tmp = head;
		while (get_next_line(0, &line))
		{
				tmp->s = ft_strdup(get_instr(line));
				tmp->next = (t_inst *)malloc(sizeof(t_inst));
				ft_strdel(&line);
				tmp = tmp->next;
		}
		tmp->next = NULL;
		return (head);
		//out_in(head);
}

int		main(int ac, char **av)
{
		t_pslist        sa;
		t_inst			*inst;

		if (ac > 1)
		{
				sa.vis = (av[1][0] == '-' && av[1][1] == 'v') ? 2 : 1;
				args_to_stack(&sa, (ac - (int)sa.vis), &av[(int)sa.vis]);
				pop_front(&sa);
				check_dups(sa.start);
				inst = get_instructs();
				start_checking(&sa, inst);
				free_ps(sa.start);
		}
		return (0);
}
