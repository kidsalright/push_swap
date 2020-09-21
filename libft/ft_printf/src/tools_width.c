/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhelena <fhelena@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 17:59:30 by fhelena           #+#    #+#             */
/*   Updated: 2020/07/31 16:12:47 by fhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	get_char(t_flags *data, char type)
{
	if (data->min)
		return (' ');
	else if (data->p_zero && (type == 'o' || type == 'x' || type == 'd'))
		return (' ');
	else if (data->w_zero && (type == 'f' || (type == 'd' && data->prec < 0)))
		return ('0');
	else if (data->w_zero && !data->prec)
		return ('0');
	else
		return (' ');
}

void		print_width(t_flags *data, int width, char type)
{
	char	c;

	c = get_char(data, type);
	while (width--)
	{
		ft_putchar(c);
		++data->len;
	}
}

/*
** May be move check types to get_char()
** And may be delete one print_.._char()
*/

void		print_prec(t_flags *data, int prec, char type)
{
	char	c;

	c = get_char(data, type);
	if (type == 'd' || type == 'o' || type == 'x' || type == 'u')
		c = '0';
	while (prec--)
	{
		ft_putchar(c);
		++data->len;
	}
}

int			get_width(t_flags *data, int len, char type)
{
	if (data->width)
	{
		if (data->prec)
		{
			if (data->prec >= len && data->width > len)
				return (data->width - len);
			else if (data->width > len && (type == 'd' || type == 'x'))
				return (data->width - len);
			else if (data->width <= len && (type == 'd' || type == 'x'))
				return (0);
			else if (data->width > data->prec)
				return (data->width - data->prec);
		}
		else if (data->p_zero)
			if (data->width < len && type != 's')
				return (len - data->width);
			else if (type == 'o' || type == 'x' || type == 'd')
				return (data->width - len);
			else
				return (data->width);
		else if (data->width > len)
			return (data->width - len);
	}
	return (0);
}
