/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nappasam <nappasam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 16:07:18 by rgliga            #+#    #+#             */
/*   Updated: 2026/03/06 15:16:47 by nappasam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	radix_lsd_sorting(t_program *p)
{
	if (p->a->size <= 3)
		sort_three(p);
	else if (p->a->size <= 5)
		sort_five(p);
	else
		radix_lsd_sort(p);
}
