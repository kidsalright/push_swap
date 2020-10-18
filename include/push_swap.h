/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 20:01:37 by yberries          #+#    #+#             */
/*   Updated: 2020/10/18 11:14:22 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

# define CYN "\x1B[36m"
# define RES "\033[0m"

typedef struct	s_inst
{
		char			*s;
		struct s_inst	*next;
}				t_inst;

typedef struct	s_psl
{
		int				num;
		struct s_psl	*prev;
		struct s_psl	*next;
}				t_psl;

typedef struct	s_stack
{
		int		len;
		t_psl	*start;
		t_psl	*end;
}				t_stack;

typedef struct	s_state
{
		char	vis;
		t_stack	a;
		t_stack b;
}				t_state;

/* lst_tools  */
void    push_front(t_stack *s, int i);
void    pop_front(t_stack *s);
void    push_end(t_stack *s, int i);
void	pop_end(t_stack *s);

/* out_tools  */
void    out_res(t_state *state);
void	ft_exit(void);

/* ps_tools   */
int		is_sorted(t_psl *s);
int		ps_atoi(char **str, char sign);
void	check_dups(t_psl *head);
void    free_ps(t_state *s);

/* reading    */
void    args_to_stack(t_stack *s, int ac, char **av);

/* sorting    */
void    start_alg(t_state *s);

/* instructions */
void	sa(t_state *s);
void	sb(t_state *s);
void	ra(t_state *s);
void	rb(t_state *s);
void	pa(t_state *s);
void	pb(t_state *s);
void	rra(t_state *s);
void	rrb(t_state *s);
void	rrr(t_state *s);
void	rr(t_state *s);
void	ss(t_state *s);

#endif
