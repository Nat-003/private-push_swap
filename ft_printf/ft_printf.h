/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nappasam <nappasam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:31:57 by nappasam          #+#    #+#             */
/*   Updated: 2026/03/09 15:48:45 by nappasam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	check_format(const char format_c, va_list *args);
int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int n);
int	ft_puthex_lower(unsigned int n);
int	ft_puthex_upper(long long n);
int	ft_print_pointer(void *p);
int	ft_putnbr_unsigned(unsigned int n);
int	ft_strlen(const char *str);
int	intlen(int n);
int	intlen_unsigend(unsigned int n);
int	ft_puthex_lower_pointer(unsigned long n);
int	ft_putfloat(double n);
#endif
