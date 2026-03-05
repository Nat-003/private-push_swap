/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgliga <rgliga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 20:49:34 by nappasam          #+#    #+#             */
/*   Updated: 2026/03/05 14:48:42 by rgliga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	cout_total_number(char **av, int k)
{
	int		count;
	int		total;
	char	**split;

	count = 0;
	total = 0;
	while (av[k])
	{
		count = 0;
		split = ft_split(av[k], ' ');
		if (!split)
			error_exit();
		while (split[count])
			count++;
		total += count;
		free_split(split);
		k++;
	}
	return (total);
}

void	validate(char **split2, t_stack *a)
{
	int		count;
	long	value;

	count = 0;
	while (split2[count])
	{
		if (!is_valid_num(split2[count]))
			free_all(split2, a);
		value = ft_atol(split2[count]);
		if (value < INT_MIN || value > INT_MAX)
			free_all(split2, a);
		if (is_dup(a, (int)value))
			free_all(split2, a);
		push_value_to_a(a, (int)value);
		count++;
	}
}

void	validate_and_build(char **av, t_stack *a, int i)
{
	char	**split2;

	while (av[i])
	{
		split2 = ft_split(av[i], ' ');
		if (!split2)
			free_all(NULL, a);
		validate(split2, a);
		free_split(split2);
		i++;
	}
}

t_config	parser(char **av, t_stack *a)
{
	int			i;
	int			k;
	int			total;
	t_config	config;
	long		value;

	config.simple = 0;
	config.medium = 0;
	config.complex = 0;
	config.adaptative = 0;
	config.bench = 0;
	i = check_flags(av, &config);
	k = i;
	total = cout_total_number(av, k);
	if (total == 0)
		exit(1);
	a->data = malloc(sizeof(int) * total);
	if (!a->data)
		error_exit();
	a->size = 0;
	if (!config.simple && !config.medium && !config.complex
		&& !config.adaptative)
		config.adaptative = 1;
	validate_and_build(av, a, i);
	return (config);
}

void	free_all(char **s, t_stack *a)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (s)
	{
		while (s[j])
		{
			free(s[j]);
			j++;
		}
		free(s);
	}
	if (a->data)
		free(a->data);
	error_exit();
}
