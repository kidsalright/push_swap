/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhelena <fhelena@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 17:59:06 by fhelena           #+#    #+#             */
/*   Updated: 2020/07/30 23:26:01 by fhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_sign(t_flags *data, int minus)
{
	if (data->plus && !minus)
	{
		ft_putchar('+');
		++data->len;
	}
	else if (data->space && minus)
	{
		ft_putchar(' ');
		++data->len;
	}
	if (minus)
	{
		ft_putchar('-');
		++data->len;
	}
}

long double	ft_power(long long int nb, int power)
{
	if (nb == 0 || power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_power(nb, power - 1));
}

static int	itoa_len(unsigned long long int value, int base)
{
	int	i;

	i = 1;
	while (value /= base)
		++i;
	return (i);
}

char		*ptf_itoa_base(long long int value, int base, char *b, char flag)
{
	unsigned long long int	n;
	char					*str;
	int						i;
	int						sign;

	sign = 0;
	if (flag && (sign = value < 0))
		n = ~(unsigned long long int)value + 1;
	else
		n = value;
	i = itoa_len(n, base) + sign;
	str = (char *)malloc(sizeof(char) * (i + 1));
	str[i--] = '\0';
	if (value == 0)
		str[0] = '0';
	if (sign)
		str[0] = '-';
	str[i--] = b[n % base];
	while ((n /= base) > 0)
		str[i--] = b[n % base];
	return (str);
}
