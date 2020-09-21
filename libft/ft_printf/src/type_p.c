/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhelena <fhelena@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 22:05:29 by fhelena           #+#    #+#             */
/*   Updated: 2020/07/30 18:03:56 by fhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	prec_parse(t_flags *data, char *s)
{
	if (data->p_zero && !data->prec && !ft_atoi(s))
		return ;
	ft_putstr(s);
	data->len += ft_strlen(s);
}

static void	width_parse(t_flags *data, char *s, char type)
{
	int	len;
	int	width;

	len = ft_strlen(s);
	width = get_width(data, len + 2, type);
	if (data->w_zero && !data->p_zero && !data->prec)
		ft_putstr("0x");
	if (!data->min)
		print_width(data, width, type);
	if (!data->w_zero || data->p_zero || data->prec)
		ft_putstr("0x");
	data->len += 2;
	prec_parse(data, s);
	if (data->min)
		print_width(data, width, type);
}

void		ptr_parse(t_flags *data, va_list ap)
{
	unsigned long long int	p;
	char					*str;

	p = va_arg(ap, unsigned long long int);
	str = ptf_itoa_base(p, 16, "0123456789abcdef", 0);
	width_parse(data, str, 'p');
	free(str);
}
