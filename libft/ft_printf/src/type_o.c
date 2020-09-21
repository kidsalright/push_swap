/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhelena <fhelena@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 21:05:17 by fhelena           #+#    #+#             */
/*   Updated: 2020/07/30 18:03:44 by fhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	prec_parse(t_flags *data, char *s, int len)
{
	if (data->prec > len)
		print_prec(data, data->prec - len, 'o');
	ft_putstr(s);
	data->len += len;
}

static int	check_width(t_flags *data, int len, char type)
{
	int	width;

	width = 0;
	if (data->prec >= len)
		width = get_width(data, data->prec, type);
	else if (data->width)
		width = get_width(data, len, type);
	return (width);
}

static void	width_parse(t_flags *data, char *s, char type)
{
	int	len;
	int	width;

	len = ft_strlen(s);
	width = check_width(data, len, type);
	if (width && data->sharp && ft_atoi(s) && data->prec <= len)
		--width;
	if (!data->min)
		print_width(data, width, type);
	if (data->sharp && ft_atoi(s) && data->prec <= len)
	{
		ft_putchar('0');
		++data->len;
	}
	prec_parse(data, s, len);
	if (data->min)
		print_width(data, width, type);
}

void		oct_parse(t_flags *data, va_list ap)
{
	unsigned long long int	o;
	char					*str;

	o = va_arg(ap, unsigned long long int);
	if (data->mod == M_LL)
		o = (unsigned long long int)o;
	else if (data->mod == M_L)
		o = (unsigned long int)o;
	else if (data->mod == M_H)
		o = (unsigned short int)o;
	else if (data->mod == M_HH)
		o = (unsigned char)o;
	else
		o = (unsigned int)o;
	str = ptf_itoa_base(o, 8, "01234567", 0);
	width_parse(data, str, 'o');
	free(str);
}
