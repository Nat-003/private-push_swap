/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nappasam <nappasam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 14:34:46 by nappasam          #+#    #+#             */
/*   Updated: 2026/03/04 14:44:32 by nappasam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_program *p)
{
	int	max;
	int	i;
	int	max_index;

	max = p->a->data[0];
	i = 0;
	max_index = 0;
	while (i < p->a->size)
	{
		if (p->a->data[i] > max)
		{
			max = p->a->data[i];
			max_index = i;
		}
		i++;
	}
	if (max_index == 0)
		ra(p);
	else if (max_index == 1)
		rra(p);
	if (p->a->data[0] > p->a->data[1])
		sa(p);
}
