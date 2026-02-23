/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nappasam <nappasam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 20:49:34 by nappasam          #+#    #+#             */
/*   Updated: 2026/02/23 20:57:30 by nappasam         ###   ########.fr       */
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
	int	count;
	int	value;

	count = 0;
	while (split2[count])
	{
		if (!is_valid_num(split2[count]))
			error_exit();
		value = ft_atol(split2[count]);
		if (value < INT_MIN || value > INT_MAX)
			error_exit();
		if (is_dup(a, (int)value))
			error_exit();
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
			error_exit();
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
		error_exit();
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
