/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgliga <rgliga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 20:52:17 by nappasam          #+#    #+#             */
/*   Updated: 2026/03/05 14:45:04 by rgliga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	check_config(t_config *config)
{
	if (config->adaptative + config->complex + config->medium
		+ config->simple > 1)
		error_exit();
}

void	set_flags(char *flag, t_config *config)
{
	if (ft_strcmp(flag, "--simple") == 0)
	{
		config->simple = 1;
		check_config(config);
	}
	else if (ft_strcmp(flag, "--medium") == 0)
	{
		config->medium = 1;
		check_config(config);
	}
	else if (ft_strcmp(flag, "--complex") == 0)
	{
		config->complex = 1;
		check_config(config);
	}
	else if (ft_strcmp(flag, "--adaptative") == 0)
	{
		config->adaptative = 1;
		check_config(config);
	}
	else if (ft_strcmp(flag, "--bench") == 0)
		config->bench = 1;
	else
		error_exit();
}

int	check_flags(char **av, t_config *config)
{
	int	i;

	i = 1;
	while (av[i] && av[i][0] == '-' && av[i][1] == '-')
	{
		set_flags(av[i], config);
		i++;
	}
	return (i);
}
