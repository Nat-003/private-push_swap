/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgliga <rgliga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 14:18:37 by nappasam          #+#    #+#             */
/*   Updated: 2026/03/11 13:42:12 by rgliga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(2, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	return (ft_strlen(str));
}

int	ft_putnbr(int n)
{
	int	og;

	og = n;
	if (n == -2147483648)
	{
		return (write(2, "-2147483648", 11));
	}
	if (n < 0)
	{
		write(2, "-", 1);
		n = n * (-1);
	}
	if (n >= 0 && n <= 9)
	{
		n = n + '0';
		write(2, &n, 1);
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	return (intlen(og));
}

int	ft_puthex_lower(unsigned int n)
{
	int		count;
	char	*base;

	count = 0;
	base = "0123456789abcdef";
	if (n >= 16)
		count += ft_puthex_lower(n / 16);
	count += ft_putchar(base[n % 16]);
	return (count);
}
