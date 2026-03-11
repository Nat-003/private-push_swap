/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgliga <rgliga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 14:20:15 by nappasam          #+#    #+#             */
/*   Updated: 2026/03/11 13:42:24 by rgliga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_upper(long long n)
{
	int				count;
	unsigned int	x;
	char			*base;

	count = 0;
	base = "0123456789ABCDEF";
	x = (unsigned int)n;
	if (x >= 16)
		count += ft_puthex_upper(x / 16);
	count += ft_putchar(base[x % 16]);
	return (count);
}

int	ft_print_pointer(void *p)
{
	long long		i;
	unsigned long	ptr;

	i = 2;
	ptr = (unsigned long)p;
	if (!p)
	{
		write(2, "(nil)", 5);
		return (i = 5);
	}
	write(1, "0x", 2);
	i += ft_puthex_lower_pointer(ptr);
	return (i);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	unsigned int	og;

	og = n;
	if (n <= 9)
	{
		n = n + '0';
		write(2, &n, 1);
	}
	else
	{
		ft_putnbr_unsigned(n / 10);
		ft_putnbr_unsigned(n % 10);
	}
	return (intlen_unsigend(og));
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}
