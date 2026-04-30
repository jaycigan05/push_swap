/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagan <jagan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 12:38:43 by jagan             #+#    #+#             */
/*   Updated: 2026/04/30 12:41:07 by jagan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_rr_rrr(t_stack *a, t_stack *b, int *ca, int *cb)
{
	while (*ca > 0 && *cb > 0)
	{
		rr(a, b);
		(*ca)--;
		(*cb)--;
	}
	while (*ca < 0 && *cb < 0)
	{
		rrr(a, b);
		(*ca)++;
		(*cb)++;
	}
}

static void	do_ra_rra(t_stack *a, int *ca)
{
	while (*ca > 0)
	{
		ra(a);
		(*ca)--;
	}
	while (*ca < 0)
	{
		rra(a);
		(*ca)++;
	}
}

static void	do_rb_rrb(t_stack *b, int *cb)
{
	while (*cb > 0)
	{
		rb(b);
		(*cb)--;
	}
	while (*cb < 0)
	{
		rrb(b);
		(*cb)++;
	}
}

void	apply_rotations_and_push(t_stack *a, t_stack *b,
	int ca, int cb)
{
	do_rr_rrr(a, b, &ca, &cb);
	do_ra_rra(a, &ca);
	do_rb_rrb(b, &cb);
	pa(a, b);
}

void	rotate_a_to_min(t_stack *a)
{
	t_node	*cur;
	int		pos;
	int		min_pos;
	int		min;

	cur = a->top;
	pos = 0;
	min_pos = 0;
	min = INT_MAX;
	while (cur)
	{
		if (cur->index < min)
		{
			min = cur->index;
			min_pos = pos;
		}
		cur = cur->next;
		pos++;
	}
	if (min_pos <= a->size / 2)
		while (min_pos-- > 0)
			ra(a);
	else
		while (min_pos++ < a->size)
			rra(a);
}
