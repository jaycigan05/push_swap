/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagan <jagan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 04:24:42 by jagan             #+#    #+#             */
/*   Updated: 2026/04/30 10:41:36 by jagan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_large(t_stack *a, t_stack *b)
{
	t_node	*cur;
	int		size;
	int		max_bits;
	int		bit;
	int		i;

	assign_index(a);
	size = a->size;
	max_bits = get_max_bits(a);
	bit = 0;
	while (bit < max_bits)
	{
		i = 0;
		while (i < size)
		{
			cur = peek_top(a);
			if (((cur->index >> bit) & 1) == 1)
				ra(a);
			else
				pb(a, b);
			i++;
		}
		while (b->size > 0)
			pa(a, b);
		bit++;
	}
}

void	sort_four(t_stack *a, t_stack *b)
{
	assign_index(a);
	while (peek_top(a)->index != 0)
		ra(a);
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_stack *a, t_stack *b)
{
	assign_index(a);
	push_min_to_b(a, b, 2);
	if (b->size == 2 && b->top->index < b->top->next->index)
		sb(b);
	sort_three(a);
	while (b->size > 0)
		pa(a, b);
}

void	sort_stacks(t_stack *a, t_stack *b)
{
	if (!a || a->size <= 1)
		return ;
	else if (a->size == 2)
		sort_two(a);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size == 4)
		sort_four(a, b);
	else if (a->size == 5)
		sort_five(a, b);
	else
		sort_large(a, b);
}