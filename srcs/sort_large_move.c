/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagan <jagan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 16:00:00 by jagan             #+#    #+#             */
/*   Updated: 2026/04/30 11:47:20 by jagan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	g_best_index;
static int	g_best_position;
static int	g_best_cost_a;
static int	g_best_cost_b;

static void	apply_rotations_and_push(t_stack *a, t_stack *b,
	int cost_a, int cost_b)
{
	while (cost_a > 0 && cost_b > 0)
	{
		rr(a, b);
		cost_a--;
		cost_b--;
	}
	while (cost_a < 0 && cost_b < 0)
	{
		rrr(a, b);
		cost_a++;
		cost_b++;
	}
	while (cost_a > 0)
	{
		ra(a);
		cost_a--;
	}
	while (cost_a < 0)
	{
		rra(a);
		cost_a++;
	}
	while (cost_b > 0)
	{
		rb(b);
		cost_b--;
	}
	while (cost_b < 0)
	{
		rrb(b);
		cost_b++;
	}
	pa(a, b);
}

static int	get_move_cost(t_stack *a, t_stack *b, t_node *node, int position)
{
	int	insert_position;
	int	cost_a;
	int	cost_b;

	insert_position = get_insert_position(a, node->index);
	cost_a = get_rotation_cost(insert_position, a->size);
	cost_b = get_rotation_cost(position, b->size);
	return (get_total_cost(cost_a, cost_b));
}

static void	find_best_move(t_stack *a, t_stack *b)
{
	t_node	*current_b;
	int		current_position;
	int		best_cost;
	int		move_cost;

	current_b = b->top;
	current_position = 0;
	best_cost = INT_MAX;
	while (current_b)
	{
		move_cost = get_move_cost(a, b, current_b, current_position);
		if (move_cost < best_cost)
		{
			best_cost = move_cost;
			g_best_index = current_b->index;
			g_best_position = current_position;
		}
		current_b = current_b->next;
		current_position++;
	}
	g_best_cost_a = get_rotation_cost(get_insert_position(a, g_best_index),
			a->size);
	g_best_cost_b = get_rotation_cost(g_best_position, b->size);
}

void	rotate_a_to_min(t_stack *a)
{
	t_node	*current;
	int		position;
	int		min_position;
	int		min_index;

	current = a->top;
	position = 0;
	min_position = 0;
	min_index = INT_MAX;
	while (current)
	{
		if (current->index < min_index)
		{
			min_index = current->index;
			min_position = position;
		}
		current = current->next;
		position++;
	}
	if (min_position <= a->size / 2)
	{
		while (min_position-- > 0)
			ra(a);
	}
	else
	{
		while (min_position++ < a->size)
			rra(a);
	}
}

void	move_best_node(t_stack *a, t_stack *b)
{
	find_best_move(a, b);
	apply_rotations_and_push(a, b, g_best_cost_a, g_best_cost_b);
}
