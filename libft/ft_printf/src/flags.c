/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhelena <fhelena@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 18:29:25 by fhelena           #+#    #+#             */
/*   Updated: 2020/07/29 16:21:18 by fhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_length_fields(const char *str, t_flags *data)
{
	int	i;

	i = 0;
	if (*str == 'L')
	{
		data->mod = M_BL;
		++i;
	}
	if (*str == 'l')
	{
		--(data->mod);
		++i;
	}
	if (*str == 'h')
	{
		++(data->mod);
		++i;
	}
	return (i);
}

static int	get_flags_fields(const char *str, t_flags *data)
{
	int	i;

	i = 0;
	if (*str == '+')
	{
		data->plus = 1;
		++i;
	}
	if (*str == '-')
	{
		data->min = 1;
		++i;
	}
	if (*str == ' ')
	{
		data->space = 1;
		++i;
	}
	if (*str == '#')
	{
		data->sharp = 1;
		++i;
	}
	i += get_length_fields(str, data);
	return (i);
}

static int	check_field(t_flags *data, int field, int tmp)
{
	if (field)
	{
		if (tmp)
			data->prec = tmp;
		else
			data->p_zero = 1;
	}
	else
	{
		if (tmp < 0)
		{
			data->min = 1;
			tmp = -tmp;
		}
		if (tmp)
			data->width = tmp;
		else
			data->w_zero = 1;
	}
	return (tmp);
}

static int	get_len(const char *str, t_flags *data, va_list ap, int field)
{
	int	i;
	int	tmp;

	i = 0;
	if (str[i] == '.')
		if (str[++i] == 48 || (!(str[i] >= 48 && str[i] <= 57) && str[i] != 42))
		{
			data->p_zero = 1;
			if (str[i] == 48)
				++i;
		}
	if (str[i] == '*')
		tmp = va_arg(ap, int);
	else
		tmp = ft_atoi(&str[i]);
	tmp = check_field(data, field, tmp);
	if (str[i] == '*')
		tmp = 1;
	else if (tmp == 0)
		return (i);
	return (ft_nbrlen(tmp) + i);
}

int			flags_parser(const char *s, t_flags *data, va_list ap, int type_pos)
{
	int	flags_count;

	flags_count = 0;
	while (flags_count < type_pos)
	{
		if (s[flags_count] == '.')
		{
			data->flag = 1;
			flags_count += get_len(&s[flags_count], data, ap, 1);
		}
		else if (s[flags_count] == '0')
		{
			data->w_zero = 1;
			++flags_count;
		}
		else if (ft_isdigit(s[flags_count]) || s[flags_count] == '*')
			flags_count += get_len(&s[flags_count], data, ap, 0);
		else
			flags_count += get_flags_fields(&s[flags_count], data);
	}
	return (flags_count);
}
