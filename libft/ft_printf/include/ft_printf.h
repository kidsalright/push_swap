/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhelena <fhelena@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 19:14:54 by fhelena           #+#    #+#             */
/*   Updated: 2020/07/30 23:26:36 by fhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include "structs.h"

int			ft_printf(const char *format, ...);
int			flags_parser(const char *str, t_flags *data, va_list ap, int type);

/*
** Special functions for formatting, counting, etc.
*/
int			get_width(t_flags *data, int len, char type);
void		print_width(t_flags *data, int width, char type);
void		print_prec(t_flags *data, int prec, char type);
void		print_sign(t_flags *data, int minus);
long double	ft_power(long long int nb, int power);
char		*ptf_itoa_base(long long int value, int base, char *b, char flag);

/*
** Types parsers
*/

void		percent_parse(t_flags *data, va_list ap);
void		char_parse(t_flags *data, va_list ap);
void		string_parse(t_flags *data, va_list ap);
void		int_parse(t_flags *data, va_list ap);
void		float_parse(t_flags *data, va_list ap);
void		oct_parse(t_flags *data, va_list ap);
void		hex_parse(t_flags *data, va_list ap);
void		hexx_parse(t_flags *data, va_list ap);
void		uint_parse(t_flags *data, va_list ap);
void		ptr_parse(t_flags *data, va_list ap);

#endif
