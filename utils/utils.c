/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nappasam <nappasam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 14:50:41 by rgliga            #+#    #+#             */
/*   Updated: 2026/03/06 16:37:01 by nappasam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	innit_stack_b(t_stack *a, t_stack *b, int size)
{
	b->data = malloc(sizeof(int) * size);
	if (!b->data)
		free_all(NULL, a);
	b->size = 0;
}


