/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgliga <rgliga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:34:01 by nappasam          #+#    #+#             */
/*   Updated: 2026/03/11 13:40:57 by rgliga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;

	va_start(args, format);
	if (!format || (write(2, "", 0) == -1))
		return (-1);
	i = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1) != '\0')
		{
			i += check_format(*(format + 1), &args);
			format++;
		}
		else
		{
			i += ft_putchar(*format);
		}
		format++;
	}
	va_end(args);
	return (i);
}
