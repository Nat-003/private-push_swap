/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nappasam <nappasam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 15:03:16 by nappasam          #+#    #+#             */
/*   Updated: 2026/03/06 15:09:15 by nappasam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_all(char **s, t_stack *a)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (s)
	{
		while (s[j])
		{
			free(s[j]);
			j++;
		}
		free(s);
	}
	if (a->data)
		free(a->data);
	error_exit();
}
