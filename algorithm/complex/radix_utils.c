/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nappasam <nappasam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 16:26:46 by nappasam          #+#    #+#             */
/*   Updated: 2026/03/06 16:36:11 by nappasam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	radix_ops(t_program *p, int n, int bit)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (((p->a->data[0] >> bit) & 1) == 0)
			pb(p);
		else
			ra(p);
		i++;
	}
	while (p->b->size > 0)
		pa(p);
}
