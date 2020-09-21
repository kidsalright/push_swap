/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhelena <fhelena@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 20:28:51 by fhelena           #+#    #+#             */
/*   Updated: 2020/09/21 19:35:21 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	prec_parse(t_flags *data, char *s, int len)
{
	if (data->p_zero && len == 1 && s[0] == '0')
		return ;
	if (data->prec > len)
		print_prec(data, data->prec - len, 'd');
	ft_putstr(s);
	data->len += len;
}

static void	print_specials(t_flags *data, int minus)
{
	if (data->space)
	{
		ft_putchar(' ');
		++data->len;
	}
	if (data->w_zero && !data->prec)
		print_sign(data, minus);
}

static int	check_width(t_flags *data, int len, int minus, char type)
{
	int	width;

	width = 0;
	if (data->prec >= len)
		width = get_width(data, data->prec + minus, type);
	else if (data->width)
		width = get_width(data, len + minus, type);
	if ((data->plus || data->space) && !minus && width)
		--width;
	return (width);
}

static void	width_parse(t_flags *data, char *s, char type)
{
	int	len;
	int	minus;
	int	width;

	minus = 0;
	len = ft_strlen(s);
	if (s[0] == '-')
	{
		minus = 1;
		++s;
		--len;
	}
	width = check_width(data, len, minus, type);
	if (data->p_zero && len == 1 && s[0] == '0' && !data->plus && !data->space)
		width = data->width;
	if (!data->min)
	{
		print_specials(data, minus);
		print_width(data, width, type);
	}
	if ((!data->w_zero && !data->prec) || data->prec || data->min)
		print_sign(data, minus);
	prec_parse(data, s, len);
	if (data->min)
		print_width(data, width, type);
}

void		int_parse(t_flags *data, va_list ap)
{
	long long int	d;
	char			*str;

	d = va_arg(ap, long long int);
	if (data->mod == M_LL)
		d = (long long int)d;
	else if (data->mod == M_L)
		d = (long int)d;
	else if (data->mod == M_H)
		d = (short int)d;
	else if (data->mod == M_HH)
		d = (char)d;
	else
		d = (int)d;
	str = ptf_itoa_base(d, 10, "0123456789", 1);
	width_parse(data, str, 'd');
	free(str);
}
