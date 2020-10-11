/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 20:01:37 by yberries          #+#    #+#             */
/*   Updated: 2020/10/11 06:26:59 by yberries         ###   ########.fr       */
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

typedef struct	s_pslist
{
		char	vis;
		int		len;
		t_psl	*start;
		t_psl	*end;
}				t_pslist;

/* lst_tools  */
void    create_stack(t_pslist *s);
void    push_front(t_pslist *s, int i);
void    pop_front(t_pslist *s);
void    push_end(t_pslist *s, int i);
void    free_ps(t_psl *s);

/* out_tools  */
void    out_res(t_pslist *sa, t_pslist *sb, char *instr);
void	ft_exit(void);

/* ps_tools   */
int		is_sorted(t_psl *s);
int		ps_atoi(char **str, char sign);
void	check_dups(t_psl *head);

/* push_swap  */

/* reading    */
void    args_to_stack(t_pslist *sa, int ac, char **av);

/* sorting    */
void    start_alg(t_pslist *sa);

/* instructions */
void    rotate_stack(t_pslist *s);

#endif
