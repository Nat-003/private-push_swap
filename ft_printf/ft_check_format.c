/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nappasam <nappasam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:33:29 by nappasam          #+#    #+#             */
/*   Updated: 2026/03/09 15:48:31 by nappasam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_format(const char format_c, va_list *args)
{
	int	count;

	count = 0;
	if (format_c == 's')
		count = ft_putstr(va_arg(*args, char *));
	else if (format_c == 'c')
		count = ft_putchar(va_arg(*args, int));
	else if (format_c == 'd' || format_c == 'i')
		count = ft_putnbr(va_arg(*args, int));
	else if (format_c == 'x')
		count = ft_puthex_lower(va_arg(*args, int));
	else if (format_c == 'X')
		count = ft_puthex_upper(va_arg(*args, int));
	else if (format_c == 'p')
		count = ft_print_pointer(va_arg(*args, void *));
	else if (format_c == 'u')
		count = ft_putnbr_unsigned(va_arg(*args, unsigned int));
	else if (format_c == '%')
		count = ft_putchar('%');
	else if (format_c == 'f')
		count = ft_putfloat(va_arg(*args, double));
	return (count);
}
