/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nappasam <nappasam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 15:53:36 by nappasam          #+#    #+#             */
/*   Updated: 2026/03/06 15:56:48 by nappasam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	select_algorithm(float d, t_program *p)
{
	if (d < 0.30f)
	{
		bubble_sorting(p);
	}
	else if (d <= 0.50f)
	{
		bucket_sorting(p);
	}
	else
	{
		radix_lsd_sorting(p);
	}
}

void	set_bench(t_program *p, float d)
{
	if (p->config->simple && p->config->bench)
	{
		bubble_sorting(p);
		bench(p->ops, d, p->config);
	}
	else if (p->config->medium && p->config->bench)
	{
		bucket_sorting(p);
		bench(p->ops, d, p->config);
	}
	else if (p->config->complex && p->config->bench)
	{
		radix_lsd_sorting(p);
		bench(p->ops, d, p->config);
	}
	else if (p->config->adaptative && p->config->bench)
	{
		select_algorithm(d, p);
		bench(p->ops, d, p->config);
	}
}

void	set_config(t_program *p, float d)
{
	if (p->config->bench)
	{
		set_bench(p, d);
	}
	else if (p->config->simple)
	{
		bubble_sorting(p);
	}
	else if (p->config->medium)
	{
		bucket_sorting(p);
	}
	else if (p->config->complex)
	{
		radix_lsd_sorting(p);
	}
	else if (p->config->adaptative)
	{
		select_algorithm(d, p);
	}
}

int	is_sorted(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->size - 1)
	{
		if (a->data[i] > a->data[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	innit_ops(t_ops *ops)
{
	ops->sa = 0;
	ops->sb = 0;
	ops->ss = 0;
	ops->pa = 0;
	ops->pb = 0;
	ops->ra = 0;
	ops->rb = 0;
	ops->rr = 0;
	ops->rra = 0;
	ops->rrb = 0;
	ops->rrr = 0;
}
