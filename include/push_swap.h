/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 20:01:37 by yberries          #+#    #+#             */
/*   Updated: 2020/11/13 21:30:49 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

# define CYN	"\033[36m"
# define YEL	"\033[33m"
# define RES	"\033[0m"

typedef struct		s_inst
{
	char			*s;
	int				opt;
	struct s_inst	*next;
}					t_inst;

typedef struct		s_psl
{
	int				num;
	int				index;
	struct s_psl	*prev;
	struct s_psl	*next;
}					t_psl;

typedef struct		s_stack
{
	int				len;
	t_psl			*start;
	t_psl			*end;
}					t_stack;

typedef struct		s_state
{
	char			vis;
	char			t;
	int				counter;
	t_stack			a;
	t_stack			b;
	t_inst			*res;
}					t_state;

typedef struct		s_cmd
{
	char			*instr;
	void			(*f)(t_state *state);
}					t_cmd;

enum					e_cmds
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
};

void				push_front(t_stack *s, t_psl *push);
void				pop_front(t_stack *s);
void				push_end(t_stack *s, t_psl *push);
void				push_read(t_stack *s, int i);
void				pop_end(t_stack *s);

void				sa(t_state *s);
void				sb(t_state *s);
void				ss(t_state *s);
void				ra(t_state *s);
void				rb(t_state *s);
void				pa(t_state *s);
void				pb(t_state *s);
void				rra(t_state *s);
void				rrb(t_state *s);
void				rrr(t_state *s);
void				rr(t_state *s);

void				put_res(t_state *state, int i);
void				out_res(t_state *state, char *instr);
void				clean_term(t_state *state);
void				ft_exit(void);
void				new_out(t_state *state);

int					is_sorted(t_psl *s);
int					ps_atoi(char **str, char sign);
void				check_dups(t_psl *head);
void				free_ps(t_state *s);
void				args_to_stack(t_stack *s, int ac, char **av);
void				protect_arg(t_state *state, char *av);
int					choose_side(t_stack *a, int n);
int					find_min(t_stack *a);
int					find_max(t_stack *a);
int					find_from_top(t_psl *l, int ind);
int					find_from_bot(t_psl *l, int ind);

void				start_alg(t_state *s);
void				set_index(t_psl *list, int len);
void				sort_three(t_state *state);

#endif
