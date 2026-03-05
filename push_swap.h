/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgliga <rgliga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 14:53:15 by rgliga            #+#    #+#             */
/*   Updated: 2026/03/05 16:00:42 by rgliga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> 
# include <limits.h>

typedef struct s_ops
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_ops;

typedef struct s_stack
{
	int	*data;
	int	size;
}	t_stack;

typedef struct s_config
{
	int	simple;
	int	medium;
	int	complex;
	int	adaptative;
	int	bench;
}	t_config;

typedef struct s_program
{
	t_stack		*a;
	t_stack		*b;
	t_ops		*ops;
	t_config	*config;
}	t_program;

// parser

t_config	parser(char **av, t_stack *a);

void		sort_three(t_program *p);
void		sort_five(t_program *p);

//parser function
void		free_split(char **s);
int			is_valid_num(char *s);
long		ft_atol(char *s);
int			is_dup(t_stack *a, int value);
void		push_value_to_a(t_stack *a, int value);
void		free_split(char **s);
void		free_all(char **s, t_stack *a);

// helper function
void		innit_stack_b(t_stack *a, t_stack *b, int size);
void		error_exit(void);
char		**ft_split(char const *s, char c);

/* Swap operations */
void		sa(t_program *p);
void		sb(t_program *p);
void		ss(t_program *p);

int			check_flags(char **av, t_config *config);

/* Push operations */
void		pa(t_program *p);
void		pb(t_program *p);

/* Rotate operations */
void		ra(t_program *p);
void		rb(t_program *p);
void		rr(t_program *p);
/* Reverse rotate operations */
void		rra(t_program *p);
void		rrb(t_program *p);
void		rrr(t_program *p);

/*disorder*/
float		disorder(int *arr, int size);

// bench
void		bench(t_ops *ops, float d, t_config *config);

// adaptive 
void		select_algorithm(float d, t_program *p);

// void bubble_sort(t_stack *a, t_ops *ops);
void		bubble_sort(t_program *p);
void		bubble_sorting(t_program *p);
// bucket sort O(nVn)
void		bucket_sort(t_program *p);
void		bucket_sorting(t_program *p);

// radix sort
void		radix_ops(t_program *p, int n, int bit);
void		radix_lsd_sorting(t_program *p);
void		radix_lsd_sort(t_program *p);

#endif