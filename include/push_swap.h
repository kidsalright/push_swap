/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 20:01:37 by yberries          #+#    #+#             */
/*   Updated: 2020/10/06 17:40:00 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct	s_psl
{
		int				num;
		struct s_psl	*prev;
		struct s_psl	*next;
}				t_psl;

typedef struct	s_pslist
{
		t_psl	*start;
		t_psl	*end;
}				t_pslist;

void	output_stack(t_psl *s);
void	check_dups(t_psl *head);
int		ps_atoi(const char *str);
void	ft_exit();
void    free_ps(t_psl *s);
int		is_sorted(int *s, int l);


#endif
