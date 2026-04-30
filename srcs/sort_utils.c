/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagan <jagan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 14:00:00 by jagan             #+#    #+#             */
/*   Updated: 2026/04/30 11:45:34 by jagan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(t_stack *a)
{
	t_node	*cur;
	t_node	*cmp;
	int		index;

	cur = a->top;
	while (cur)
	{
		index = 0;
		cmp = a->top;
		while (cmp)
		{
			if (cmp->value < cur->value)
				index++;
			cmp = cmp->next;
		}
		cur->index = index;
		cur = cur->next;
	}
}

int	get_max_bits(t_stack *a)
{
	t_node	*cur;
	int		max;
	int		bits;

	max = 0;
	cur = a->top;
	while (cur)
	{
		if (cur->index > max)
			max = cur->index;
		cur = cur->next;
	}
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	push_min_to_b(t_stack *a, t_stack *b, int target)
{
	int	rotations;
	int	size;

	rotations = 0;
	size = a->size;
	while (target > 0 && rotations < size * 2)
	{
		if (peek_top(a)->index < 2)
		{
			pb(a, b);
			target--;
		}
		else
			ra(a);
		rotations++;
	}
}
