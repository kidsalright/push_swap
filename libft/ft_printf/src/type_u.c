/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhelena <fhelena@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 21:00:58 by fhelena           #+#    #+#             */
/*   Updated: 2020/07/31 14:56:20 by fhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	prec_parse(t_flags *data, char *s, int len)
{
	if (data->p_zero && len == 1 && s[0] == '0')
		return ;
	if (data->prec > len)
		print_prec(data, data->prec - len, 'x');
	ft_putstr(s);
	data->len += len;
}

static int	check_width(t_flags *data, int len)
{
	int	width;

	width = 0;
	if (data->prec >= len)
		width = get_width(data, data->prec, 'x');
	else
		width = get_width(data, len, 'x');
	return (width);
}

static void	width_parse(t_flags *data, char *s, char type)
{
	int	len;
	int	width;

	len = ft_strlen(s);
	width = check_width(data, len);
	if (data->p_zero && len == 1 && s[0] == '0')
		width = data->width;
	if (!data->min)
		print_width(data, width, 'o');
	prec_parse(data, s, len);
	if (data->min)
		print_width(data, width, type);
}

void		uint_parse(t_flags *data, va_list ap)
{
	unsigned long long int	u;
	char					*str;

	u = va_arg(ap, unsigned long long int);
	if (data->mod == M_LL)
		u = (unsigned long long int)u;
	else if (data->mod == M_L)
		u = (unsigned long int)u;
	else if (data->mod == M_H)
		u = (unsigned short int)u;
	else if (data->mod == M_HH)
		u = (unsigned char)u;
	else
		u = (unsigned int)u;
	str = ptf_itoa_base(u, 10, "0123456789", 0);
	width_parse(data, str, 'u');
}
