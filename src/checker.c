/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 22:34:10 by yberries          #+#    #+#             */
/*   Updated: 2020/11/10 22:54:06 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cmd	g_cmd[] =
{
	{"ra", &ra},
	{"rb", &rb},
	{"rr", &sa},
	{"sa", &sa},
	{"sb", &sb},
	{"ss", &ss},
	{"pa", &pa},
	{"pb", &pb},
	{"rra", &rra},
	{"rrb", &rrb},
	{"rrr", &rrr},
	{0, NULL}
};

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
	ft_exit();
	return (0);
}

t_inst	*get_instructs(void)
{
	t_inst	*head;
	t_inst	*tmp;
	char	*line;

	head = (t_inst *)malloc(sizeof(t_inst));
	head->next = NULL;
	tmp = head;
	line = NULL;
	while (get_next_line(0, &line))
	{
		tmp->s = ft_strdup(get_instr(line));
		tmp->next = (t_inst *)malloc(sizeof(t_inst));
		ft_strdel(&line);
		tmp = tmp->next;
	}
	free(line);
	tmp->next = NULL;
	return (head);
}

void	free_inst(t_inst *inst)
{
	t_inst *tmp;

	while (inst->next)
	{
		tmp = inst->next;
		ft_strdel(&inst->s);
		free(inst);
		inst = tmp;
	}
	free(inst);
	inst = NULL;
}

void	start_checking(t_state *state, t_inst *inst)
{
	t_inst	*tmp;
	int		i;

	state->b.start = NULL;
	state->b.end = NULL;
	state->b.len = 0;
	tmp = inst;
	while (tmp->next)
	{
		i = 0;
		while (g_cmd[i].instr)
		{
			if (ft_strequ(g_cmd[i].instr, tmp->s))
				g_cmd[i].f(state);
			++i;
		}
		if (state->vis == 2)
		{
			out_res(state, tmp->s);
			clean_term(state);
		}
		tmp = tmp->next;
	}
}

int		main(int ac, char **av)
{
	t_state		state;
	t_inst		*inst;

	if (ac > 1)
	{
		state.t = 0;
		state.vis = (av[1][0] == '-' && av[1][1] == 'v') ? 2 : 1;
		args_to_stack(&state.a, (ac - (int)state.vis), \
				&av[(int)state.vis]);
		check_dups(state.a.start);
		inst = get_instructs();
		state.counter = 0;
		start_checking(&state, inst);
		if (is_sorted(state.a.start) && state.b.len == 0)
			(state.vis == 2) ? out_res(&state, \
					"\033[32mOK") : ft_printf("OK\n");
		else
			(state.vis == 2) ? out_res(&state, \
					"\033[31mKO") : ft_printf("KO\n");
		free_inst(inst);
		free_ps(&state);
	}
	return (0);
}
