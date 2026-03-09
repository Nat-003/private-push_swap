/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nappasam <nappasam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 14:07:06 by marvin            #+#    #+#             */
/*   Updated: 2026/03/09 15:50:07 by nappasam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putlong_simple(long n)
{
	int	len;

	len = 0;
	if (n >= 10)
		len += ft_putlong_simple(n / 10);
	len += ft_putchar((n % 10) + '0');
	return (len);
}

int	ft_putfloat(double n)
{
	int		count;
	long	int_part;
	int		precision;
	int		digit;

	count = 0;
	precision = 2;
	if (n < 0)
	{
		count += ft_putchar('-');
		n = -n;
	}
	n += 0.005;
	int_part = (long)n;
	count += ft_putlong_simple(int_part);
	count += ft_putchar('.');
	n -= (double)int_part;
	while (precision--)
	{
		n *= 10;
		digit = (int)n;
		count += ft_putchar(digit + '0');
		n -= (double)digit;
	}
	return (count);
}
