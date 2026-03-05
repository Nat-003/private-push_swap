/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgliga <rgliga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 16:11:54 by rgliga            #+#    #+#             */
/*   Updated: 2026/03/05 16:25:18 by rgliga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* The fixed Bucket Sort logic */
void	bucket_sort(t_program *p)
{
	int	*copy;
	int	original_size;
	int	index_stored;

	original_size = p->a->size;
	int i, j, bucket_count, bucket_size, current_min, current_max;
	copy = copy_arr(p->a);
	if (!&copy_arr)
		return ;
	sort_array(copy, original_size);
	change_value_to_indexes(p->a, p->ops, original_size, copy);
	push_a_to_b(p, original_size);
	push_back_to_a(p);
	i = 0;
	while (i < p->a->size)
	{
		index_stored = p->a->data[i];
		p->a->data[i] = copy[index_stored];
		i++;
	}
	free(copy);
}

void	bucket_sorting(t_program *p)
{
	if (p->a->size <= 3)
		sort_three(p);
	else if (p->a->size <= 5)
		sort_five(p);
	else
		bucket_sort(p);
}
