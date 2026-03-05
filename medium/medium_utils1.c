/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgliga <rgliga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 16:20:05 by rgliga            #+#    #+#             */
/*   Updated: 2026/03/05 16:20:51 by rgliga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sqrt(int x)
{
	long	i;

	if (x <= 0)
		return (0);
	if (x == 1)
		return (1);
	i = 1;
	while (i * i <= x)
	{
		if (i * i == x)
			return ((int)i);
		i++;
	}
	return ((int)i - 1);
}

int	*copy_arr(t_stack *a)
{
	int	i;
	int	*copy;

	copy = malloc(sizeof(int) * a->size);
	if (!copy)
		return (NULL);
	while (i < a->size)
	{
		copy[i] = a->data[i];
		i++;
	}
	return (copy);
}

void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = 0;
	tmp = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	still_in_bucket(t_stack *a, int min, int max)
{
	int	i;

	i = 0;
	while (i < a->size)
	{
		if (a->data[i] >= min && a->data[i] <= max)
			return (1);
		i++;
	}
	return (0);
}

int	find_max_value(t_stack *x)
{
	int	i;
	int	current_max;

	i = 0;
	current_max = x->data[0];
	while (i < x->size)
	{
		if (x->data[i] > current_max)
			current_max = x->data[i];
		i++;
	}
	return (current_max);
}