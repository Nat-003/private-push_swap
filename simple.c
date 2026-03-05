/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgliga <rgliga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 14:51:05 by rgliga            #+#    #+#             */
/*   Updated: 2026/03/05 14:52:52 by rgliga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(t_program *p)
{
	int	i;
	int	j;
	int	swapped;

	i = 0;
	while (i < p->a->size - 1)
	{
		swapped = 0;
		j = 0;
		while (j < p->a->size - 1)
		{
			if (p->a->data[0] > p->a->data[1])
			{
				sa(p);
				swapped = 1;
			}
			ra(p);
			j++;
		}
		ra(p);
		if (swapped == 0)
			return ;
		i++;
	}
}

void	bubble_sorting(t_program *p)
{
	if (p->a->size <= 3)
		sort_three(p);
	else if (p->a->size <= 5)
		sort_five(p);
	else
		bubble_sort(p);
}
