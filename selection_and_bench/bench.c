/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nappasam <nappasam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 17:13:18 by nappasam          #+#    #+#             */
/*   Updated: 2026/03/09 15:48:05 by nappasam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	total_operation(t_ops *ops)
{
	int	sum;

	sum = 0;
	ft_printf("sa  : %d\n", ops->sa);
	ft_printf("sb  : %d\n", ops->sb);
	ft_printf("ss  : %d\n", ops->ss);
	ft_printf("pa  : %d\n", ops->pa);
	ft_printf("pb  : %d\n", ops->pb);
	ft_printf("ra  : %d\n", ops->ra);
	ft_printf("rb  : %d\n", ops->rb);
	ft_printf("rr  : %d\n", ops->rr);
	ft_printf("rra : %d\n", ops->rra);
	ft_printf("rrb : %d\n", ops->rrb);
	ft_printf("rrr : %d\n", ops->rrr);
	sum = ops->sa + ops->sb + ops->ss + ops->pa + ops->pb + ops->ra + ops->rb
		+ ops->rr + ops->rra + ops->rrb + ops->rrr;
	return (sum);
}

char	*adaptative_strat(float d)
{
	char	*res;

	res = "";
	if (d < 0.30f)
		res = "Simple / O(n2)";
	else if (d <= 0.50f)
		res = "Medium / O(nVn)";
	else
		res = "Complex / O(n log n)";
	return (res);
}

char	*strat(t_config *config, float d)
{
	char	*res;

	res = "";
	if (config->simple)
		res = "Simple O(n2)";
	else if (config->medium)
		res = "Medium O(nVn)";
	else if (config->complex)
		res = "Complex O(n log n)";
	else if (config->adaptative)
		res = adaptative_strat(d);
	return (res);
}

void	bench(t_ops *ops, float d, t_config *config)
{
	int		res;
	char	*strategy;

	res = total_operation(ops);
	strategy = strat(config, d);
	ft_printf("strategy: %s\n", strategy);
	ft_printf("disorder: %f %% \n", d);
	ft_printf("Total operations: %d\n", res);
}
