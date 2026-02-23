/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nappasam <nappasam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 20:54:39 by nappasam          #+#    #+#             */
/*   Updated: 2026/02/23 20:55:36 by nappasam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_valid_num(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (s[i] == '\0')
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
long	ft_atol(char *s)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i])
	{
		result = result * 10 + (s[i] - '0');
		i++;
	}
	return (result * sign);
}
int	is_dup(t_stack *a, int value)
{
	int	i;

	i = 0;
	while (i < a->size)
	{
		if (a->data[i] == value)
			return (1);
		i++;
	}
	return (0);
}
void	push_value_to_a(t_stack *a, int value)
{
	a->data[a->size] = value;
	a->size = a->size + 1;
}

void	free_split(char **s)
{
	int	j;

	j = 0;
	while (s[j])
	{
		free(s[j]);
		j++;
	}
	free(s);
}