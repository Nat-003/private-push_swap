/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgliga <rgliga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 16:21:11 by rgliga            #+#    #+#             */
/*   Updated: 2026/03/05 16:21:39 by rgliga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_position(t_stack *x, int max)
{
	int	i;

	i = 0;
	while (i < x->size)
	{
		if (x->data[i] == max)
			return (i);
		i++;
	}
	return (-1);
}

void	push_back_to_a(t_program *p)
{
	int	max_val;
	int	pos;

	while (p->b->size > 0)
	{
		max_val = find_max_value(p->b);
		pos = find_position(p->b, max_val);
		while (pos != 0)
		{
			if (pos <= p->b->size / 2)
				rb(p);
			else
				rrb(p);
			pos = find_position(p->b, max_val);
		}
		pa(p);
	}
}
void	innit_vars(int *bucket_count, int *bucket_size, int *current_min,
		int *current_max, int original_size)
{
	*bucket_count = ft_sqrt(original_size);
	if (*bucket_count == 0)
		*bucket_count = 1;
	*bucket_size = original_size / (*bucket_count);
	*current_min = 0;
	*current_max = *bucket_size - 1;
}
void	push_a_to_b(t_program *p, int original_size)
{
	int	i;
	int	bucket_count;
	int	bucket_size;
	int	current_min;
	int	current_max;

	innit_vars(&bucket_count, &bucket_size, &current_min, &current_max,
		original_size);
	i = 0;
	while (i < bucket_count)
	{
		if (i == bucket_count - 1)
			current_max = original_size - 1;
		while (still_in_bucket(p->a, current_min, current_max))
		{
			if (p->a->data[0] >= current_min && p->a->data[0] <= current_max)
				pb(p);
			else
				ra(p);
		}
		current_min += bucket_size;
		current_max += bucket_size;
		i++;
	}
}
void	change_value_to_indexes(t_stack *a, t_ops *ops, int original_size,
		int *copy)
{
	int	i;
	int	j;

	i = 0;
	while (i < original_size)
	{
		j = 0;
		while (j < original_size)
		{
			if (a->data[i] == copy[j])
			{
				a->data[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
}