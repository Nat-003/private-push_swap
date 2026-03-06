/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nappasam <nappasam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 16:11:54 by rgliga            #+#    #+#             */
/*   Updated: 2026/03/06 16:31:36 by nappasam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	bucket_sort(t_program *p)
{
	int	*copy;
	int	original_size;
	int	index_stored;
	int	i;

	original_size = p->a->size;
	copy = copy_arr(p->a);
	if (!&copy_arr)
		return ;
	sort_array(copy, original_size);
	change_value_to_indexes(p->a, original_size, copy);
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
