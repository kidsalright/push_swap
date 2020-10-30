/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 20:01:37 by yberries          #+#    #+#             */
/*   Updated: 2020/10/30 18:31:06 by yberries         ###   ########.fr       */
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
	struct s_inst	*next;
}					t_inst;

typedef struct		s_psl
{
	int				num;
	int				index;
	char			flag;
	struct s_psl	*prev;
	struct s_psl	*next;
}					t_psl;

typedef struct		s_stack
{
	int				len;
	int				vislen;
	t_psl			*start;
	t_psl			*end;
}					t_stack;

typedef struct		s_state
{
	char			vis;
	int				counter;
	t_stack			a;
	t_stack			b;
}					t_state;

typedef struct		s_cmd
{
	char			*instr;
	void			(*f)(t_state *state);
}					t_cmd;

void				push_front(t_stack *s, int i);
void				pop_front(t_stack *s);
void				push_end(t_stack *s, int i);
void				pop_end(t_stack *s);
void				out_res(t_state *state, char *instr);
void				clean_term(t_state *state);
void				ps_output(char *instr);
void				ft_exit(void);
int					is_sorted(t_psl *s);
int					ps_atoi(char **str, char sign);
void				check_dups(t_psl *head);
void				free_ps(t_state *s);
void				args_to_stack(t_stack *s, int ac, char **av);
void				start_alg(t_state *s);
void				marking(t_stack *s);
void				ft_quicksort(int *arr, int low, int high);
void				sa(t_state *s);
void				sb(t_state *s);
void				ra(t_state *s);
void				rb(t_state *s);
void				pa(t_state *s);
void				pb(t_state *s);
void				rra(t_state *s);
void				rrb(t_state *s);
void				rrr(t_state *s);
void				rr(t_state *s);
void				ss(t_state *s);
void				fucker_sort(t_state *state);

#endif
