/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nappasam <nappasam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 16:21:11 by rgliga            #+#    #+#             */
/*   Updated: 2026/03/06 16:13:57 by nappasam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	innit_vars(t_bucket *b, int original_size)
{
	b->bucket_count = ft_sqrt(original_size);
	if (b->bucket_count == 0)
		b->bucket_count = 1;
	b->bucket_size = original_size / b->bucket_count;
	b->current_min = 0;
	b->current_max = b->bucket_size - 1;
}

void	push_a_to_b(t_program *p, int original_size)
{
	int			i;
	t_bucket	b;

	innit_vars(&b, original_size);
	i = 0;
	while (i < b.bucket_count)
	{
		if (i == b.bucket_count - 1)
			b.current_max = original_size - 1;
		while (still_in_bucket(p->a, b.current_min, b.current_max))
		{
			if (p->a->data[0] >= b.current_min
				&& p->a->data[0] <= b.current_max)
				pb(p);
			else
				ra(p);
		}
		b.current_min += b.bucket_size;
		b.current_max += b.bucket_size;
		i++;
	}
}

void	change_value_to_indexes(t_stack *a, int original_size, int *copy)
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
