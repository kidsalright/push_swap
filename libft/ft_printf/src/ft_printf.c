/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhelena <fhelena@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 19:14:11 by fhelena           #+#    #+#             */
/*   Updated: 2020/07/28 14:09:07 by fhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_type	g_type[] =
{
	{'c', &char_parse},
	{'s', &string_parse},
	{'p', &ptr_parse},
	{'d', &int_parse},
	{'i', &int_parse},
	{'o', &oct_parse},
	{'u', &uint_parse},
	{'x', &hexx_parse},
	{'X', &hex_parse},
	{'f', &float_parse},
	{'%', &percent_parse},
	{0, NULL}
};

static int	get_type_pos(const char *str)
{
	char	*types;
	int		i;
	int		j;

	types = "cspdiouxXf%";
	i = 0;
	while (str[i])
	{
		j = 0;
		while (types[j])
		{
			if (types[j] == str[i])
				return (i);
			++j;
		}
		++i;
	}
	return (0);
}

static int	ft_parser(const char *str, va_list ap, t_flags *data)
{
	int	i;
	int	type_pos;
	int	type_len;
	int	flags_count;

	flags_count = 0;
	if ((type_pos = get_type_pos(str)))
		flags_count = flags_parser(str, data, ap, type_pos);
	i = 0;
	while (g_type[i].value && str[flags_count] != g_type[i].value)
		++i;
	type_len = 0;
	if (g_type[i].value)
	{
		g_type[i].f(data, ap);
		++type_len;
	}
	return (type_len + flags_count);
}

static void	init(t_flags *data)
{
	data->mod = 0;
	data->min = 0;
	data->plus = 0;
	data->flag = 0;
	data->star = 0;
	data->prec = 0;
	data->width = 0;
	data->sharp = 0;
	data->space = 0;
	data->w_zero = 0;
	data->p_zero = 0;
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	t_flags	data;
	int		i;
	int		placeholder_len;

	i = 0;
	data.len = 0;
	va_start(ap, format);
	while (format[i])
	{
		while (format[i] && format[i] != '%')
		{
			ft_putchar(format[i++]);
			++data.len;
		}
		if (format[i] == '%')
		{
			init(&data);
			placeholder_len = ft_parser(&format[++i], ap, &data);
			i += placeholder_len;
		}
	}
	va_end(ap);
	return (data.len);
}
