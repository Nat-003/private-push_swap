/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nappasam <nappasam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 14:34:20 by nappasam          #+#    #+#             */
/*   Updated: 2026/03/09 14:16:42 by nappasam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_min_index(t_stack *a)
{
	int	i;
	int	min;
	int	min_index;

	min = a->data[0];
	min_index = 0;
	i = 1;
	while (i < a->size)
	{
		if (a->data[i] < min)
		{
			min = a->data[i];
			min_index = i;
		}
		i++;
	}
	return (min_index);
}

void	sort_five(t_program *p)
{
	int	min_index;
	int	reverse_moves;

	while (p->a->size > 3)
	{
		min_index = find_min_index(p->a);
		if (min_index <= p->a->size / 2)
		{
			while (min_index-- > 0)
				ra(p);
		}
		else
		{
			reverse_moves = p->a->size - min_index;
			while (reverse_moves-- > 0)
				rra(p);
		}
		pb(p);
	}
	sort_three(p);
	if (p->b->size > 1 && p->b->data[0] < p->b->data[1])
		sb(p);
	while (p->b->size > 0)
		pa(p);
}
