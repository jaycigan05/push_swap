/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagan <jagan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 12:11:20 by jagan             #+#    #+#             */
/*   Updated: 2026/04/30 12:13:40 by jagan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_move_cost(t_stack *a, t_stack *b, t_node *node, int pos)
{
	int	insert_pos;
	int	cost_a;
	int	cost_b;

	insert_pos = get_insert_position(a, node->index);
	cost_a = get_rotation_cost(insert_pos, a->size);
	cost_b = get_rotation_cost(pos, b->size);
	return (get_total_cost(cost_a, cost_b));
}

static void	find_best_move(t_stack *a, t_stack *b, t_move *best)
{
	t_node	*cur;
	int		pos;
	int		best_cost;
	int		cost;

	cur = b->top;
	pos = 0;
	best_cost = INT_MAX;
	while (cur)
	{
		cost = get_move_cost(a, b, cur, pos);
		if (cost < best_cost)
		{
			best_cost = cost;
			best->index = cur->index;
			best->position = pos;
		}
		cur = cur->next;
		pos++;
	}
	best->cost_a = get_rotation_cost(
			get_insert_position(a, best->index), a->size);
	best->cost_b = get_rotation_cost(best->position, b->size);
}

void	move_best_node(t_stack *a, t_stack *b)
{
	t_move	best;

	find_best_move(a, b, &best);
	apply_rotations_and_push(a, b, best.cost_a, best.cost_b);
}
